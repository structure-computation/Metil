#include "CompilationCppParser.h"
#include "Tokenize.h"
#include "System.h"

BEG_METIL_LEVEL1_NAMESPACE;

CompilationEnvironment::CompilationEnvironment( CompilationEnvironment *ch ) : child( ch ) {
    if ( child == 0 ) {
        // inc_paths
        String dir = directory_of( __FILE__ );
        add_inc_path( dir.beg_upto( dir.size() - 7 ) ); // Level1

        // default values
        CXX  = "g++";
        LD   = "g++";
        NVCC = "/usr/local/cuda/bin/nvcc";
        _comp_dir = absolute_filename( "compilations" ) + "/";

        device_emulation = 0;
        maxrregcount     = 0;
        nb_threads       = 8;

        load_env_var();
    } else {
        device_emulation = -1;
        maxrregcount     = -1;
        nb_threads       = -1;
    }
}

String CompilationEnvironment::find_src( const String &filename, const String &current_dir ) const {
    // absolute path ?
    if ( filename[ 0 ] == '/' or filename[ 0 ] == '\\' )
        return ( file_exists( filename ) ? filename : String() );

    // try with current_dir
    String trial = current_dir + filename;
    if ( file_exists( trial ) )
        return trial;

    // try with inc_paths
    for( int i = 0; i < inc_paths.size(); ++i ) {
        trial = inc_paths[ i ] + filename;
        if ( file_exists( trial ) )
            return trial;
    }

    // try with inc_paths of child
    if ( child )
        return child->find_src( filename, current_dir );

    // not found :(
    return String();
}

String CompilationEnvironment::comp_dir() const {
    if ( not _comp_dir )
        return child->comp_dir();
    mkdir( _comp_dir, false );
    return _comp_dir;
}

void CompilationEnvironment::add_inc_path( const String &path ) {
    String a = absolute_filename( path );
    if ( a.size() ) {
        if ( not a.ends_with( "/" ) )
            a += '/';
        inc_paths.push_back_unique( a );
    }
}

void CompilationEnvironment::add_lib_path( const String &path ) {
    if ( child )
        child->add_lib_path( path );
    else {
        String a = absolute_filename( path );
        if ( a.size() ) {
            if ( not a.ends_with( "/" ) )
                a += '/';
            lib_paths.push_back_unique( a );
        }
    }
}

void CompilationEnvironment::add_lib_name( const String &name ) {
    if ( child )
        child->add_lib_name( name );
    else
        lib_names.push_back_unique( name );
}

void CompilationEnvironment::add_CPPFLAG( const String &flag ) {
    if ( CPPFLAGS )
        CPPFLAGS << ' ';
    CPPFLAGS << flag;
}

void CompilationEnvironment::set_CXX( const String &path ) {
    CXX = path;
}

void CompilationEnvironment::set_device_emulation( bool flag ) {
    device_emulation = flag;
}

void CompilationEnvironment::set_maxrregcount( int nb_registers ) {
    maxrregcount = nb_registers;
}

void CompilationEnvironment::set_comp_dir( const String &path ) {
    _comp_dir = absolute_filename( path );
    mkdir( _comp_dir, false );
    if ( not _comp_dir.ends_with( '/' ) )
        _comp_dir += '/';
}

void CompilationEnvironment::set_nb_threads( int nb_threads_ ) {
    nb_threads = nb_threads_;
}

String CompilationEnvironment::get_NVCC() const {
    return NVCC ? NVCC : child->get_NVCC();
}

String CompilationEnvironment::get_CXX() const {
    return CXX ? CXX : child->get_CXX();
}

String CompilationEnvironment::get_LD() const {
    return LD ? LD : child->get_LD();
}

int CompilationEnvironment::get_nb_threads() const {
    return nb_threads > 0 ? nb_threads : child->get_nb_threads();
}

