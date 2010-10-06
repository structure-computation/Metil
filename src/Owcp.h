#ifndef OWCP_H
#define OWCP_H

#include "Type.h"
#include "AdditionalDataVoid.h"

BEG_METIL_LEVEL1_NAMESPACE;

/**
*/
struct OwcpChild {
    OwcpChild() : prev( 0 ), next( 0 ) {}
    MO         obj ; // child object
    OwcpChild *prev; // prev parent
    OwcpChild *next; // next parent
    MO         self; // origin object
};

/**
  Objet With Children and parents

  Automatic ref count (-> cpt_use )
*/
struct OwcpAncestor {
    OwcpAncestor() {
        cpt_use      = 0;
        op_id        = 0;
        first_parent = 0;
    }

    /// number of time this object is used
    int   cpt_use;

    /// operation id (every new operation on the graph begins with ++current_op_id
    /// and one can compare op_id with current_op_id to see if operation on this node has been done or not).
    SI64  op_id;

    /// if used somewhere...
    OwcpChild *first_parent;

    /// result of current operations
    MO op_mp;
};

/**
*/
template<int nb_children,class AdditionalData=AdditionalDataVoid>
struct Owcp : public OwcpAncestor {
    CANNOT_BE_DERIVED;

    Owcp( Type *type ) {
        for( int i = 0; i < nb_children; ++i ) children[ i ].self = MO( this, type );
    }

    Owcp( Type *type, const MO &ch_0 ) {
        for( int i = 0; i < nb_children; ++i ) children[ i ].self = MO( this, type );
        init_ch( 0, ch_0 );
    }

    Owcp( Type *type, const MO &ch_0, const MO &ch_1 ) {
        for( int i = 0; i < nb_children; ++i ) children[ i ].self = MO( this, type );
        init_ch( 0, ch_0 );
        init_ch( 1, ch_1 );
    }

    Owcp( Type *type, const MO &ch_0, const MO &ch_1, const MO &ch_2 ) {
        for( int i = 0; i < nb_children; ++i ) children[ i ].self = MO( this, type );
        init_ch( 0, ch_0 );
        init_ch( 1, ch_1 );
        init_ch( 2, ch_2 );
    }

    Owcp( Type *type, const MO &ch_0, const MO &ch_1, const MO &ch_2, const MO &ch_3 ) {
        for( int i = 0; i < nb_children; ++i ) children[ i ].self = MO( this, type );
        init_ch( 0, ch_0 );
        init_ch( 1, ch_1 );
        init_ch( 2, ch_2 );
        init_ch( 3, ch_3 );
    }

    ~Owcp() {
        for( int i = 0; i < nb_children; ++i ) {
            ch( i ).type->rem_parent( ch( i ), children + i );
            CM_1( del, ch( i ) );
        }
    }

    MO &ch( int n ) { return children[ n ].obj; }

    void init_ch( int num, const MO &val ) {
        ch( num ) = CM_1( copy, val );
        ch( num ).type->add_parent( ch( num ), children + num );
    }

    void add_parent( OwcpChild *parent ) {
        if ( first_parent ) {
            first_parent->prev = parent;
            parent->next = first_parent;
            parent->prev = 0;
            first_parent = parent;
        } else {
            first_parent = parent;
            parent->next = 0;
            parent->prev = 0;
        }
    }

    void rem_parent( OwcpChild *parent ) {
        if ( parent == first_parent ) {
            first_parent = first_parent->next;
            if ( first_parent )
                first_parent->prev = 0;
            return;
        }
        //
        for( OwcpChild *p = first_parent->next; p; p = p->next ) {
            if ( p == parent ) {
                p->prev->next = p->next; // we do have a p->prev because this is not the first item
                if ( p->next )
                    p->next->prev = p->prev;
                return;
            }
        }
    }

    /// an Owcp can contain from 0 to ... children meaning that sizeof( Owcp ) does not represent
    /// the room occupied in memory
    OwcpChild children[ nb_children ];

    ///
    AdditionalData data;

    //    static void del( MO &self ) {
    //        Owcp *obj = reinterpret_cast<Owcp *>( self.data );
    //        if ( --obj->cpt_use < 0 )
    //            obj->~Owcp();
    //    }

    //    static void free_( MO &self ) {
    //        FREE( self.data, Number<sizeof(Owcp)>() );
    //    }

    //    static MO copy( const MO &self ) {
    //        ++reinterpret_cast<Owcp *>( self.data )->cpt_use;
    //        return self;
    //    }

    //    static MO copy_ref( const MO &self ) {
    //        ++reinterpret_cast<Owcp *>( self.data )->cpt_use;
    //        MO res( self.data, self.type->bas_type );
    //        return res;
    //    }

    //    static ST size_in_mem( const MO &self ) {
    //        return get_room_used_by( *reinterpret_cast<Owcp *>( self.data ) );
    //    }

    //    static MO get_child( const MO &self, ST num ) {
    //        return reinterpret_cast<const Owcp *>( self.data )->ch( num );
    //    }

    //    static ST nb_children_( const MO &self ) {
    //        return nb_children;
    //    }
};

END_METIL_LEVEL1_NAMESPACE;

#endif // OWCP_H
