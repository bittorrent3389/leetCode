#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for strlen
void myStrcpy(char *s, char *t){
	while(*s++ = *t++);
}
void main(void) {
	char *t="Hello World";
	char g[] = "Hello World";
	char *s = (char*)malloc(strlen(t)+1);
	printf("%zd\n", sizeof(t));    // pointer size
	printf("strlen(t)+1 %zu\n", strlen(t)+1);  // array size
	printf("strlen(g)+1 %zu\n", strlen(g)+1);
	while(*s++ = *t++);
//	myStrcpy(s,t);
	s-=12;
	puts(s);
	puts(g);
	printf("%s \n", s);
	printf("%c \n", *(s+10));

}

