#include "UnitTest.h"
#include "String.h"
#include "Val.h"

using namespace Metil;

int main() {
//    Val a( "a" ), res("res"), b( "b" ), c( "c" ), d( "d" ), m( "m" ), n( "n" );
//    Val A( "A" ), B( "B" ), x("x"), y("y");
//    m = -5;
//    n = 3;

//    UNIT_TEST_CMP_STRING( exp(log(x)), x );
//    UNIT_TEST_CMP_STRING( log(exp(x)), x );

//    /// code généré par /home/pasquier/MyPython/test_unitaire_pour_metil/main.py
//    UNIT_TEST_CMP_STRING( a+a , 2*a );
//    UNIT_TEST_CMP_STRING( a-a , 0 );
//    UNIT_TEST_CMP_STRING( -a+a , 0 );
//    UNIT_TEST_CMP_STRING( -a-a , (-2)*a );
//    UNIT_TEST_CMP_STRING( a+0 , a );
//    UNIT_TEST_CMP_STRING( 0+a , a );
//    UNIT_TEST_CMP_STRING( 0-a , neg(a) );
//    UNIT_TEST_CMP_STRING( -a+0 , neg(a) );
//    UNIT_TEST_CMP_STRING( -a+2*a , a );
//    UNIT_TEST_CMP_STRING( -a+5*a , 4*a );
//    UNIT_TEST_CMP_STRING( a+5*a , 6*a );
//    UNIT_TEST_CMP_STRING( 1*a , a );
//    UNIT_TEST_CMP_STRING( a*1 , a );
//    UNIT_TEST_CMP_STRING( a/1 , a );
//    UNIT_TEST_CMP_STRING( -1*a , neg(a) );
//    UNIT_TEST_CMP_STRING( a*(-1) , neg(a) );
//    UNIT_TEST_CMP_STRING( 5*a+2*a , 7*a );
//    UNIT_TEST_CMP_STRING( 5*a+(-2)*a , 3*a );
//    UNIT_TEST_CMP_STRING( 5*a+(-6)*a , neg(a) );
//    UNIT_TEST_CMP_STRING( a/2 , 1/2*a );
//    UNIT_TEST_CMP_STRING( a*a , pow(a,2) );
//    UNIT_TEST_CMP_STRING( a*pow(a,2) , pow(a,3) );
//    UNIT_TEST_CMP_STRING( a/a , 1 );
//    UNIT_TEST_CMP_STRING( 0*a , 0 );
//    UNIT_TEST_CMP_STRING( a*0 , 0 );
//    UNIT_TEST_CMP_STRING( 1/a , inv(a) );
//    UNIT_TEST_CMP_STRING( n*a*m , (-15)*a );
//    UNIT_TEST_CMP_STRING( a*(-b) , neg(a*b) );
//    UNIT_TEST_CMP_STRING( (-a)*b , neg(a*b) );
//    UNIT_TEST_CMP_STRING( (-a)*(-b) , a*b );
//    UNIT_TEST_CMP_STRING( a/(-1) , neg(a) );
//    UNIT_TEST_CMP_STRING( (-1)/a , neg(inv(a)) );
//    UNIT_TEST_CMP_STRING( pow(a,m)*pow(a,n) , pow(a,-2) );
//    UNIT_TEST_CMP_STRING( pow(a,m)/pow(a,n) , pow(a,-8) );
//    UNIT_TEST_CMP_STRING( a*pow(a,m) , pow(a,-4) );
//    UNIT_TEST_CMP_STRING( a/pow(a,m) , pow(a,6) );
//    UNIT_TEST_CMP_STRING( pow(a,m)*a , pow(a,-4) );
//    UNIT_TEST_CMP_STRING( pow(a,m)/a , pow(a,-6) );
//    UNIT_TEST_CMP_STRING( n*(-a)*m , 15*a );
//    UNIT_TEST_CMP_STRING( (-a)*pow(a,m) , neg(pow(a,-4)) );
//    UNIT_TEST_CMP_STRING( pow(a,m)*(-a) , neg(pow(a,-4)) );
//    UNIT_TEST_CMP_STRING( (-a)/pow(a,m) , neg(pow(a,6)) );
//    UNIT_TEST_CMP_STRING( pow(a,m)/(-a) , neg(pow(a,-6)) );
//    UNIT_TEST_CMP_STRING( -(-a) , a );
//    UNIT_TEST_CMP_STRING( 1/(1/a) , a );
//    UNIT_TEST_CMP_STRING( 5*a+a , 6*a );
//    UNIT_TEST_CMP_STRING( pow(a,m)*(1/a) , pow(a,-6) );
//    UNIT_TEST_CMP_STRING( (1/a)*pow(a,m) , pow(a,-6) );
//    UNIT_TEST_CMP_STRING( 3*a-a/3 , 8/3*a );
//    UNIT_TEST_CMP_STRING( a/(-b) , neg(a/b) );
//    UNIT_TEST_CMP_STRING( (-a)/b , neg(a/b) );
//    UNIT_TEST_CMP_STRING( (-a)/(-b) , a/b );
//    UNIT_TEST_CMP_STRING( pow(a,m)*(-1/a) , neg(pow(a,-6)) );
//    UNIT_TEST_CMP_STRING( (-1/a)*pow(a,m) , neg(pow(a,-6)) );
//    UNIT_TEST_CMP_STRING( pow(a,m)/(-1/a) , neg(pow(a,-4)) );
//    UNIT_TEST_CMP_STRING( (-1/a)/pow(a,m) , neg(inv(pow(a,-4))) );
//    UNIT_TEST_CMP_STRING( 5*(-a) , (-5)*a );
//    UNIT_TEST_CMP_STRING( 5/(-a) , (-5)/a );
//    UNIT_TEST_CMP_STRING( (-a)/5 , (-1/5)*a );
//    UNIT_TEST_CMP_STRING( (1/a)*b , b/a );
//    UNIT_TEST_CMP_STRING( b*(1/a) , b/a );
//    UNIT_TEST_CMP_STRING( sqrt(a)*sqrt(a) , a );
//    UNIT_TEST_CMP_STRING( sqrt(a)*sqrt(b) , sqrt(a*b) );
//    UNIT_TEST_CMP_STRING( sqrt(a)/sqrt(b) , sqrt(a/b) );
//    UNIT_TEST_CMP_STRING( pow(a,1) , a );
//    UNIT_TEST_CMP_STRING( pow(a,-1) , inv(a) );
//    UNIT_TEST_CMP_STRING( pow(sqrt(a),2) , a );
//    UNIT_TEST_CMP_STRING( pow(sqrt(a),3) , pow(a,3/2) );
//    UNIT_TEST_CMP_STRING( pow(sqrt(a),4) , pow(a,2) );
//    UNIT_TEST_CMP_STRING( pow(sqrt(a),5) , pow(a,5/2) );
//    UNIT_TEST_CMP_STRING( pow(sqrt(a),-1) , inv(sqrt(a)) );
//    UNIT_TEST_CMP_STRING( pow(sqrt(a),-2) , inv(a) );
//    UNIT_TEST_CMP_STRING( pow(sqrt(a),-3) , pow(a,-3/2) );
//    UNIT_TEST_CMP_STRING( pow(sqrt(a),1) , sqrt(a) );
//    UNIT_TEST_CMP_STRING( pow(sqrt(a),-1) , inv(sqrt(a)) );
//    UNIT_TEST_CMP_STRING( pow(a,Val("1/2")) , sqrt(a) );
//    UNIT_TEST_CMP_STRING( pow(pow(a,m),n) , pow(a,-15) );
//    UNIT_TEST_CMP_STRING( pow(a,m)*sqrt(a) , pow(a,-9/2) );
//    UNIT_TEST_CMP_STRING( sqrt(a)*pow(a,m) , pow(a,-9/2) );
//    UNIT_TEST_CMP_STRING( pow(a,m)/sqrt(a) , pow(a,-11/2) );
//    UNIT_TEST_CMP_STRING( sqrt(a)/pow(a,m) , pow(a,11/2) );
//    UNIT_TEST_CMP_STRING( a*sqrt(a) , pow(a,3/2) );
//    UNIT_TEST_CMP_STRING( sqrt(a)*a , pow(a,3/2) );
//    UNIT_TEST_CMP_STRING( pow(sqrt(a),2) , a );
//    UNIT_TEST_CMP_STRING( sqrt(a)/a , inv(sqrt(a)) );
//    UNIT_TEST_CMP_STRING( a/sqrt(a) , sqrt(a) );
//    UNIT_TEST_CMP_STRING( sqrt(pow(a,2)) , abs(a) );
//    UNIT_TEST_CMP_STRING( sqrt(pow(a,m)) , pow(a,-5/2) );
//    UNIT_TEST_CMP_STRING( sqrt(pow(a,n)) , pow(a,3/2) );
//    UNIT_TEST_CMP_STRING( sqrt(pow(a,b)) , pow(a,1/2*b) );
//    UNIT_TEST_CMP_STRING( pow((-a),m) , neg(pow(a,-5)) );
//    UNIT_TEST_CMP_STRING( pow((-a),2) , pow(a,2) );
//    UNIT_TEST_CMP_STRING( pow((-a),3) , neg(pow(a,3)) );
//    UNIT_TEST_CMP_STRING( pow((-a),1.5) , pow(neg(a),1.500e0) );
//    UNIT_TEST_CMP_STRING( pow((-a),b) , pow(neg(a),b) );
//    UNIT_TEST_CMP_STRING( pow(1/a,m) , pow(a,5) );
//    UNIT_TEST_CMP_STRING( pow(pow(a,4),Val("1/4")) , abs(a) );
//    UNIT_TEST_CMP_STRING( pow(pow(a,12),Val("1/4")) , pow(abs(a),3) );
//    UNIT_TEST_CMP_STRING( pow(pow(a,13),Val("1/4") ) , pow(a,13/4) );
//    UNIT_TEST_CMP_STRING( pow(pow(a,12),Val("3/4") ) , pow(a,9) );
//    UNIT_TEST_CMP_STRING( a+(a+b) , b+2*a );
    
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a+(3*a+b) = b+4*a" ,  a+(3*a+b) , b+4*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a+((-2)*a+b) = b-a" ,  a+((-2)*a+b) , b-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a+((-a)+b) = b" ,  a+((-a)+b) , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a+(a+b) = b+4*a" ,  3*a+(a+b) , b+4*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a+(2*a+b) = b+5*a" ,  3*a+(2*a+b) , b+5*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "-3*a+(2*a+b) = b-a" ,  -3*a+(2*a+b) , b-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "-3*a+(3*a+b) = b" ,  -3*a+(3*a+b) , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "-3*a+(4*a+b) = a+b" ,  -3*a+(4*a+b) , a+b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a+(b+a) = b+2*a" ,  a+(b+a) , b+2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a+(b+3*a) = b+4*a" ,  a+(b+3*a) , b+4*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a+(b+a) = b+4*a" ,  3*a+(b+a) , b+4*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a+(b+2*a) = b+5*a" ,  3*a+(b+2*a) , b+5*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a+(b+(-a)) = b" ,  a+(b+(-a)) , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a+(a-b) = 2*a-b" ,  a+(a-b) , 2*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a+(3*a-b) = 4*a-b" ,  a+(3*a-b) , 4*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a+(a-b) = 4*a-b" ,  3*a+(a-b) , 4*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a+(2*a-b) = 5*a-b" ,  3*a+(2*a-b) , 5*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a+((-3)*a-b) = neg(b)" ,  3*a+((-3)*a-b) , neg(b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a+((-4)*a-b) = neg(a)-b" ,  3*a+((-4)*a-b) , neg(a+b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a+(b-a) = b" ,  a+(b-a) , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a+(b-(-2)*a) = b+3*a" ,  a+(b-(-2)*a) , b+3*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a+(b-a) = b+2*a" ,  3*a+(b-a) , b+2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a+(b-3*a) = b+-2*a" ,  a+(b-3*a) , b+(-2)*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a+(b-2*a) = a+b" ,  3*a+(b-2*a) , a+b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "5*a+(b-5*a) = b" ,  5*a+(b-5*a) , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a+b)+a = b+2*a" ,  (a+b)+a , b+2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a+b)+3*a = b+4*a" ,  (a+b)+3*a , b+4*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(2*a+b)+3*a = b+5*a" ,  (2*a+b)+3*a , b+5*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "((-3)*a+b)+3*a = b" ,  ((-3)*a+b)+3*a , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "((-4)*a+b)+3*a = b-a" ,  ((-4)*a+b)+3*a , b-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(2*a+b)+a = b+3*a" ,  (2*a+b)+a , b+3*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "((-2)*a+b)+a = b-a" ,  ((-2)*a+b)+a , b-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "((-a)+b)+a = b" ,  ((-a)+b)+a , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b+a)+a = b+2*a" ,  (b+a)+a , b+2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b+a)+3*a = b+4*a" ,  (b+a)+3*a , b+4*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b+2*a)+3*a = b+5*a" ,  (b+2*a)+3*a , b+5*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b+(-3)*a)+3*a = b" ,  (b+(-3)*a)+3*a , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b+(-4)*a)+3*a = b-a" ,  (b+(-4)*a)+3*a , b-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b+2*a)+a = b+3*a" ,  (b+2*a)+a , b+3*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b+(-2)*a)+a = b-a" ,  (b+(-2)*a)+a , b-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b+(-a))+a = b" ,  (b+(-a))+a , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-b)+a = 2*a-b" ,  (a-b)+a , 2*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "((-a)-b)+a = neg(b)" ,  ((-a)-b)+a , neg(b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-b)+3*a = 4*a-b" ,  (a-b)+3*a , 4*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "((-a)-b)+3*a = 2*a-b" ,  ((-a)-b)+3*a , 2*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(2*a-b)+3*a = 5*a-b" ,  (2*a-b)+3*a , 5*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "((-3)*a-b)+3*a = neg(b)" ,  ((-3)*a-b)+3*a , neg(b) );
//    UNIT_TEST_CMP_STRING( (-4)*a-b+3*a , neg(a+b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-a)+a = b" ,  (b-a)+a , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-(-a))+a = b+2*a" ,  (b-(-a))+a , b+2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-a)+(-a) = b-2*a" ,  (b-a)+(-a) , b-2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-(-a))+(-a) = b" ,  (b-(-a))+(-a) , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-a)+3*a = b+2*a" ,  (b-a)+3*a , b+2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-2*a)+3*a = a+b" ,  (b-2*a)+3*a , a+b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-(-3)*a)+3*a = b+6*a" ,  (b-(-3)*a)+3*a , b+6*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-(-4)*a)+3*a = b+7*a" ,  (b-(-4)*a)+3*a , b+7*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(2*a-b)+a = 3*a-b" ,  (2*a-b)+a , 3*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "((-2)*a-b)+a = neg(a)-b" ,  ((-2)*a-b)+a , neg(a+b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "((-a)-b)+a = neg(b)" ,  ((-a)-b)+a , neg(b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a-(a+b) = neg(b)" ,  a-(a+b) , neg(b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a-(5*a+b) = -4*a-b" ,  a-(5*a+b) , (-4)*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a-(2*a+b) = neg(a)-b" ,  a-(2*a+b) , neg(a+b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a-((-a)+b) = 2*a-b" ,  a-((-a)+b) , 2*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a-(a+b) = 2*a-b" ,  3*a-(a+b) , 2*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a-((-a)+b) = 4*a-b" ,  3*a-((-a)+b) , 4*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a-(5*a+b) = -2*a-b" ,  3*a-(5*a+b) , (-2)*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a-(4*a+b) = neg(a)-b" ,  3*a-(4*a+b) , neg(a+b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a-(2*a+b) = a-b" ,  3*a-(2*a+b) , a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a-(3*a+b) = neg(b)" ,  3*a-(3*a+b) , neg(b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a-(b+a) = neg(b)" ,  a-(b+a) , neg(b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a-(b+5*a) = -4*a-b" ,  a-(b+5*a) , (-4)*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a-(b+(-2)*a) = 3*a-b" ,  a-(b+(-2)*a) , 3*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a-(b+(-a)) = 2*a-b" ,  a-(b+(-a)) , 2*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a-(b+a) = 2*a-b" ,  3*a-(b+a) , 2*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a-(b+5*a) = -2*a-b" ,  3*a-(b+5*a) , (-2)*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a-(b+4*a) = neg(a)-b" ,  3*a-(b+4*a) , neg(a+b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a-(b+3*a) = neg(b)" ,  3*a-(b+3*a) , neg(b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a-(b+2*a) = a-b" ,  3*a-(b+2*a) , a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a-(a-b) = b" ,  a-(a-b) , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a-(3*a-b) = b+-2*a" ,  a-(3*a-b) , b+(-2)*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a-(2*a-b) = b-a" ,  a-(2*a-b) , b-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a-((-a)-b) = b+2*a" ,  a-((-a)-b) , b+2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a-((-3)*a-b) = b+4*a" ,  a-((-3)*a-b) , b+4*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a-(a-b) = b+2*a" ,  3*a-(a-b) , b+2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a-(5*a-b) = b+-2*a" ,  3*a-(5*a-b) , b+(-2)*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a-(4*a-b) = b-a" ,  3*a-(4*a-b) , b-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a-(3*a-b) = b" ,  3*a-(3*a-b) , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a-(2*a-b) = a+b" ,  3*a-(2*a-b) , a+b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a-(b-a) = 2*a-b" ,  a-(b-a) , 2*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a-(b-3*a) = 4*a-b" ,  a-(b-3*a) , 4*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a-(b-2*a) = 3*a-b" ,  a-(b-2*a) , 3*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a-(b-(-2)*a) = neg(a)-b" ,  a-(b-(-2)*a) , neg(a+b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a-(b-(-a)) = neg(b)" ,  a-(b-(-a)) , neg(b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a+b)-a = b" ,  (a+b)-a , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(5*a+b)-a = b+4*a" ,  (5*a+b)-a , b+4*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(2*a+b)-a = a+b" ,  (2*a+b)-a , a+b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "((-a)+b)-a = b-2*a" ,  ((-a)+b)-a , b-2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a+b)-3*a = b+-2*a" ,  (a+b)-3*a , b+(-2)*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(5*a+b)-3*a = b+2*a" ,  (5*a+b)-3*a , b+2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(4*a+b)-3*a = a+b" ,  (4*a+b)-3*a , a+b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(3*a+b)-3*a = b" ,  (3*a+b)-3*a , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(2*a+b)-3*a = b-a" ,  (2*a+b)-3*a , b-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b+a)-a = b" ,  (b+a)-a , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b+5*a)-a = b+4*a" ,  (b+5*a)-a , b+4*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b+2*a)-a = a+b" ,  (b+2*a)-a , a+b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b+(-a))-a = b-2*a" ,  (b+(-a))-a , b-2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-b)-a = neg(b)" ,  (a-b)-a , neg(b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(5*a-b)-a = 4*a-b" ,  (5*a-b)-a , 4*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "((-a)-b)-a = -2*a-b" ,  ((-a)-b)-a , neg(b+2*a) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-b)-3*a = -2*a-b" ,  (a-b)-3*a , (-2)*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(5*a-b)-3*a = 2*a-b" ,  (5*a-b)-3*a , 2*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(4*a-b)-3*a = a-b" ,  (4*a-b)-3*a , a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(3*a-b)-3*a = neg(b)" ,  (3*a-b)-3*a , neg(b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(2*a-b)-3*a = neg(a)-b" ,  (2*a-b)-3*a , neg(a+b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-a)-a = b-2*a" ,  (b-a)-a , b-2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-3*a)-a = b-4*a" ,  (b-3*a)-a , b-4*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-(-2)*a)-a = a+b" ,  (b-(-2)*a)-a , a+b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-(-a))-a = b" ,  (b-(-a))-a , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-a)-3*a = b-4*a" ,  (b-a)-3*a , b-4*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-5*a)-3*a = b-8*a" ,  (b-5*a)-3*a , b-8*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-(-3)*a)-3*a = b" ,  (b-(-3)*a)-3*a , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-(-4)*a)-3*a = a+b" ,  (b-(-4)*a)-3*a , a+b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-(-2)*a)-3*a = b-a" ,  (b-(-2)*a)-3*a , b-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a*(1-b)+a*b = a" ,  a*(1-b)+a*b , a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a*c)/(a*b) = c/b" ,  (a*c)/(a*b) , c/b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a*c)/(b*a) = c/b" ,  (a*c)/(b*a) , c/b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(c*a)/(a*b) = c/b" ,  (c*a)/(a*b) , c/b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(c*a)/(b*a) = c/b" ,  (c*a)/(b*a) , c/b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a/(a*b) = inv(b)" ,  a/(a*b) , inv(b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a/b)/(c/d) = (a*d)/(b*c)" ,  (a/b)/(c/d) , (a*d)/(b*c) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a/(a*b) = inv(b)" ,  a/(a*b) , inv(b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a/(b*a) = inv(b)" ,  a/(b*a) , inv(b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a*b)/a = b" ,  (a*b)/a , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b*a)/a = b" ,  (b*a)/a , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(-a)/(a*b) = neg(inv(b))" ,  (-a)/(a*b) , neg(inv(b)) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(-a)/(b*a) = neg(inv(b))" ,  (-a)/(b*a) , neg(inv(b)) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a*b)/(-a) = neg(b)" ,  (a*b)/(-a) , neg(b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b*a)/(-a) = neg(b)" ,  (b*a)/(-a) , neg(b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "b/(1/a) = a*b" ,  b/(1/a) , a*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(1/a)/b = inv(a*b)" ,  (1/a)/b , inv(a*b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "b/(1/(-a)) = neg(a*b)" ,  b/(1/(-a)) , neg(a*b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(1/(-a))/b = neg(inv(a*b))" ,  (1/(-a))/b , neg(inv(a*b)) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(-b)/(1/a) = neg(a*b)" ,  (-b)/(1/a) , neg(a*b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(1/a)/(-b) = neg(inv(a*b))" ,  (1/a)/(-b) , neg(inv(a*b)) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(-b)/(1/(-a)) = a*b" ,  (-b)/(1/(-a)) , a*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(1/(-a))/(-b) = inv(a*b)" ,  (1/(-a))/(-b) , inv(a*b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(2*b+3*a)+(2*a+7*b) = 9*b+5*a" ,  (2*b+3*a)+(2*a+7*b) , 9*b+5*a );
//    /// fin du code généré

