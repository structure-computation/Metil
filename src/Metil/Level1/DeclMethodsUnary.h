// basic methods
#ifndef DONT_WANT_UNARY_BASIC

#ifndef AVOID_DEL
DECL_MET( Vo  , del                     ); // call destroy and free
#endif // AVoID_DEL

DECL_MET( Vo  , free                    ); // free memory used by object
DECL_MET( Vo  , destroy                 ); // call destructor

#ifndef AVOID_COPY
DECL_MET( OO  , copy                    ); // make a copy of self
#endif // AVOID_COPY

DECL_MET( OO  , copy_ref                ); // make a copy of a data reference @see RefOn
#endif // DONT_WANT_UNARY_BASIC

DECL_MET( Vo  , init_1                  ); //

DECL_MET( SO  , size_in_mem             ); // size in bytes of the object

//DECL_MET( VOt , write_str               ); // string or file output
//DECL_MET( VOt , write_dot               ); // string or file output
//DECL_MET( VOt , write_tex               ); // string or file output

//DECL_MET( Vot , read_str                ); // string or file input

DECL_MET( Vo  , close                   ); //
DECL_MET( Vo  , flush                   ); //
DECL_MET( VoPS, write                   ); // a.write( ptr, size )
DECL_MET( VopS, read                    ); // a.read ( ptr, size )
DECL_MET( VOpS, copy_data               ); // a.copy_data( ptr, size )
DECL_MET( VoS , seek                    ); //

// arrays
DECL_MET( OO  , base_type               ); //
DECL_MET( OO  , dim                     ); // tensorial order
DECL_MET( OO  , size                    ); // size of data (nb items). Returns a scalar
DECL_MET( OO  , sizes                   ); // size of data (nb items / axes). Returns a vector
DECL_MET( OO  , min_1                   ); // min of the values
DECL_MET( OO  , max_1                   ); // max of the values
DECL_MET( OO  , mul_1                   ); // mul of the values
DECL_MET( OO  , add_1                   ); // mul of the values

// string
DECL_MET( po  , ptr                     ); // return a ptr on data
DECL_MET( po  , ptr_z                   ); // return a ptr on data with a zero at the end (usefull for c_str)
DECL_MET( pO  , new_ptr                 ); // return a new ptr on copy of data
DECL_MET( pO  , new_ptr_z               ); // return a new ptr on copy of data with a zero at the end (usefull for c_str)

// arithmetic, unary
#ifndef DONT_WANT_UNARY_ARITHMETIC
#include "DeclMethodsUnaryArithmetic.h"
#endif // DONT_WANT_UNARY_ARITHMETIC

// conversions
DECL_MET( BO  , convert_to_Bool         ); // operator bool
DECL_MET( IO  , convert_to_SI32         ); // operator SI32
DECL_MET( LO  , convert_to_SI64         ); // operator SI64
DECL_MET( FO  , convert_to_FP32         ); // operator FP32
DECL_MET( DO  , convert_to_FP64         ); // operator FP64
DECL_MET( EO  , convert_to_FP80         ); // operator FP80

DECL_MET( BO  , ok                      ); //

//// graph and lazy evaluation
#ifndef AVOID_LAZY_OP
DECL_MET( OOS , get_child               ); //
DECL_MET( VoY , add_parent              ); // add_parent( OwcpChild )
DECL_MET( VoY , rem_parent              ); // rem_parent( OwcpChild )
DECL_MET( SO  , nb_children             ); // return -1 if not an Owcp
DECL_MET( YO  , get_parent              ); // get_parent
DECL_MET( BO  , cur_op_id               ); // return true if op_id == current_op_id
DECL_MET( DO  , priority                ); // + -> 10, * -> 20, ...
DECL_MET( MO  , machine_id              ); // return info on where the object is stored
DECL_MET( OO  , get_op_mp               ); // return op_mp if an Owcp, 0 if not
DECL_MET( Vopp, set_op_mp               ); // set op_mp if an Owcp, 0 if not
#endif // AVOID_LAZY_OP
