#ifndef PNG_H
#define PNG_H

#include "String.h"
#include "Ps.h"

BEG_METIL_NAMESPACE;

Ps<char> make_png( const unsigned *img, int w, int h, bool gray_only = false, const char *prelim = 0, ST prelim_size = 0 );
Ps<char> make_png( const unsigned char *img, int w, int h, bool gray_only = false, const char *prelim = 0, ST prelim_size = 0 );
void save_png( const String &filename, const unsigned char *img, int w, int h, bool gray_only = false );

END_METIL_NAMESPACE;

#endif // PNG_H
