#include <stdio.h>
#include <limits.h>
int maxSubArray(int* nums, int numsSize) {
	if ( numsSize == 1 )
		return nums[0];
	int sum=0, leftSum = INT_MIN, rightSum = INT_MIN, mid,i;
	mid = numsSize / 2;
	int leftAns   = maxSubArray(nums, mid);
	int rightAns  = maxSubArray(nums+mid, numsSize - mid);
	for ( i = mid; i < numsSize; i++  ) {
	        sum += nums[i];
	        rightSum = ( rightSum > sum  )? rightSum:sum;					    
	}
	sum = 0;
	for ( i = mid-1; i >= 0 ; i-- ) {
		sum += nums[i];
		leftSum = ( leftSum > sum )? leftSum:sum;
	}
	int ans = (leftAns > rightAns)? leftAns:rightAns;
	return (ans > (leftSum + rightSum))? ans:(leftSum+rightSum);	
}		
void main (void) {
	int a[] = {6,-4,7,-4,0,1};
	printf("%d \n", maxSubArray(a,sizeof(a)/sizeof(a[0])));
}
