/*
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/
#include <Level1/CompilationEnvironment.h>
#include <System.h>

using namespace Metil;

void usage( const char *pn, const char *msg = NULL ) {
    if ( msg )
        cerrn << msg;
    cerrn << pn << " [options] cpp_file";
    cerrn << "  -h or --help : usage";
    cerrn << "  -o file : name of the output file";
    cerrn << "  -jn : launch compilation using n threads";
    cerrn << "  -mex : create a Matlab mexglx file";
    cerrn << "  -dylib : create a dynamic library";
    cerrn << "  -ne : do not launch the executable";
    cerrn << "  -nc : do not compile (launch the executable if -ne is not present)";
    cerrn << "  -Iincludedir : append an include dir to environnement";
    cerrn << "  -DMACRO : #define MACRO";
    cerrn << "  -DMACRO=val : #define MACRO val";
    cerrn << "  --comp-dir dir : specify path of directory used to store tmp files (.o, ...)";
    cerrn << "  --exec-using prg : execute using prg. Example : --exec-using time to use time";
    cerrn << "  --valgrind : execute using valgrind";
    cerrn << "  --gdb : execute using gbb (user has to write run in the gdb prompt...)";
    cerrn << "  --device-emulation : device emulation for cuda";
    cerrn << "  --maxrregcount n : device emulation for cuda";
    cerrn << "possible pragma in .h/.cpp/.cu files:";
    cerrn << "  src_file additionnal cpp / cu files";
    cerrn << "  inc_path additionnal include path";
    cerrn << "  lnk_flag additionnal flags explicitly passed to the linker";
    cerrn << "  gpu_flag additionnal flags explicitly passed to nvcc";
    cerrn << "  lib_path additionnal library (.so/.a) path, like e.g. /usr/local/lib";
    cerrn << "  lib_name additionnal library name (.so/.a), like e.g. pthread";
}


bool is_a_CPPFLAG( const String &arg ) {
    return
        arg.begins_by( "-O" ) or
        arg.begins_by( "-g" ) or
        arg.begins_by( "-march") or
        arg.begins_by( "-f" ) or
        arg.begins_by( "-W" ) or
        arg.begins_by( "-D" );
}


int main( int argc, char **argv ) {
    Level1::CompilationEnvironment &ce = Level1::CompilationEnvironment::get_main_compilation_environment();

    String cpp_file, out_file, exec_using, comp_dir;
    BasicVec<String> exec_args;
    bool execution   = true;
    bool compilation = true;
    bool want_mex    = false;
    bool want_lib    = false;
    bool want_dyn    = true;

    //
    for( int i = 1; i < argc; ++i ) {
        String arg = argv[ i ];
        if ( arg == "-h" or arg == "--help" ) {
            usage( argv[ 0 ] );
            return 0;
        } else if ( arg == "--valgrind" ) {
            exec_using = "valgrind";
        } else if ( arg == "--gdb" ) {
            exec_using = "gdb --args";
        } else if ( arg == "--exec-using" ) {
            if ( ++i >= argc ) {
                usage( argv[ 0 ], "--exec-using must be followed by a program name" );
                return 4;
            }
            exec_using = argv[ i ];
        } else if ( arg == "--cxx" ) {
            if ( ++i >= argc ) {
                usage( argv[ 0 ], "--cxx must be followed by the name of the cxx compiler" );
                return 5;
            }
            ce.set_CXX( argv[ i ] );
        } else if ( arg == "--comp-dir" ) {
            if ( ++i >= argc ) {
                usage( argv[ 0 ], "--comp-dir must be followed by a path" );
                return 6;
            }
            comp_dir = argv[ i ];
        } else if ( is_a_CPPFLAG( arg ) ) {
            ce.add_CPPFLAG( arg );
        } else if ( arg == "--device-emulation" ) {
            ce.set_device_emulation( 1 );
        } else if ( arg == "--maxrregcount" ) {
            ce.set_maxrregcount( atoi( argv[ ++i ] ) );
        } else if ( arg == "-j" ) {
            ce.set_nb_threads( atoi( argv[ i ] + 2 ) );
        } else if ( arg == "-mex" ) {
            want_mex  = true;
            want_lib  = true;
            want_dyn  = true;
            execution = false;
        } else if ( arg == "-dylib" ) {
            want_lib  = true;
            want_dyn  = true;
            execution  = false;
        } else if ( arg == "-ne" ) {
            execution = false;
        } else if ( arg == "-nc" ) {
            compilation = false;
        } else if ( arg[0] == '-' and arg[1]== 'I' ) {
            ce.add_inc_path( arg.end_from( 2 ) );
        } else if ( arg[0] == '-' and arg[1]== 'o' ) {
            if ( i + 1 >= argc ) {
                usage( argv[ 0 ], "-o must be followed by something (the output file)." );
                return 7;
            }
            out_file = argv[ ++i ];
        } else { // -> program name (assuming a .cpp file)
            if ( not comp_dir )
                if ( String dir = directory_of( arg ) )
                    comp_dir = dir + "/compilations";
            cpp_file = arg;
            for( ++i; i < argc; ++i )
                exec_args << argv[ i ];
        }
    }

    if ( comp_dir )
        ce.set_comp_dir( comp_dir );

    // filenames
    if ( not cpp_file ) {
        usage( argv[ 0 ], "you have to specify something to compile." );
        return 8;
    }

    if ( not out_file ) {
        if ( want_mex )
            out_file = ce.mex_for( cpp_file );
        else if ( want_lib )
            out_file = ce.lib_for( cpp_file, want_dyn );
        else
            out_file = ce.exe_for( cpp_file );
    }

    // compilation
    if ( compilation )
        if ( int res_make = ce.make_app( out_file, cpp_file, want_lib, want_dyn ) )
            return res_make;

    // execute
    if ( execution ) {
        // env var (including LD_LIBRARY_PATH)
        ce.save_env_var();

        // exec
        out_file = absolute_filename( out_file );
        String cmd = out_file;
        if ( exec_using.size() )
            cmd = exec_using + ' ' + out_file;
        for(int i = 0; i < exec_args.size(); ++i )
            cmd << ' ' << exec_args[ i ];
        return exec_cmd( cmd );
    }

    return 0;
}
