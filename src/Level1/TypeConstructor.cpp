#include "TypeConstructor_Array.h"
#include "Ad.h"

BEG_METIL_LEVEL1_NAMESPACE;

// default behavior
void             metil_def_self_append__pert__0( MO &a, MO b ) { Ad c = a; a = CM_2( append, a, b ); }
void             metil_def_reassign__pert__0( MO &a, MO b ) { Ad c = a; a = CM_1( copy, b ); }
void             metil_def_add_parent__pert__0( MO &a, struct OwcpChild *b ) {}
void             metil_def_rem_parent__pert__0( MO &a, struct OwcpChild *b ) {}
bool             metil_def_cur_op_id__pert__0( MO a ) { return false; }
const MachineId *metil_def_machine_id__pert__0( MO a ) { return MachineId::cur(); }

// void objects
MO metil_def_copy__when__a__has__is_void__pert__1( MO a ) { return a.type; }
void metil_gen_copy__when__a__has__is_void( MethodWriter &mw, const Mos *a, const String &ret ) { mw.n << ret << " " << a->type << ";"; }

// static gen...( MethodWriter & ) { constructor->write_... }
#define DECL_MET( T, N ) void metil_gen_##N##__when__a__has__has_writer_for_##N##__pert__1( MethodWriter &cw, const Mos *a, const String &ret ) { cw.get_type( 0 )->constructor->write_##N( cw, a, ret ); }
#include "DeclMethodsUnary.h"
#undef DECL_MET

void metil_gen_self_append__when__a__isa__String__and__b__has__has_writer_for_write_str__pert__1( MethodWriter &cw, const Mos *a, const String &ret ) {
    cw.add_include( "String.h" );
    if ( cw.get_os_defined() == false ) {
        cw.set_os_defined( true );
        cw.n << "String &os = static_cast<String &>( " << a[ 0 ] << " );";
    }
    cw.get_type( 1 )->constructor->write_write_str( cw, a + 1 );
}

// POD
void metil_gen_del__when__a__has__is_a_POD__pert__1( MethodWriter &mw, const Mos *a, const String &ret ) {
    int size = mw.get_type( 0 )->constructor->static_size_in_bytes();
    if ( size > 0 )
        mw.n << "FREE( " << a->data << ", Number<" << size << ">() );";
}

void metil_gen_copy__when__a__has__is_a_POD__pert__1( MethodWriter &mw, const Mos *a, const String &ret ) {
    int size = mw.get_type( 0 )->constructor->static_size_in_bytes();
    if ( size > 0 ) {
        mw.add_include( "Level1/StringHelp.h" );
        String s; s << "Number<" << size << ">()";
        mw.n << "void *res = MALLOC( " << s << " );";
        mw.n << "memcpy( res, " << a->data << ", " << s << " );";
        mw.n << ret << "MO( res, &metil_type_bas_" << mw.get_type( 0 )->name << " );";
    } else {
        mw.n << ret << "MO( &metil_type_cst_" << mw.get_type( 0 )->name << " );";
    }
}



TypeConstructor::TypeConstructor() {
    have_been_initialized = false;
}

TypeConstructor::~TypeConstructor() {
    for( int d = 0; d < _dyn_array_type_set.size(); ++d )
        if ( _dyn_array_type_set[ d ] )
            DEL( _dyn_array_type_set[ d ] );
    for( int d = 0; d < _sta_array_type_set.size(); ++d )
        for( int n = 0; n < _sta_array_type_set[ d ].size(); ++n )
            if ( _sta_array_type_set[ d ][ n ] )
                DEL( _sta_array_type_set[ d ][ n ] );
}

void TypeConstructor::init( Type *type ) {
    bas_type = type->bas_type;
    ref_type = type->ref_type;
    cst_type = type->cst_type;
}

bool TypeConstructor::Owcp_type() const { return Owcp_size() >= 0; }
bool TypeConstructor::Owcp_size_0() const { return Owcp_size() == 0; }
bool TypeConstructor::Owcp_size_1() const { return Owcp_size() == 1; }
bool TypeConstructor::Owcp_size_2() const { return Owcp_size() == 2; }
bool TypeConstructor::Owcp_size_3() const { return Owcp_size() == 3; }

bool TypeConstructor::is_a_POD() const { return 0; }
bool TypeConstructor::tensor_order_0() const { return tensor_order() == 0; }
bool TypeConstructor::tensor_order_1() const { return tensor_order() == 1; }
bool TypeConstructor::is_void() const { return static_size_in_bits() == 0; }

