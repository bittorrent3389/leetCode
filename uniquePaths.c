#include <stdio.h>
int _uniquePaths(int m, int n) {
//	printf("m:%d n:%d \n", m, n);
	if ( n == 0 || m == n )
		return 1;
	return _uniquePaths(m-1, n-1) + _uniquePaths(m-1, n);
}
int __uniquePaths(int m, int n) {
    m = m + n - 2;
    n--;
    return _uniquePaths(m,n);
}
int uniquePaths(int m, int n) {
	int a[m][n];
	int i,j;
	for (i = 0; i < m; i++) 
		a[i][0] = 1;
	for (j = 0; j < n; j++)
		a[0][j] = 1;
	for (i = 1; i < m; i++) {
		for(j = 1; j < n; j++) {
			a[i][j]	= a[i-1][j] + a[i][j-1];
		}	
	}
	return a[m-1][n-1];
}

void main(void) {
	printf("uniquePaths: %d \n", uniquePaths(7,4));
	printf("_uniquePaths: %d \n", __uniquePaths(7,4));

}
