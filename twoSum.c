#include <stdio.h>
#include <stdlib.h> //include malloc()
#include <assert.h>
//Before BinarySearch, the data should be sorted.
int BinarySearch(int a[], int find, int low, int upper) {
		printf("low = %d, upper = %d, find = %d\n",low, upper, find);
				while (low <= upper) {
					int mid = (low + upper) >> 1;
					if ( a[mid] > find  )
						upper = mid - 1; 
					else if ( a[mid] < find )															
						low = mid + 1; 
					else
						return mid; 
				}
				printf("find = %d not found.\n", find);
				return -1;
}
int comp( const void *p, const void *q  ) {
	    return (*(int*)p - *(int*)q);
}
int* twoSum(int* nums, int numsSize, int target) {
		printf("numsSize : %d\n", numsSize);
	    int i, j, k;
		int *ptr = (int*)malloc(sizeof(int)*2);
		int *backup = (int*)malloc(numsSize*sizeof(int));
		while( i != numsSize ){
			backup[i] = nums[i];
			i++;
		}
        for (i = 0; i < numsSize ; i++)
            printf("backup = %d ", backup[i]);
        printf("\n");
		qsort(nums, numsSize, sizeof(int), comp);
		for (i = 0; i < numsSize ; i++)
			printf("nums = %d ", nums[i]);
		printf("\n");
        for(i=0 ; i < numsSize ; i++ ){
			printf("target - nums[%d] = %d - %d = %d\n"
					, i, target, nums[i],target - nums[i]);
		j = BinarySearch(nums ,target - nums[i], i + 1, numsSize-1);
			if ( nums[j] == target - nums[i]) {
				printf("found\n");
				assert(nums[i]+nums[j] == target);
				break;
			}
		}
		for ( k = 0; k < numsSize; k++  ){
	        if( backup[k] == nums[i]  )
	            ptr[0]=k;
		}
		for ( k = 0; k< numsSize; k++ ) {
	        if( backup[k] == nums[j] && k != ptr[0] )
	            ptr[1]=k;					                
		}
		int temp;
		if ( ptr[0] > ptr[1]  ) {
		   temp = ptr[1];
		   ptr[1] = ptr[0];
		   ptr[0] = temp;							    
		}
		ptr[0]++;
		ptr[1]++;
		printf("index1 = %d, index2 = %d \n", ptr[0], ptr[1]);
		printf("Finally, backup[ptr[0]] + backup[ptr[1]] = %d \n", backup[ptr[0]-1] + backup[ptr[1]-1]);
		//assert(target == backup[ptr[0]] + backup[ptr[1]]);
		return ptr;
}
int main(void) {
		int arr[] = {217,231,523,52,547,243,648,509,415,149,689,710,265,187,370,56,977,182,400,329,471,805,955,989,255,766,38,566,79,843,295,229,988,108,781,619,704,542,335,307,359,907,727,959,161,699,123,650,147,459,657,188,304,268,405,685,620,721,351,570,899,60,388,771,24,659,425,440,508,373,32,645,409,272,356,175,533,740,370,152,34,510,745,251,227,494,258,527,817,773,178,194,860,387,627,851,449,736,15,212,529,950,316,28,65,484,968,63,4,643,795,669,203,677,139,636,289,555,430,849,150,493,301,377,240,873,965,441,230,349,447,470};
		printf("arr size : %lu\n", sizeof(arr)/sizeof(*arr));
		int *ggla = (int*)malloc(sizeof(int)*2);
		ggla = (int*)twoSum(arr, sizeof(arr)/sizeof(*arr), 718);
		return 0;
}