void CompilationEnvironment::save_env_var( bool update_LD_LIBRARY_PATH ) const {
    String METIL_INC_PATHS;
    for( int i = 0; i < inc_paths.size(); ++i )
        METIL_INC_PATHS << ( i ? ";" : "" ) << inc_paths[ i ];
    set_env( "METIL_INC_PATHS", METIL_INC_PATHS );

    String METIL_LIB_PATHS;
    for( int i = 0; i < lib_paths.size(); ++i )
        METIL_LIB_PATHS << ( i ? ";" : "" ) << lib_paths[ i ];
    set_env( "METIL_LIB_PATHS", METIL_LIB_PATHS );

    String METIL_LIB_NAMES;
    for( int i = 0; i < lib_names.size(); ++i )
        METIL_LIB_NAMES << ( i ? ";" : "" ) << lib_names[ i ];
    set_env( "METIL_LIB_NAMES", METIL_LIB_NAMES );

    String METIL_PARSED;
    for( int i = 0; i < parsed.size(); ++i )
        METIL_PARSED << ( i ? ";" : "" ) << parsed[ i ];
    set_env( "METIL_PARSED", METIL_PARSED );

    set_env( "METIL_COMP_DIR", _comp_dir );
    set_env( "METIL_CXX"     , CXX       );
    set_env( "METIL_LD"      , LD        );
    set_env( "METIL_NVCC"    , NVCC      );
    set_env( "METIL_CPPFLAGS", CPPFLAGS  );
    set_env( "METIL_LDFLAGS" , LDFLAGS   );

    if ( device_emulation )
        set_env( "METIL_DEV_EMU", "1" );
    if ( maxrregcount )
        set_env( "METIL_REG_CNT", String( maxrregcount ) );

    // LD_LIBRARY_PATH
    if ( update_LD_LIBRARY_PATH ) {
        const char *l = getenv( "LD_LIBRARY_PATH" );
        String LD_LIB = l ? l : "";
        for( int i = 0; i < lib_paths.size(); ++i ) {
            if ( LD_LIB.size() )
                LD_LIB += ";";
            LD_LIB += lib_paths[ i ];
        }
        set_env( "LD_LIBRARY_PATH", LD_LIB );
    }

}

void CompilationEnvironment::load_env_var() {
    if ( String str = get_env( "METIL_INC_PATHS" ) ) {
        BasicVec<String> lst = tokenize( str, ';' );
        for( int i = 0; i < lst.size(); ++i )
            add_inc_path( lst[ i ] );
    }

    if ( String str = get_env( "METIL_LIB_PATHS" ) ) {
        BasicVec<String> lst = tokenize( str, ';' );
        for( int i = 0; i < lst.size(); ++i )
            add_lib_path( lst[ i ] );
    }

    if ( String str = get_env( "METIL_LIB_NAMES" ) ) {
        BasicVec<String> lst = tokenize( str, ';' );
        for( int i = 0; i < lst.size(); ++i )
            add_lib_name( lst[ i ] );
    }

    if ( String str = get_env( "METIL_PARSED" ) ) {
        BasicVec<String> lst = tokenize( str, ';' );
        for( int i = 0; i < lst.size(); ++i )
            parsed << lst[ i ];
    }

    if ( String str = get_env( "METIL_COMP_DIR" ) ) _comp_dir = str;
    if ( String str = get_env( "METIL_CXX"      ) ) CXX       = str;
    if ( String str = get_env( "METIL_LD"       ) ) LD        = str;
    if ( String str = get_env( "METIL_NVCC"     ) ) NVCC      = str;
    if ( String str = get_env( "METIL_CPPFLAGS" ) ) CPPFLAGS  = str;
    if ( String str = get_env( "METIL_LDFLAGS"  ) ) LDFLAGS   = str;
    if ( String str = get_env( "METIL_DEV_EMU"  ) ) device_emulation = Val( str );
    if ( String str = get_env( "METIL_REG_CNT"  ) ) maxrregcount = Val( str );
}

String CompilationEnvironment::obj_suffix( bool dyn ) {
    return dyn ? ".os" : ".o";
}

String CompilationEnvironment::lib_suffix( bool dyn ) {
    return dyn ? ".so" : ".a";
}

String CompilationEnvironment::exe_suffix() {
    return String();
}

String CompilationEnvironment::obj_for( const String &cpp, bool dyn ) {
    return comp_dir() + filename_without_dir_of( cpp ) + obj_suffix( dyn );
}

String CompilationEnvironment::lib_for( const String &cpp, bool dyn ) {
    return comp_dir() + filename_without_dir_of( cpp ) + lib_suffix( dyn );
}

