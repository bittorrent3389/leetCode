#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    while(--numsSize != 0) {
		printf("%d \n", numsSize);
        nums[numsSize-1] ^= nums[numsSize];
	}
    return nums[0];
}
void main (void) {
	int a[] = {3,3,4,4,1};
	printf("%d \n", singleNumber(a,5));
}
