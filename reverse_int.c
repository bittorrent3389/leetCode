#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TEST(n, e)  printf("%12d  =>  %-12d    %s!\n",  n, reverse(n),  e == reverse(n)?"passed":"failed")  
#define abs(x)  ( ( (x) < 0 ) ? -(x) : (x)  )
int reverse(int x) {
	int res = 0;
	while (x != 0) {
		// handle overflow/underflow
		if (abs(res) > INT_MAX/10)
			return 0;
		res = x%10 + res*10;
		x /=10;
	}
	return res;
}
void main(void) {

	printf("%d \n", reverse(123456));
}
