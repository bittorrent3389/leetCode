#include <stdio.h>
// 1D Dynamic Progamming.
int maxSubarray( int *a, int size ) {
	int f[size];
	f[0] = a[0];
	int global=a[0], k;
	for ( k = 1; k < size; k++ ) {
		f[k] = ( a[k] > a[k]+ f[k-1] )? a[k]: a[k]+ f[k-1];
		global = ( f[k] > global )? f[k]:global;
	}
	return global;
}
void main(void) {
	int a[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	printf("%d \n", maxSubarray(a, sizeof(a)/sizeof(a[0])));
}