//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-b)*c+(b-a)*d = (a-b)*(c-d)" ,  (a-b)*c+(b-a)*d , (a-b)*(c-d) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-b)*c+d*(b-a) = (a-b)*(c-d)", (a-b)*c+d*(b-a), (a-b)*(c-d) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "c*(a-b)+(b-a)*d = (a-b)*(c-d)" , c*(a-b)+(b-a)*d , (a-b)*(c-d) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-b)*c+(b-a)*3 = (a-b)*(c-3)" , (a-b)*c+(b-a)*3 , (a-b)*(c-3) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-b)*c+(b-a)*3 = (a-b)*(c-3)" ,  (a-b)*c+(b-a)*3 , (a-b)*(c-3) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-b)*3+(b-a)*d = (d-3)*(b-a)" , (a-b)*3+(b-a)*d , (a-b)*(3-d) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "2*(a-b)+(b+(-3)*(b-a)) = b+5*(a-b)",  2*(a-b)+(b+(-3)*(b-a) ) , b+(-5)*(b-a) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "2*(a-b)+(b+c*(b-a)) = b+(a-b)*(2-c)",  2*(a-b)+(b+c*(b-a)) , b+(a-b)*(2-c) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "2*(a-b)+(c*(b-a)+b) = b+(a-b)*(2-c)",  2*(a-b)+(c*(b-a)+b) , b+(a-b)*(2-c) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "c*(a-b)+(c*(b-a)+b) = b",  c*(a-b)+(c*(b-a)+b) , b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "c*(a-b)+(2*(b-a)-b) = (2-c)*(a-b)-b",  c*(a-b)+(2*(b-a)-b) , (a-b)*(c-2)-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "c*(a-b)+(c*(b-a)-b) =  neg(b)",  c*(a-b)+(c*(b-a)-b) , neg(b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "c*(a-b)+(d*(b-a)-b) = (a-b)*(c-d)-b", c*(a-b)+d*(b-a)-b, (a-b)*(c-d)-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "c*(a-b)+(b-d*(b-a)) = b+(a-b)*(c+d)",  c*(a-b)+(b-d*(b-a)) , b+(a-b)*(c+d) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( x * (b-a) - y ) + A * (a-b) = (a-b)*(A-x)-y",  ( x * (b-a) - y ) + A * (a-b) , (a-b)*(A-x)-y );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( y - x * (b-a) ) + A * (a-b) = y+(a-b)*(x+A)", ( y - x * (b-a) ) + A * (a-b), y+(a-b)*(x+A) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( y - x * (b-a) ) + A * (a-b) = y+(a-b)*(x+A)", ( y - x * (b-a) ) + A * (a-b), y+(a-b)*(x+A) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "A * (a-b) - ( x * (b-a) + y ) = (a-b)*(x+A)-y", A * (a-b) - ( x * (b-a) + y ), (a-b)*(x+A)-y );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "A * (a-b) - ( y + x * (b-a) ) = (a-b)*(x+A)-y", A * (a-b) - ( y + x * (b-a) ) , (a-b)*(x+A)-y );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "A * (a-b) - ( x * (b-a) - y ) = y+(a-b)*(x+A)", A * (a-b) - ( x * (b-a) - y ) , y+(a-b)*(x+A) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "A * (a-b) - ( y - x * (b-a) ) = (a-b)*(A-x)-y", A * (a-b) - ( y - x * (b-a) ) , (a-b)*(A-x)-y );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( x * (b-a) + y ) - A * (a-b) = y-(a-b)*(x+A)", ( x * (b-a) + y ) - A * (a-b) , y-(a-b)*(x+A) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( y + x * (b-a) ) - A * (a-b) = y-(a-b)*(x+A)", ( y + x * (b-a) ) - A * (a-b) , y-(a-b)*(x+A) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-b)*A/((a-b)*B) = A/B",  (a-b)*A/((a-b)*B) , A/B );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-b)*A/((b-a)*B) = neg(A/B)",  (a-b)*A/((b-a)*B) , neg(A/B) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( x * (b-a) - y ) - A * (a-b) = (a-b)*(neg(A)-x)-y", ( x * (b-a) - y ) - A * (a-b) , (b-a)*(x+A)-y );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( y - x * (b-a) ) - A * (a-b) = y+(a-b)*(x-A)",  ( y - x * (b-a) ) - A * (a-b) , y-(a-b)*(A-x) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a*b-a*c = a*(b-c)",  a*b-a*c , a*(b-c) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "b*a-a*c = a*(b-c)",  b*a-a*c , a*(b-c) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "A * (a-b) - (a-b) * x = (a-b)*(A-x)", A * (a-b) - (a-b) * x , (b-a)*(A-x) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "A * (a-b) - x * (a-b) = (a-b)*(A-x)", A * (a-b) - x * (a-b) , (b-a)*(A-x) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-b) * A - (a-b) * x = (a-b)*(A-x)", (a-b) * A - (a-b) * x , (b-a)*(A-x) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-b) * A - x * (a-b) = (a-b)*(A-x)", (a-b) * A - x * (a-b) , (b-a)*(A-x) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "A * (a-b) - (b-a) * x = (a-b)*(x+A)", A * (a-b) - (b-a) * x , (a-b)*(x+A) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "A * (a-b) - x * (b-a) = (a-b)*(x+A)", A * (a-b) - x * (b-a) , (a-b)*(x+A) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-b) * A - (b-a) * x = (a-b)*(x+A)", (a-b) * A - (b-a) * x , (a-b)*(x+A) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-b) * A - x * (b-a) = (a-b)*(x+A)", (a-b) * A - x * (b-a) , (a-b)*(x+A) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "A * (b-a) - (a-b) * x = (b-a)*(x+A)", A * (b-a) - (a-b) * x , (b-a)*(x+A) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "A * (b-a) - x * (a-b) = (b-a)*(x+A)", A * (b-a) - x * (a-b) , (b-a)*(x+A) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-a) * A - (a-b) * x = (b-a)*(x+A)", (b-a) * A - (a-b) * x , (b-a)*(x+A) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-a) * A - x * (a-b) = (b-a)*(x+A)", (b-a) * A - x * (a-b) , (b-a)*(x+A) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "A * (a-b) + (b-a) * x = (b-a)*(x-A)", A * (a-b) + (b-a) * x , (a-b)*(A-x) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "A * (a-b) + x * (b-a) = (a-b)*(A-x)", A * (a-b) + x * (b-a) , (a-b)*(A-x) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-b) * A + (b-a) * x = (a-b)*(A-x)", (a-b) * A + (b-a) * x , (a-b)*(A-x) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-b) * A + x * (b-a) = (a-b)*(A-x)", (a-b) * A + x * (b-a) , (a-b)*(A-x) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "A * (b-a) + (a-b) * x = (b-a)*(A-x)", A * (b-a) + (a-b) * x , (b-a)*(A-x) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "A * (b-a) + x * (a-b) = (b-a)*(A-x)", A * (b-a) + x * (a-b) , (b-a)*(A-x) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-a) * A + (a-b) * x = (a-b)*(x-A)", (b-a) * A + (a-b) * x , (b-a)*(A-x) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(b-a) * A + x * (a-b) = (a-b)*(x-A)", (b-a) * A + x * (a-b), (b-a)*(A-x)  );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "3*a-((-a)+b) = 4*a-b",  3*a-((-a)+b) , 4*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(-a)+b = b-a",  (-a)+b , b-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(3+a)+5 = 8+a",  (3+a)+5 , 8+a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(3+a)+ 1/7 = a+22/7",  (3+a)+ Val("1/7") , 22/7+a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a+3)+5 = a+8",  (a+3)+5 , 8+a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a+3)+ 1/7 = a+22/7",  (a+3)+ Val("1/7") , 22/7+a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(3-a)+5 = 8-a",  (3-a)+5 , 8-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(3-a)+ 1/7 = 22/7-a",  (3-a)+ Val("1/7") , 22/7-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-3)+5 = 2+a",  (a-3)+5 , 2+a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-3)+ 1/7 = -20/7+a", (a-3)+ Val("1/7") , -20/7+4 );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(3+a)-5 = -2+a",  (3+a)-5 , -2+a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(3+a)- 1/7 = 20/7+a",  (3+a)- Val("1/7") , 20/7+a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a+3)-5 = -2+a",  (a+3)-5 , -2+a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a+3)- 1/7 = 20/7+a",  (a+3)- Val("1/7") , 20/7+a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(3-a)-5 = -2-a",  (3-a)-5 , -2-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(3-a)- 1/7 = 20/7-a",  (3-a)- Val("1/7") , 20/7-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-3)-5 = a-8",  (a-3)-5 , a-8 );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(a-3)- 1/7 = a-22/7",  (a-3)- Val("1/7") , a-22/7 );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "x+a+(x-1)*a = x*(1+a)",  x+a+(x-1)*a , x*(1+a) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "x+(1-x) = 1",  x+(1-x) , 1 );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "-5+(2+x) = -3+x",  -5+(2+x) , -3+x );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(1-x)-1 = neg(x)",  (1-x)-1 , neg(x) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "2+(1+a) = 3+a",  2+(1+a) , 3+a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "2+(1-a) = 3-a",  2+(1-a) , 3-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "2+(a+1) = 3+a",   2+(a+1) , 3+a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "2+(a-1) = 1+a",   2+(a-1) , 1+a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "2-(1+a) = 1-a",   2-(1+a) , 1-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "2-(1-a) = 1+a",   2-(1-a) , 1+a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "2-(a+1) = 1-a",   2-(a+1) , 1-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "2-(a-1) = 3-a",   2-(a-1) , 3-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(1/a)*(1/b) = 1/(a*b)",  (1/a)*(1/b) , inv(a*b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(1/a)/(1/b) = b/a",  (1/a)/(1/b) , b/a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "exp(0) = 1",  exp( zero ) , 1 );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "exp(a)*exp(b) = exp(a+b)",  exp( a ) * exp( b ) , exp(a+b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "exp(a)/exp(b) = exp(a-b)",  exp( a ) / exp( b ) , exp(a-b) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a*b+a^3 = a*(b+a^2)",  a*b+pow(a,3) , a*(b+pow(a,2)) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "b*a+a^3 = a*(b+a^2)",  b*a+pow(a,3) , a*(b+pow(a,2)) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a^3+a*b = a*(b+a^2)",  pow(a,3)+a*b , a*(b+pow(a,2)) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "a^3+b*a = a*(b+a^2)",  pow(a,3)+b*a , a*(b+pow(a,2)) );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a + b ) + ( a + b ) = 4*a+2*b",  ( 3 * a + b ) + ( a + b ) , 4*a+2*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a + b ) + ( b + a ) = 4*a+2*b", ( 3 * a + b ) + ( b + a ) , 4*a+2*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a + b ) + ( a + c ) = 4*a+c+b",  ( 3 * a + b ) + ( a + c ) , b+c+4*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a + b ) + ( c + a ) = 4*a+c+b",  ( 3 * a + b ) + ( c + a ) , b+c+4*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b + a ) + ( a + c ) = 2*a+c+3*b", ( 3 * b + a ) + ( a + c ) , c+3*b+2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b + a ) + ( c + a ) = 2*a+c+3*b", ( 3 * b + a ) + ( c + a ) , c+3*b+2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(3*a+2*b)+(2*a+7*c) ) = 5*a+7*c+2*b",  (3*a+2*b)+(2*a+7*c) , 5*a+7*c+2*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a - b ) + ( a + b ) = 4*a",  ( 3 * a - b ) + ( a + b ) , 4*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a - b ) + ( b + a ) = 4*a",  ( 3 * a - b ) + ( b + a ) , 4*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a - b ) + ( a + c ) = 4*a+c-b",  ( 3 * a - b ) + ( a + c ) , c+4*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a - b ) + ( c + a ) = 4*a+c-b",  ( 3 * a - b ) + ( c + a ) , c+4*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b - a ) + ( a + c ) = c+3*b", ( 3 * b - a ) + ( a + c ) , c+3*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b - a ) + ( c + a ) = c+3*b", ( 3 * b - a ) + ( c + a ) , c+3*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a - 2*b ) + ( a + b ) = 4*a-b",  ( 3 * a - 2*b ) + ( a + b ) , 4*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a - 2*b ) + ( b + a ) = 4*a-b",  ( 3 * a - 2*b ) + ( b + a ) , 4*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a - b ) + ( a + c ) = 4*a+c-b",  ( 3 * a - b ) + ( a + c ) , c+4*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a - b ) + ( c + a ) = 4*a+c-b",  ( 3 * a - b ) + ( c + a ) , c+4*a-b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b - 3*a ) + ( a + c ) = -2*a+c+3*b",  ( 3 * b - 3*a ) + ( a + c ) , c+3*b+(-2)*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b - 2*a ) + ( c + a ) = 3*b+c-a",  ( 3 * b - 2*a ) + ( c + a ) , c+3*b-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT(  "( 3 * b + a ) + ( a - c ) = 2*a+3*b-c",  ( 3 * b + a ) + ( a - c ) , 2*a+3*b-c );
//    UNIT_TEST_CMP_STRING_WITH_TEXT(  "( 3 * b + a ) + ( c - a ) = c+3*b",  ( 3 * b + a ) + ( c - a ) , c+3*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT(  "( 3 * b + a ) + ( c - 2*a ) = -a+c+3*b",  ( 3 * b + a ) + ( c - 2*a ) , c+3*b-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT(  "( 3 * b + a ) + ( -3*b - a ) = 0",   ( 3 * b + a ) + ( -3*b - a ) , 0 );
//    UNIT_TEST_CMP_STRING_WITH_TEXT(  "( a + 3 * b ) + ( a - c ) = 2*a+3*b-c",  ( a + 3 * b ) + ( a - c ) , 2*a+3*b-c );
//    UNIT_TEST_CMP_STRING_WITH_TEXT(  "( a + 3 * b ) + ( c - a ) = c+3*b",  ( a + 3 * b ) + ( c - a ) , c+3*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT(  "( a + 3 * b ) + ( c - 2*a ) =  -a+c+3*b",  ( a + 3 * b ) + ( c - 2*a ) , c+3*b-a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT(  "( a + 3 * b ) + ( -3*b - a ) = 0" ,  ( a + 3 * b ) + ( -3*b - a ) , 0 );
//    UNIT_TEST_CMP_STRING_WITH_TEXT(  "( 3 * b - a ) + ( a - c ) = 3*b-c" ,  ( 3 * b - a ) + ( a - c ) , 3*b-c );
//    UNIT_TEST_CMP_STRING_WITH_TEXT(  "( 3 * b - a ) + ( c - a ) = c+3*b-2*a" ,  ( 3 * b - a ) + ( c - a ) , c+3*b-2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT(  "( 3 * b - a ) + ( c - 2*a ) = c+3*b-3*a",  ( 3 * b - a ) + ( c - 2*a ) , c+3*b-3*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT(  "( 3 * b - a ) + ( -3*b - a ) = (-2)*a" ,  ( 3 * b - a ) + ( -3*b - a ) , (-2)*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT(  "( a - 3 * b ) + ( a - c ) = 2*a-c-3*b" ,  ( a - 3 * b ) + ( a - c ) , 2*a-c-3*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT(  "( a - 3 * b ) + ( c - a ) = c-3*b" ,  ( a - 3 * b ) + ( c - a ) , c-3*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT(  "( a - 3 * b ) + ( c - 2*a ) = neg(a)+c-3*b",  ( a - 3 * b ) + ( c - 2*a ) , c-a-3*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT(  "( a - 3 * b ) + ( -3*b - a ) = (-6)*b" ,  ( a - 3 * b ) + ( -3*b - a ) , (-6)*b );