String CompilationEnvironment::cpp_for( const String &cpp ) {
    return comp_dir() + filename_without_dir_of( cpp ) + ".cpp";
}

String CompilationEnvironment::mex_for( const String &cpp ) {
    const char *suffix = ".mexglx";
    if ( cpp.ends_with( ".cpp" ) ) return cpp.rstrip( 4 ) + suffix;
    if ( cpp.ends_with( ".cxx" ) ) return cpp.rstrip( 4 ) + suffix;
    if ( cpp.ends_with( ".cc"  ) ) return cpp.rstrip( 3 ) + suffix;
    return cpp + suffix;
}

String CompilationEnvironment::exe_for( const String &cpp ) {
    return comp_dir() + filename_without_dir_of( cpp ) + exe_suffix();
}

void CompilationEnvironment::extra_lnk_cmd( String &cmd, bool lib, bool dyn ) const {
    if ( LDFLAGS )
        cmd << ' ' << LDFLAGS;
    for( int i = 0; i < lib_paths.size(); ++i )
        cmd << " -L" << lib_paths[ i ];
    for( int i = 0; i < lib_names.size(); ++i )
        cmd << " -l" << lib_names[ i ];
    if ( child )
        child->extra_lnk_cmd( cmd, lib, dyn );
}

void CompilationEnvironment::extra_obj_cmd( String &cmd, bool dyn, bool cu ) const {
    if ( cu ) {
        if ( GPUFLAGS )
            cmd << ' ' << GPUFLAGS;
    } else {
        if ( CPPFLAGS )
            cmd << ' ' << CPPFLAGS;
    }
    for( int i = 0; i < inc_paths.size(); ++i )
        cmd << " -I" << inc_paths[ i ];
    if ( child )
        child->extra_obj_cmd( cmd, dyn, cu );
}

String CompilationEnvironment::lnk_cmd( const String &exe, const BasicVec<String> &obj, bool lib, bool dyn ) const {
    String cmd = get_LD();
    // basic flags
    if ( lib )
        cmd << ( dyn ? " -shared" : " -static" );
    // -L... -l...
    extra_lnk_cmd( cmd, lib, dyn );
    // input / output
    cmd << " -o " << exe;
    for( int i = 0; i < obj.size(); ++i )
        cmd << ' ' << obj[ i ];
    return cmd;
}

String CompilationEnvironment::obj_cmd( const String &obj, const String &cpp, bool dyn ) const {
    String cmd;
    bool cu = cpp.ends_with( ".cu" );
    if ( cu ) {
        cmd << get_NVCC();
        // basic flags
        if ( dyn )
            cmd << " -Xcompiler -fPIC";
        if ( maxrregcount > 0 )
            cmd << " --maxrregcount=" << maxrregcount;
        if ( device_emulation > 0 )
            cmd << " --device-emulation -G -g";
        else
            cmd << " -w -g -O3 --gpu-architecture=compute_13";
    } else {
        cmd << get_CXX();
        // basic flags
        if ( dyn )
            cmd << " -fpic";
    }
    // -L... -l...
    extra_obj_cmd( cmd, dyn, cu );
    // input / output
    cmd << " -c -o " << obj << ' ' << cpp;
    return cmd;
}

CompilationEnvironment *CompilationEnvironment::deepest_child() {
    if ( child )
        return child->deepest_child();
    return this;
}

Ptr<CompilationTree> CompilationEnvironment::make_cpp_compilation_tree( const String &cpp ) {
    Ptr<CompilationTree> &res = deepest_child()->cor_files[ cpp ];
    if ( not res )
        res = NEW( CompilationTree, cpp );
    return res;
}


Ptr<CompilationTree> CompilationEnvironment::make_obj_compilation_tree( const String &obj, Ptr<CompilationTree> cpp, bool dyn ) {
    Ptr<CompilationTree> &res = deepest_child()->cor_files[ obj ];
    if ( not res ) {
        res = NEW( CompilationTree, obj );
        res->add_child( cpp );
        res->cmd = obj_cmd( obj, cpp->dst, dyn );
    }
    return res;
}

