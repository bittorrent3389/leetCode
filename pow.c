#include <stdio.h>
double myPow(double x, int n) {
	if ( n == 0 ) return 1;
	if ( n < 0 ) {
		n = -n;
		x = 1/x;
	}
	double res = myPow(x,n/2);
	return (n&1)? x*res*res:res*res;
}
void main( void ){
	printf("%f \n", myPow(0.44528,0));
}

