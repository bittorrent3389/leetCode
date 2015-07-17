#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int max( int a, int b ){
	return (a>b)? a:b;
}
void f(int m) {
	int b[m],i;
	for (i = 0; i < m ; i++) {
		b[i] = i;
		printf("b[i]:%d \n", b[i]);
	}	
}
void main() {	
	f(14);
	int a[] = { 1, 2, 3 };
	int* p;
	int b = INT_MAX;
	printf("QQ:%d \n", max(b, 4));
	p = a;
	p++;
	printf("MAX:%d \n", INT_MAX);
	printf("MIN:%d \n", INT_MIN);
}