void TypeConstructor::default_mw( MethodWriter &mw ) const {}
int TypeConstructor::Owcp_size() const { return -1; }
int TypeConstructor::static_size_in_bits() const { return -1; }
int TypeConstructor::needed_alignement_in_bits() const { return 8; }
int TypeConstructor::needed_alignement_in_bits_if_in_vec( const MachineId *mid ) const { return 1; }
int TypeConstructor::tensor_order() const { return 0; }

int TypeConstructor::static_size_in_bytes() const { return ( static_size_in_bits() + 7 ) / 8; }
int TypeConstructor::needed_alignement_in_bytes() const { return ( needed_alignement_in_bits() + 7 ) / 8; }
int TypeConstructor::needed_alignement_in_bytes_if_in_vec( const MachineId *mid ) const { return ( needed_alignement_in_bits_if_in_vec( mid ) + 7 ) / 8; }

void TypeConstructor::write_convert_to_ST( MethodWriter &mw, const Mos *a, const String &ret_ins ) const {
    mw.n << "if ( sizeof( ST ) == 8 ) {";
    write_convert_to_SI64( mw, a, ret_ins );
    mw.n << "} else {";
    write_convert_to_SI32( mw, a, ret_ins );
    mw.n << "}";
}

// virtual has_writer_for_...
#define DECL_MET( T, N ) bool TypeConstructor::has_writer_for_##N() const { return 0; }
#include "DeclMethodsUnary.h"
#undef DECL_MET

// virtual write_...
#define DECL_MET( T, N ) void TypeConstructor::write_##N( MethodWriter &, const Mos *, const String & ) const { ERROR( "What do we do here (%s, %s) ?", bas_type->name, #N ); }
#include "DeclMethodsUnary.h"
#undef DECL_MET

void TypeConstructor::write_write_str( MethodWriter &, const Mos *, const String & ) const { ERROR( "What do we do here (%s) ?", bas_type->name ); }

void TypeConstructor::write_select_op( MethodWriter &mw, const Mos *a, TypeConstructor *index_type, const String &op ) const {
    ERROR( "write_select_op is not defined for %s", bas_type->name );
}

String TypeConstructor::cpp_type() const {
    return String();
}

TypeSetAncestor *TypeConstructor::dyn_array_type( int dim, const String &name, MachineId *mid, bool want_CptUse ) {
    bool want_ExtPtr    = mid != MachineId::cur();
    bool want_MachineId = want_ExtPtr;
    bool want_Gpu       = mid->is_a_gpu();
    int off = 16 * dim + 8 * want_CptUse + 4 * want_ExtPtr + 2 * want_MachineId + want_Gpu;
    if ( _dyn_array_type_set.size() <= off )
        _dyn_array_type_set.resize( off + 1, (TypeSetAncestor *)0 );

    if ( not _dyn_array_type_set[ off ] ) {
        String tn;
        tn << "Array_" << name.size() << name << "_" << dim;
        for( int d = 0; d < dim; ++d )
            tn << "_m_m";
        if ( want_CptUse    ) tn << "_CptUse";
        if ( want_ExtPtr    ) tn << "_ExtPtr";
        if ( want_Gpu       ) tn << "_Gpu";
        if ( want_MachineId ) tn << "_MachineId";
        _dyn_array_type_set[ off ] = NEW( TypeSet<TypeConstructor_Array>, tn );
    }
    return _dyn_array_type_set[ off ];
}

TypeSetAncestor *TypeConstructor::static_vec_type( ST size, const String &name, MachineId *mid ) {
    ASSERT( mid == MachineId::cur(), "TODO" );
    if ( _sta_array_type_set.size() <= 1 )
        _sta_array_type_set.resize( 2 );
    if ( _sta_array_type_set[ 1 ].size() <= size )
        _sta_array_type_set[ 1 ].resize( size + 1, (TypeSetAncestor *)0 );
    if ( not _sta_array_type_set[ 1 ][ size ] ) {
        String tn;
        tn << "Array_" << name.size() << name << "_" << 1 << "_" << size << "_" << size;
        _sta_array_type_set[ 1 ][ size ] = NEW( TypeSet<TypeConstructor_Array>, tn );
    }
    return _sta_array_type_set[ 1 ][ size ];
}

TypeSetAncestor *TypeConstructor::sta_array_type( int dim, ST *size, const String &name, MachineId *mid ) {
    ASSERT( mid == MachineId::cur(), "TODO" );
    if ( dim == 1 )
        return static_vec_type( size[ 0 ], name, mid );
    if ( _sta_array_type_set.size() <= dim )
        _sta_array_type_set.resize( dim + 1 );
    TODO;
    return 0;
}

END_METIL_LEVEL1_NAMESPACE;