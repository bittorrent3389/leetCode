#include <stdio.h>
#define ROWS 10
#define COLS 10
int foo(int a[][COLS]) {
	printf("%d \n", a[0][0]);
}
void main(void) {
	int arr[10][10]={0};
	foo(arr);

}
