#ifndef TYPECONSTRUCTOR_OP_H
#define TYPECONSTRUCTOR_OP_H

#include "TypeConstructor_SymbolicExpression.h"

BEG_METIL_LEVEL1_NAMESPACE;

class TypeConstructor_Op : public TypeConstructor_SymbolicExpression {
public:
    DECL_WRITER( write_str );

    virtual void default_mw( MethodWriter &mw ) const;
    virtual void init( Type *type );
    int nb_children;
    String name;
};

END_METIL_LEVEL1_NAMESPACE;

#endif // TYPECONSTRUCTOR_OP_H
