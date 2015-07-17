#include <stdio.h>
#include <stdlib.h>
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
	int m = matrixRowSize, n = matrixColSize;
	int i,index=0;
	int *a = (int*)malloc(m*n*sizeof(int));
	int row=0, col=-1;
	while(1) {
		for( i = 0; i < n; i++ ) 
			a[index++] = matrix[row][++col];
		if (--m == 0) break;
		for( i = 0; i < m ; i++ ) 
			a[index++] = matrix[++row][col];
		if (--n == 0) break;
		for( i = 0; i < n; i++ )
			a[index++] = matrix[row][--col];
		if (--m == 0) break;
		for( i = 0; i < m ; i++ )
			a[index++] = matrix[--row][col];
		if (--n == 0) break;
	}
	return a;
}
void main( void ) {
	int i,j;
	int m=3,n=3;
	int **arr = (int **) malloc(sizeof(int*)*m);
	for (i = 0; i < m; i++)
		arr[i] = (int *) malloc(sizeof(int)*n);
	int index=1;
	//initialize
	for( i =0 ; i < m ; i++ ) {
		for (j = 0 ; j < n ; j++) {
			arr[i][j] = index++;
		}
	}
	int* gg = spiralOrder(arr,m,n);
	for( i = 0 ; i < m*n ; i++ )
		printf("%d ", gg[i]);
	puts("");
	//free
	free(gg);
	for(i=0; i < m ; i++) 
		free(arr[i]);
	free(arr);
	
}

