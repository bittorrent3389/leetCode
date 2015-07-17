#include <stdio.h>
int singleNumber(int* nums, int numsSize) {
	   int count[32] = {0};
	   int i,j;
	   for (i = 0 ; i < 32; i++) {
		   for (j = 0; j < numsSize; j++) {
			   count[i] += (nums[j] >> i) & 1;
			   
		   }
	   }
	   puts("count[] : ");
	   for ( i = 0; i < 6; i++ )
		   printf("%d ", count[i]);
	   puts("");
	   int res=0;
	   for(i=0; i<32 ;i++)
		   res += ((count[i]%3)) << i;
	   return res;
}
void main(void){
	int a[] = { 1,1,2,3,3,3,2,2,4,1 } ;
	int i;
	for ( i =0;i<sizeof(a)/sizeof(a[0]);i++ )
		printf("%d ",a[i]);
	puts("");
	printf("%d \n", singleNumber(a,sizeof(a)/sizeof(a[0])));
}
