#include <stdio.h>
#include <string.h>
void swap(char* a, char* b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
// Using GCC C extension : nested function
char* reverse( char* s ) {
	char* t = s;
	int c = 0;
	while(*t++) c++;
	//nested function : rev
	char* _reverse(char *s, int n) 
	{
		if (n >= 2) {
			swap( s, &s[n-1]);
			n -=2;
		return _reverse(++s, n);
		} else { return; }
	}	
	return _reverse(s,c);
}
void main() {
	char s[]= "abcde";
	reverse(s);
	puts(s);
}
