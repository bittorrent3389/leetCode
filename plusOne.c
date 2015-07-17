#include <stdio.h>
#include <stdlib.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int *a = (int*) malloc(sizeof(int)*(digitsSize+1)); //999+1=1000
	
	int i, carry=1, sum=0;
	for ( i = digitsSize; i>=0 ;i--) {
		if(carry == 0) {
	        *returnSize = digitsSize;
			return a;							    
		}
		sum	= carry + digits[i-1];
		carry = sum / 10;
		printf ("In for Loop:%d, carry:%d \n", sum, carry);
		a[digitsSize-i] = sum % 10;
	}
	a[digitsSize-1] = carry;
	*returnSize = ++digitsSize;
	return a;

}
void main(void) {
	int a[]	= {4};
	int *p,q=0;
	p = &q;
	int* gg = plusOne(a,1,p);
	int i;
	for( i =0; i < *p ; i++ )
		printf("%d, size:%d \n", gg[i],*p);

}



