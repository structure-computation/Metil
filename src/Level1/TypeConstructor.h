#ifndef TYPECONSTRUCTOR_H
#define TYPECONSTRUCTOR_H

#include "MethodWriter.h"
#include "MethodCond.h"
#include "MachineId.h"
#include "TypeSet.h"

BEG_METIL_LEVEL1_NAMESPACE;

class TypeConstructor {
public:
    TypeConstructor();
    virtual ~TypeConstructor();
    virtual void init( Type *type );

    // conditions ( used by "has__..." in metil_def_... or metil_gen_... )
    #define DECL_COND( N ) \
        struct C0_has_##N : public MethodCond { virtual bool valid( Type *type_0, Type *, Type * ) const { return type_0->constructor->N(); } }; \
        struct C1_has_##N : public MethodCond { virtual bool valid( Type *, Type *type_1, Type * ) const { return type_1->constructor->N(); } }; \
        struct C2_has_##N : public MethodCond { virtual bool valid( Type *, Type *, Type *type_2 ) const { return type_2->constructor->N(); } }; \
        virtual bool N() const

    DECL_COND( Owcp_type );
    DECL_COND( Owcp_size_0 );
    DECL_COND( Owcp_size_1 );
    DECL_COND( Owcp_size_2 );
    DECL_COND( Owcp_size_3 );
    DECL_COND( is_a_POD );
    DECL_COND( tensor_order_0 );
    DECL_COND( tensor_order_1 );
    DECL_COND( is_void );

    #define DECL_MET( T, N ) DECL_COND( has_writer_for_##N );
    #include "DeclMethodsUnary.h"
    #undef DECL_MET

    // writers for unary methods
    #define DECL_MET( T, N ) virtual void write_##N( MethodWriter &mw, const Mos *a, const String &ret_ins = "return " ) const;
    #include "DeclMethodsUnary.h"
    #undef DECL_MET

    // write_str (used with self_append and String)
    DECL_COND( has_writer_for_write_str ) { return 0; }
    virtual void write_write_str( MethodWriter &mw, const Mos *a, const String &ret_ins = "return " ) const;

    // for inherited classes
    #define DECL_WRITER( N ) \
        virtual bool has_writer_for_##N() const { return 1; } \
        virtual void write_##N( MethodWriter &mw, const Mos *a, const String &ret_ins ) const


    virtual int Owcp_size() const;
    virtual void default_mw( MethodWriter &mw ) const;
    virtual int tensor_order() const;
    virtual int static_size_in_bits() const;
    virtual int needed_alignement_in_bits() const;
    virtual int needed_alignement_in_bits_if_in_vec( const MachineId *mid ) const;
    virtual String cpp_type() const;

    int static_size_in_bytes() const;
    int needed_alignement_in_bytes() const;
    int needed_alignement_in_bytes_if_in_vec( const MachineId *mid ) const;

    DECL_COND( has_writer_for_convert_to_ST ) { return 0; }
    virtual void write_convert_to_ST( MethodWriter &mw, const Mos *a, const String &ret_ins ) const;

    virtual void write_select_op( MethodWriter &mw, const Mos *a, TypeConstructor *index_type, const String &op ) const;

    TypeSetAncestor *dyn_array_type ( int dim, const String &name, MachineId *mid, bool want_CptUse = false );
    TypeSetAncestor *sta_array_type ( int dim, ST *size, const String &name, MachineId *mid );
    TypeSetAncestor *static_vec_type( ST size, const String &name, MachineId *mid );

    bool have_been_initialized;
    Type *bas_type;
    Type *ref_type;
    Type *cst_type;

    #undef DECL_COND

protected:
    BasicVec<TypeSetAncestor *> _dyn_array_type_set; ///< for matrices, vectors, ...
    BasicVec<BasicVec<TypeSetAncestor *> > _sta_array_type_set; ///< for matrices, vectors, ...
};

#define DEFI_TYPE( B, N ) \
    static TypeConstructor_##B inst_type_##N; \
    Type metil_type_bas_##N( &inst_type_##N, #N, &metil_type_bas_##N, &metil_type_ref_##N, &metil_type_cst_##N, Type::Bas ); \
    Type metil_type_ref_##N( &inst_type_##N, #N, &metil_type_bas_##N, &metil_type_ref_##N, &metil_type_cst_##N, Type::Ref ); \
    Type metil_type_cst_##N( &inst_type_##N, #N, &metil_type_bas_##N, &metil_type_ref_##N, &metil_type_cst_##N, Type::Cst )

END_METIL_LEVEL1_NAMESPACE;

#endif // TYPECONSTRUCTOR_H