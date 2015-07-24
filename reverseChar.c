#include <stdio.h>
//#define swap(a,b) ( a^=b^=a^=b )
void swap (char* a, char* b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
void reverse(char* s){
	int i, count = 0;
	puts(s);
	char* t = s;
	while(*t++) count++;
	for( i = 0; i < count/2 ; i++ )
		swap( &s[i], &s[count-i-1] );
}
void main (void) {
	char s[] = "abcd";
	reverse(s);
	puts(s);
}