//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a + b ) - ( a + b )  = 2*a" ,  ( 3 * a + b ) - ( a + b )  , 2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a + b ) - ( b + a )  = 2*a" ,  ( 3 * a + b ) - ( b + a )  , 2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a + b ) - ( a + c )  = 2*a+b-c" ,  ( 3 * a + b ) - ( a + c )  , b+2*a-c );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a + b ) - ( c + a )  = 2*a+b-c" ,  ( 3 * a + b ) - ( c + a )  , b+2*a-c );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b + a ) - ( a + c )  = 3*b-c" ,  ( 3 * b + a ) - ( a + c )  , 3*b-c );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b + a ) - ( c + a )  = 3*b-c" ,  ( 3 * b + a ) - ( c + a )  , 3*b-c );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "(3 * a + 2 * b) - ( 2 * a + 7 *c )  = a+2*b-7*c" , (3 * a + 2 * b) - ( 2 * a + 7 *c )  , a+2*b-7*c );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a - b ) - ( a + b )  = 2*a-2*b" ,  ( 3 * a - b ) - ( a + b )  , 2*a-2*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a - b ) - ( b + a )  = 2*a-2*b" ,  ( 3 * a - b ) - ( b + a )  , 2*a-2*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a - b ) - ( a + c )  = 2*a-c-b" ,  ( 3 * a - b ) - ( a + c )  , 2*a-b-c );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a - b ) - ( c + a )  = 2*a-c-b" ,  ( 3 * a - b ) - ( c + a )  , 2*a-b-c );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b - a ) - ( a + c )  = 3*b-2*a-c" ,  ( 3 * b - a ) - ( a + c )  , 3*b-c-2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b - a ) - ( c + a )  = 3*b-2*a-c" ,  ( 3 * b - a ) - ( c + a )  , 3*b-c-2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a - 2*b ) - ( a + b )  = 2*a-3*b" ,  ( 3 * a - 2*b ) - ( a + b )  , 2*a-3*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a - 2*b ) - ( b + a )  = 2*a-3*b" ,  ( 3 * a - 2*b ) - ( b + a )  , 2*a-3*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a - b ) - ( a + c )  = 2*a-c-b" ,  ( 3 * a - b ) - ( a + c )  , 2*a-b-c );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * a - b ) - ( c + a )  = 2*a-c-b" ,  ( 3 * a - b ) - ( c + a )  , 2*a-b-c );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b - 3*a ) - ( a + c )  = 3*b-4*a-c" ,  ( 3 * b - 3*a ) - ( a + c )  , 3*b-c-4*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b - 2*a ) - ( c + a )  = 3*b-3*a-c" ,  ( 3 * b - 2*a ) - ( c + a )  , 3*b-c-3*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b + a ) - ( a - c )  = c+3*b" ,  ( 3 * b + a ) - ( a - c )  , c+3*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b + a ) - ( c - a )  = 2*a+3*b-c" ,  ( 3 * b + a ) - ( c - a )  , 2*a+3*b-c );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b + a ) - ( c - 2*a )  = 3*a+3*b-c" ,  ( 3 * b + a ) - ( c - 2*a )  , 3*b+3*a-c );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b + a ) - ( -3*b - a )  = 2*a+6*b" , ( 3 * b + a ) - ( -3*b - a ) , 2*a+6*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( a + 3 * b ) - ( a - c )  = c+3*b" ,  ( a + 3 * b ) - ( a - c )  , c+3*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( a + 3 * b ) - ( c - a )  = 2*a+3*b-c" ,  ( a + 3 * b ) - ( c - a )  , 3*b+2*a-c );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( a + 3 * b ) - ( c - 2*a )  = 3*a+3*b-c" , ( a + 3 * b ) - ( c - 2*a )  , 3*b+3*a-c );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( a + 3 * b ) - ( -3*b - a )  = 2*a+6*b" ,  ( a + 3 * b ) - ( -3*b - a )  , 2*a+6*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b - a ) - ( a - c )  = c+3*b-2*a" ,  ( 3 * b - a ) - ( a - c )  , c+3*b-2*a );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b - a ) - ( c - a )  = 3*b-c" ,  ( 3 * b - a ) - ( c - a )  , 3*b-c );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b - a ) - ( c - 2*a )  = a+3*b-c" ,  ( 3 * b - a ) - ( c - 2*a )  , a+3*b-c );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( 3 * b - a ) - ( -3*b - a )  = 6*b" ,  ( 3 * b - a ) - ( -3*b - a )  , 6*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( a - 3 * b ) - ( a - c )  = c-3*b" ,  ( a - 3 * b ) - ( a - c )  , c-3*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( a - 3 * b ) - ( c - a )  = 2*a-c-3*b" ,  ( a - 3 * b ) - ( c - a )  , 2*a-c-3*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( a - 3 * b ) - ( c - 2*a )  = 3*a-c-3*b" ,  ( a - 3 * b ) - ( c - 2*a )  , 3*a-c-3*b );
//    UNIT_TEST_CMP_STRING_WITH_TEXT( "( a - 3 * b ) - ( -3 * b - a )  = 2*a" ,  ( a - 3 * b ) - ( -3 * b - a )  , 2*a );
//    UNIT_TEST_CMP_STRING( ,  );
//    UNIT_TEST( true );
    return 0;
}



