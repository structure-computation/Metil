#ifndef TYPECONSTRUCTOR_SYMBOLICEXPRESSION_H
#define TYPECONSTRUCTOR_SYMBOLICEXPRESSION_H

#include "TypeConstructor.h"

BEG_METIL_LEVEL1_NAMESPACE;

class TypeConstructor_SymbolicExpression : public TypeConstructor {
public:
    virtual void default_mw( MethodWriter &mw ) const;
};

END_METIL_LEVEL1_NAMESPACE;

#endif // TYPECONSTRUCTOR_SYMBOLICEXPRESSION_H
