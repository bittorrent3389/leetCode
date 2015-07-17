#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for strlen
void myStrcpy(char *s, char *t){
	while(*s++ = *t++);
}
void main(void) {
	char *t="Hello World";
	char *s = (char*)malloc(strlen(t)+1);
	printf("%zd\n", sizeof(t));    // pointer size
	printf("%zu\n", strlen(t)+1);  // array size
	while(*s++ = *t++);
//	myStrcpy(s,t);
	s-=12;
	puts(s);
	printf("%s \n", s);
	printf("%c \n", *(s+10));

}

