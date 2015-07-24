#include <stdio.h>
#include <string.h>
void trim(char *s) {
    char *p1 = s, *p2 = s;
    do {
      while (*p2 == ' ' && *(p2+1) == ' ')  p2++;  
	} while (*p1++ = *p2++);
}
void main(){
	char s[] = "e abcd g";
	puts(s);
	trim(s);
	puts(s);
}
