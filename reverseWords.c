#include <stdio.h>
#include <string.h>
void reverse(char* start) {
	void _rev(char* s, char* t) {
		    --t;
			while (s < t) {
			    *s = *s ^ *t;
				*t = *s ^ *t;
				*s = *s ^ *t;
				s++;
				t--;											    
			}
	}
	void trim(char* s) {
		char *prev = s, *next = s, *leading = s, *trailing = s;
		int c = 0;
		// remove spaces between word.
		do
		  while (*next == ' ' && *(next+1) == ' ') next++;
		while (*prev++ = *next++);
		// remove leading spaces.
		if (*leading == ' ') while (*leading++ != '\0')  *(leading-1) = *leading;
		// remove trailing spaces.	
		while ( *trailing != '\0') trailing++;
		if (*(trailing-1) == ' ' ) *(trailing-1) = '\0';
	}
	trim(start);
	printf("After trim:\n%s.\n", start);
	printf("strlen(s):%ld\n", strlen(start));
	char* end = start;
	char* res = start;
	while ( *end++ != '\0' ) {
		if ( *end == ' ' || *end == '\0' ) { 
			_rev(start, end);
			start = end+1;		
		}
	}
	_rev(res, end-1 );
}
void main() {
	char s[] = "1 ";
	char *g = s;
	puts(s);
	printf("strlen(s):%ld\n", strlen(s));
	reverse(s);
	int i =0 ;
	while (*g) 
		printf("i:%d, %p, %c\n",i++ , g,*g++);
	printf("strlen(s):%ld\n", strlen(s));
	puts(s);
}
