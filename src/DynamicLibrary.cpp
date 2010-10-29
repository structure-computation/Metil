#include "DynamicLibrary.h"
#include "String.h"

#ifndef WIN32
    #include <dlfcn.h>
#else
    #include <windows.h>
#endif

#ifdef METIL_COMP_DIRECTIVE
#pragma lib_name dl
#endif

BEG_METIL_NAMESPACE;

DynamicLibrary::DynamicLibrary() {
    data = 0;
}

bool DynamicLibrary::open( String name ) {
    #ifdef WIN32
    data = LoadLibrary( (const WCHAR *)lib );
    #else
    data = dlopen( name.c_str(), RTLD_LAZY );
    #endif
    return data;
}

DynamicLibrary::~DynamicLibrary() {
    if ( data )
        dlclose( data );
}

void *DynamicLibrary::get_sym( String name ) {
    return data ? dlsym( data, name.c_str() ) : 0;
}

DynamicLibrary::operator bool() const {
    return data;
}

String DynamicLibrary::error() const {
    return dlerror();
}

END_METIL_NAMESPACE;