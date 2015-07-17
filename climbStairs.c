#include <stdio.h>

int climbStairs(int n) {
	/*
	if ( n <= 2 ) return n;
	else return climbStairs(n-1) + climbStairs(n-2);
	*/
	int z, k, i = 0, j = 1;
	for (z=0; z < n; z++) {
		k = i + j;
		i = j;
		j = k;
	}
	return k;
}

void main(void) {
	int q;
	for ( q = 1; q <= 14; q++ )
		printf("%d ", climbStairs(q));
	puts("");
}
