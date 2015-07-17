#include <stdio.h>
long _sqrt(long x){
	//Find x^(1/2) in [0, x/2+1]
	long l = 0, r = x/2+1;
	long mid, t;
	while(l <= r) {
		mid = (l+r)/2;
		t = mid * mid;
	//	printf("l:%ld, r:%ld, x:%ld, t:%ld\n", l, r, x, t);
		if ( x > t )
			l = mid + 1;
		else if ( x < t )
			r = mid - 1;
		else
			return mid;
	}
	return r;
}
void main(void){
	long i;
	for ( i = 0 ; i < 26; i++ ) 
		printf("i:%ld sqrt(i):%ld \n",i , _sqrt(i));
}
