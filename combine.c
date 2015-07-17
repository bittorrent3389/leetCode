#include <stdio.h>
long combine (long m, long n) {
	long i,sum=1;
	for (i = 0; i < n; i++, m--)
		sum *= m;
	while(n != 0) 
		sum /= n--;
	return sum;
}
void main(void) {
	printf("%ld \n", combine(23+12-2,12-1));
}
