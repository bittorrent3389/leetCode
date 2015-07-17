#include <stdio.h>
#include <stdlib.h> //for malloc

int foo( int **a, int x, int y ) {
	int i,j;
	for ( i = 0 ; i < y ; i++ ) {
		for( j = 0 ; j < x ; j++ )
			printf("a[%d][%d]:%d \n", x,y,a[i][j]);
	}
	return a[1][1];
}

void main(void) {
	int x = 2;
	int y = 2;
	int **matrix = (int**)malloc(y*sizeof(int*));
	int i;
	for( i =0 ; i < y ; i++ ) {
		matrix[i] = (int*)malloc(x*sizeof(int));
	}
	matrix[0][0]=0;
	matrix[0][1]=1;
	matrix[1][1]=0;
	matrix[1][0]=0;
	printf("%d \n", foo(matrix,x,y));
}
