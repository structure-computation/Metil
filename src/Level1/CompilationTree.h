#ifndef COMPILATIONTREE_H
#define COMPILATIONTREE_H

#include "BasicVec.h"
#include "String.h"
#include "Ptr.h"

BEG_METIL_LEVEL1_NAMESPACE;

class CompilationTree : public ObjectWithCptUse {
public:
    CompilationTree( const String &dst );

    void add_child( const Ptr<CompilationTree> &ch );

    int exec( String *out = 0 );
    int exec_node( String *out );

    String dst;
    String cmd;
    BasicVec<Ptr<CompilationTree> > children;
    mutable BasicVec<CompilationTree *> parents;
    SI64 op_id;
};

END_METIL_LEVEL1_NAMESPACE;

#endif // COMPILATIONTREE_H