Ptr<CompilationTree> CompilationEnvironment::make_lnk_compilation_tree( const String &exe, const BasicVec<Ptr<CompilationTree> > &obj, bool lib, bool dyn ) {
    Ptr<CompilationTree> &res = deepest_child()->cor_files[ exe ];
    if ( not res ) {
        res = NEW( CompilationTree, exe );
        for( int i = 0; i < obj.size(); ++i )
            res->add_child( obj[ i ] );
        BasicVec<String> obj_str;
        for( int i = 0; i < obj.size(); ++i )
            obj_str << obj[ i ]->dst;
        res->cmd = lnk_cmd( exe, obj_str, lib, dyn );
    }
    return res;
}

void CompilationEnvironment::parse_cpp( BasicVec<Ptr<CompilationTree> > &obj, const String &cpp_, bool dyn ) {
    String cpp = absolute_filename( cpp_ );

    // already parsed ?
    if ( parsed.contains( cpp ) )
        return;
    parsed << cpp;

    // parse
    CompilationCppParser cpp_parser( *this, cpp );

    // global flags
    for( int i = 0; i < cpp_parser.lib_names.size(); ++i )
        add_lib_name( cpp_parser.lib_names[ i ] );
    for( int i = 0; i < cpp_parser.lib_paths.size(); ++i )
        add_lib_path( cpp_parser.lib_paths[ i ] );

    // local flags
    CompilationEnvironment loc_ce( this );
    for( int i = 0; i < cpp_parser.inc_paths.size(); ++i )
        loc_ce.inc_paths.push_back_unique( cpp_parser.inc_paths[ i ] );

    // command
    Ptr<CompilationTree> res = loc_ce.make_obj_compilation_tree( obj_for( cpp, dyn ), make_cpp_compilation_tree( cpp ), dyn );
    for( int i = 0; i < cpp_parser.inc_files.size(); ++i )
        res->add_child( loc_ce.make_cpp_compilation_tree( cpp_parser.inc_files[ i ] ) );
    obj.push_back_unique( res );

    // .h -> .cpp or .cu ?
    for( int i = 0; i < cpp_parser.inc_files.size(); ++i ) {
        String h = cpp_parser.inc_files[ i ];
        if ( h.ends_with( ".h" ) ) {
            String base = h.beg_upto( h.size() - 2 );
            if ( file_exists( base + ".cpp" ) )
                parse_cpp( obj, base + ".cpp", dyn );
            if ( file_exists( base + ".cu" ) )
                parse_cpp( obj, base + ".cu", dyn );
        }
    }

    // src_file
    for( int i = 0; i < cpp_parser.src_files.size(); ++i ) {
        String ext_cpp = cpp_parser.src_files[ i ];
        parse_cpp( obj, ext_cpp, dyn );
    }
}

struct Lib {
    BasicVec<Ptr<CompilationTree> > obj;
};

int CompilationEnvironment::make_app( const String &app, const String &cpp, bool lib, bool dyn ) {
    BasicVec<Ptr<CompilationTree> > obj;
    parse_cpp( obj, cpp, dyn );

    // sort by directory
    String base_dir = directory_of( cpp );
    std::map<String,Lib> map_lib;
    for( int i = 0; i < obj.size(); ++i ) {
        String dir = directory_of( obj[ i ]->children[ 0 ]->dst );
        if ( dir == base_dir )
            continue;
        map_lib[ dir ].obj << obj[ i ];
        obj.remove( i-- );
    }

    // make dylibs
    int cpt = 0;
    for( std::map<String,Lib>::iterator iter = map_lib.begin(); iter != map_lib.end(); ++iter ) {
        String name; name << app << "_" << cpt++;
        obj << make_lnk_compilation_tree( lib_for( name, true ), iter->second.obj, true, true );
    }

    //
    Ptr<CompilationTree> res = make_lnk_compilation_tree( app, obj, lib, dyn );
    return res->exec( get_nb_threads(), &cout );
}

int CompilationEnvironment::make_lib( const String &lib, const String &cpp, bool dyn ) {
    return make_app( lib, cpp, true, dyn );
}

int CompilationEnvironment::make_exe( const String &exe, const String &cpp ) {
    return make_app( exe, cpp, false, true );
}

CompilationEnvironment &CompilationEnvironment::get_main_compilation_environment() {
    static CompilationEnvironment res;
    return res;
}

END_METIL_LEVEL1_NAMESPACE;