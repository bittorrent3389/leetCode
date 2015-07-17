#include <stdio.h>

int singleNumber(int a[],int n) {
	int ones = 0, twos = 0, threes =0;
	int i;
	for ( i = 0; i < n; i++ ) {
		twos |= ones & a[i];
		printf("a[%d] = %d \n", i, a[i]);
		printf("i:%d ones:%d twos:%d threes:%d \n",i,ones,twos,threes);
		ones ^= a[i];
		printf("i:%d ones:%d twos:%d threes:%d \n",i,ones,twos,threes);
		threes = ones & twos;
		printf("i:%d ones:%d twos:%d threes:%d \n",i,ones,twos,threes);
		ones &= ~threes;
		printf("i:%d ones:%d twos:%d threes:%d \n",i,ones,twos,threes);
		twos &= ~threes;
		printf("i:%d ones:%d twos:%d threes:%d \n",i,ones,twos,threes);
		puts("---------------------------------");
	}
	return ones;
}
void main(void) {
	int a[] = {4,3,3,3};
	printf("%d \n", singleNumber(a,sizeof(a)/sizeof(a[0])));
}
