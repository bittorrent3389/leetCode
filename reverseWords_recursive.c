#include <stdio.h>
void reverseWords(char *s) {
	char* _rev(char *s) {
		char* t = s;
		while ( *t != '\0' && *t !=' ') t++;
		if (*t == '\0') {
			printf("%s ",s);
			*--s = '\0';
			return NULL;
		} else {
			_rev(++t);
			printf("%s ",s);
			*--s = '\0';
	   	}
	}	
	_rev(s);
	puts("");
}

void main () {
	char s[] = "the sky is blue";
	puts(s);
	reverseWords(s);
}
