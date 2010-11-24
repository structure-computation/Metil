// file generated by MethodGenerator.h.py
#ifndef METHODGENERATOR_H
#define METHODGENERATOR_H

#include "MethodFinder.h"

BEG_METIL_LEVEL1_NAMESPACE;

template<class T,class N>
struct MethodGenerator {};

template<class N>
struct MethodGenerator<Type::Method_DO,N> {
    static FP64 generator( MO a ) {
        a.type->init_if_necessary();
        N::access( a.type ) = MethodFinder<N>::find( a.type );
        return N::access( a.type )( a );
    }
};

template<class N>
struct MethodGenerator<Type::Method_YO,N> {
    static struct OwcpChild *generator( MO a ) {
        a.type->init_if_necessary();
        N::access( a.type ) = MethodFinder<N>::find( a.type );
        return N::access( a.type )( a );
    }
};

template<class N>
struct MethodGenerator<Type::Method_OoO,N> {
    static MO generator( MO &a, MO b ) {
        a.type->init_if_necessary();
        b.type->init_if_necessary();
        N::access( a.type )[ b.type->number ] = MethodFinder<N>::find( a.type, b.type );
        return N::access( a.type )[ b.type->number ]( a, b );
    }
};

template<class N>
struct MethodGenerator<Type::Method_BO,N> {
    static bool generator( MO a ) {
        a.type->init_if_necessary();
        N::access( a.type ) = MethodFinder<N>::find( a.type );
        return N::access( a.type )( a );
    }
};

template<class N>
struct MethodGenerator<Type::Method_VOpS,N> {
    static void generator( MO a, void *b, ST c ) {
        a.type->init_if_necessary();
        N::access( a.type ) = MethodFinder<N>::find( a.type );
        return N::access( a.type )( a, b, c );
    }
};

template<class N>
struct MethodGenerator<Type::Method_BOO,N> {
    static bool generator( MO a, MO b ) {
        a.type->init_if_necessary();
        b.type->init_if_necessary();
        N::access( a.type )[ b.type->number ] = MethodFinder<N>::find( a.type, b.type );
        return N::access( a.type )[ b.type->number ]( a, b );
    }
};

template<class N>
struct MethodGenerator<Type::Method_pO,N> {
    static void *generator( MO a ) {
        a.type->init_if_necessary();
        N::access( a.type ) = MethodFinder<N>::find( a.type );
        return N::access( a.type )( a );
    }
};

template<class N>
struct MethodGenerator<Type::Method_FO,N> {
    static FP32 generator( MO a ) {
        a.type->init_if_necessary();
        N::access( a.type ) = MethodFinder<N>::find( a.type );
        return N::access( a.type )( a );
    }
};

template<class N>
struct MethodGenerator<Type::Method_LO,N> {
    static SI64 generator( MO a ) {
        a.type->init_if_necessary();
        N::access( a.type ) = MethodFinder<N>::find( a.type );
        return N::access( a.type )( a );
    }
};

template<class N>
struct MethodGenerator<Type::Method_poO,N> {
    static void *generator( MO &a, MO b ) {
        a.type->init_if_necessary();
        b.type->init_if_necessary();
        N::access( a.type )[ b.type->number ] = MethodFinder<N>::find( a.type, b.type );
        return N::access( a.type )[ b.type->number ]( a, b );
    }
};

template<class N>
struct MethodGenerator<Type::Method_po,N> {
    static void *generator( MO &a ) {
        a.type->init_if_necessary();
        N::access( a.type ) = MethodFinder<N>::find( a.type );
        return N::access( a.type )( a );
    }
};

template<class N>
struct MethodGenerator<Type::Method_EO,N> {
    static FP80 generator( MO a ) {
        a.type->init_if_necessary();
        N::access( a.type ) = MethodFinder<N>::find( a.type );
        return N::access( a.type )( a );
    }
};

template<class N>
struct MethodGenerator<Type::Method_VoO,N> {
    static void generator( MO &a, MO b ) {
        a.type->init_if_necessary();
        b.type->init_if_necessary();
        N::access( a.type )[ b.type->number ] = MethodFinder<N>::find( a.type, b.type );
        return N::access( a.type )[ b.type->number ]( a, b );
    }
};

template<class N>
struct MethodGenerator<Type::Method_Vopp,N> {
    static void generator( MO &a, void *b, void *c ) {
        a.type->init_if_necessary();
        N::access( a.type ) = MethodFinder<N>::find( a.type );
        return N::access( a.type )( a, b, c );
    }
};

template<class N>
struct MethodGenerator<Type::Method_IO,N> {
    static SI32 generator( MO a ) {
        a.type->init_if_necessary();
        N::access( a.type ) = MethodFinder<N>::find( a.type );
        return N::access( a.type )( a );
    }
};

template<class N>
struct MethodGenerator<Type::Method_XOO,N> {
    static struct MetilException *generator( MO a, MO b ) {
        a.type->init_if_necessary();
        b.type->init_if_necessary();
        N::access( a.type )[ b.type->number ] = MethodFinder<N>::find( a.type, b.type );
        return N::access( a.type )[ b.type->number ]( a, b );
    }
};

template<class N>
struct MethodGenerator<Type::Method_VoY,N> {
    static void generator( MO &a, struct OwcpChild *b ) {
        a.type->init_if_necessary();
        N::access( a.type ) = MethodFinder<N>::find( a.type );
        return N::access( a.type )( a, b );
    }
};

template<class N>
struct MethodGenerator<Type::Method_OO,N> {
    static MO generator( MO a ) {
        a.type->init_if_necessary();
        N::access( a.type ) = MethodFinder<N>::find( a.type );
        return N::access( a.type )( a );
    }
};

template<class N>
struct MethodGenerator<Type::Method_OOO,N> {
    static MO generator( MO a, MO b ) {
        a.type->init_if_necessary();
        b.type->init_if_necessary();
        N::access( a.type )[ b.type->number ] = MethodFinder<N>::find( a.type, b.type );
        return N::access( a.type )[ b.type->number ]( a, b );
    }
};

template<class N>
struct MethodGenerator<Type::Method_VOO,N> {
    static void generator( MO a, MO b ) {
        a.type->init_if_necessary();
        b.type->init_if_necessary();
        N::access( a.type )[ b.type->number ] = MethodFinder<N>::find( a.type, b.type );
        return N::access( a.type )[ b.type->number ]( a, b );
    }
};

template<class N>
struct MethodGenerator<Type::Method_VoPS,N> {
    static void generator( MO &a, const void *b, ST c ) {
        a.type->init_if_necessary();
        N::access( a.type ) = MethodFinder<N>::find( a.type );
        return N::access( a.type )( a, b, c );
    }
};

template<class N>
struct MethodGenerator<Type::Method_Vo,N> {
    static void generator( MO &a ) {
        a.type->init_if_necessary();
        N::access( a.type ) = MethodFinder<N>::find( a.type );
        return N::access( a.type )( a );
    }
};

template<class N>
struct MethodGenerator<Type::Method_OOS,N> {
    static MO generator( MO a, ST b ) {
        a.type->init_if_necessary();
        N::access( a.type ) = MethodFinder<N>::find( a.type );
        return N::access( a.type )( a, b );
    }
};

template<class N>
struct MethodGenerator<Type::Method_MO,N> {
    static const MachineId *generator( MO a ) {
        a.type->init_if_necessary();
        N::access( a.type ) = MethodFinder<N>::find( a.type );
        return N::access( a.type )( a );
    }
};


END_METIL_LEVEL1_NAMESPACE;

#endif // METHODGENERATOR_H
