#ifndef DISPLAYITEM_BASICMESH_H
#define DISPLAYITEM_BASICMESH_H

#include "DisplayItem.h"
#include "BasicMesh_Compacted.h"

BEG_METIL_NAMESPACE;

/**
*/
class DisplayItem_BasicMesh : public DisplayItem {
public:
    typedef float T;
    DisplayItem_BasicMesh( Ps<BasicMesh_Compacted> mesh );
    ~DisplayItem_BasicMesh();

    virtual void render_to( BitmapDisplay *display );
    virtual void render_to( VectorDisplay *display );
    virtual void update_p_min_p_max( GenericDisplay *display, T3 &p_min, T3 &p_max, bool use_trans );

    void set_coloring_field( int t, int n, T mi, T ma, int dimension = 0 ); ///< color using field number n

    unsigned *get_elem_count_gpu_ptr( ST nb_types, int sb );
    int *get_elem_data_gpu_ptr( ST needed_size );

protected:
    void make_proj();

    Ps<BasicMesh_Compacted> mesh;

    T *proj[ 3 ]; // pos_nodes in screen coordinates

    ST size_elem_data;
    int *elem_data_gpu;

    ST size_elem_count;
    unsigned *elem_count_gpu;

    T min_coloring_field;
    T max_coloring_field;
    int num_coloring_field, dim_coloring_field, typ_coloring_field;
};

END_METIL_NAMESPACE;

#endif // DISPLAYITEM_BASICMESH_H
