#include "TypeConstructor_ConstCharPtrWithSize.h"
#include "TypeConstructor_FileWithoutClose.h"
#include "OwcpStringData.h"
#include "String.h"

#include <cstdio>
#include <cstring>

BEG_METIL_LEVEL1_NAMESPACE;

// flush
void metil_def_flush__when__a__isa__FileWithoutClose__pert__1( MO &a ) { fflush( reinterpret_cast<FILE *>( a.data ) ); }

// write
void metil_def_write__when__a__isa__FileWithoutClose__pert__1( MO &a, const void *ptr, ST len ) {
    if ( a.data )
        std::fwrite( ptr, 1, len, reinterpret_cast<FILE *>( a.data ) );
}

// convert_to_Bool
bool metil_def_convert_to_Bool__when__a__isa__FileWithoutClose__pert__1( MO a ) {
    return a.data and not feof( reinterpret_cast<FILE *>( a.data ) );
}

// const char *
void metil_def_self_append__when__a__isa__FileWithoutClose__and__b__isa__ConstCharPtr__pert__1( MO &a, MO b ) {
    const char *ptr = reinterpret_cast<const char *>( b.data );
    if ( ptr )
        std::fwrite( ptr, 1, std::strlen( ptr ), reinterpret_cast<FILE *>( a.data ) );
}

// OwcpString
void metil_def_self_append__when__a__isa__FileWithoutClose__and__b__isa__OwcpString__pert__1( MO &a, MO b ) {
    Level1::OwcpStringData *o = reinterpret_cast<Level1::OwcpStringData *>( b.data );
    std::fwrite( o->ptr(), 1, o->size(), reinterpret_cast<FILE *>( a.data ) );
}

// const char * + size
void metil_def_self_append__when__b__isa__ConstCharPtrWithSize__and__a__isa__FileWithoutClose__pert__1( MO &a, MO b ) {
    const TypeConstructor_ConstCharPtrWithSize::Data *o = reinterpret_cast<const TypeConstructor_ConstCharPtrWithSize::Data *>( b.data );
    std::fwrite( o->data, 1, o->size, reinterpret_cast<FILE *>( a.data ) );
}

// ptr_z
const void *metil_def_ptr_z__when__a__isa__FileWithoutClose__pert__1( MO &a ) {
    FILE *f = reinterpret_cast<FILE *>( a.data );
    if ( not f )
        return "";
    ST old = ftell( f );
    fseek( f,   0, SEEK_END );
    ST end = ftell( f );
    fseek( f, old, SEEK_SET );

    NewString res( end - old );
    fread( res.ptr(), 1, end - old, f );
    static_cast<String &>( a ) = res;
    return res.ptr();
}

END_METIL_LEVEL1_NAMESPACE;
