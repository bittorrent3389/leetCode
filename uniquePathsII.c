#include <stdio.h>
#include <stdlib.h>
int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
   int a[obstacleGridRowSize][obstacleGridColSize];
   int i,j;
   a[0][0] = (obstacleGrid[0][0])? 0:1;
   
	for ( i = 1; i < obstacleGridRowSize; i++ ) {
	        a[i][0] = (obstacleGrid[i][0])? 0:a[i-1][0];
				    
	}
	for ( j = 1; j < obstacleGridColSize; j++ ) {
	        a[0][j] = (obstacleGrid[0][j])? 0:a[0][j-1];
					    
	}
	for ( i = 1; i < obstacleGridRowSize; i++ ) {
			for ( j = 1; j < obstacleGridColSize; j++ ) {
	            a[i][j] = (obstacleGrid[i][j])? 0:a[i-1][j]+a[i][j-1];					}	    
	}
    return a[obstacleGridRowSize-1][obstacleGridColSize-1];
}
void main(void) {
	int **a,rows=2,cols=2, i;
	a = (int **)malloc(rows*sizeof(int*));
	for ( i = 0 ; i < rows ; i++ )
		a[i] = (int*)malloc(cols*sizeof(int));
	a[0][0]=0; a[0][1]=0;
	a[1][0]=1; a[1][1]=0;
	printf("%d \n", uniquePathsWithObstacles(a,2,2));
}

