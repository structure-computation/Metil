#ifndef TYPECONSTRUCTOR_VOIDSTRING_H
#define TYPECONSTRUCTOR_VOIDSTRING_H

#include "TypeConstructor_String.h"

BEG_METIL_LEVEL1_NAMESPACE;

/**  */
class TypeConstructor_VoidString : public TypeConstructor_String {
public:
    virtual int static_size_in_bits() const;
};

END_METIL_LEVEL1_NAMESPACE;

#endif // TYPECONSTRUCTOR_VOIDSTRING_H
