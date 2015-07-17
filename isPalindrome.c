#include <stdio.h>
#include <stdlib.h>
int isPalindrome(int x) {
	if ( x<0 ) return 0;
	long res = 0;
	long tmp = x;
	while (x!=0) {
		res = x%10 + res*10;
		x/=10;		
	}	
	printf("res:%ld \n",res);
	printf("tmp:%ld \n",tmp);
	return res == tmp;
}
void main(void) {
	printf("result : %d \n", isPalindrome(0));
}
