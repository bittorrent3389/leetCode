#include <stdio.h>
#define max(a,b) (((a) > (b))? (a):(b))
#define min(a,b) (((a) < (b))? (a):(b))
int maxProduct(int* nums, int numsSize) {
	int localMax = nums[0], localMin = nums[0];
	int i, globalMax = nums[0];
	for ( i = 1 ; i < numsSize ; i++ ){
			int m = localMax;
			int n = localMin;
			localMin = min( min( m*nums[i], nums[i]), n*nums[i]);
			localMax = max( max( m*nums[i], nums[i]), n*nums[i]);
			printf("f[%d]:%d \n", i, localMax);
			printf("localMax:%d localMin:%d globalMax:%d ", 
					localMax, localMin, globalMax);
			printf("localMax*nums[%d]:%d \n", i, localMax*nums[i]);
			printf("localMin*nums[%d]:%d \n", i, localMax*nums[i]);
			globalMax = max( globalMax, localMax );
	}
	return globalMax;
}
void main(void) {
	int a[] = {-2};
	int i;
	puts("The target array : ");
	for ( i = 0 ; i < sizeof(a)/sizeof(a[0]); i++ )
		printf("%d ", a[i]);
	puts("");
	printf("maxProduct:%d \n", maxProduct(a, sizeof(a)/sizeof(a[0])));}
