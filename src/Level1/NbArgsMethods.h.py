# -*- coding: utf-8 -*-
from MethodHelper import *

print '// file generated by NbArgsMethods.h.py'
print '#ifndef NB_ARGS_METHOD_H'
print '#define NB_ARGS_METHOD_H'
print ''
for m in methods:
    n = m[1:].count( "O" ) + m[1:].count( "o" )
    print '#define NB_ARGS_METHOD_' + m + ' ' + str( n )
print ''
print '#endif // NB_ARGS_METHOD_H'
