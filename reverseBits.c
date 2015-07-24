#include <stdio.h>
#include <stdint.h>
void print_binary(uint32_t number) {
	if (number) {
		print_binary(number >>1);
		putc((number & 1)? '1':'0', stdout);
	}
}
uint32_t revBit(uint32_t n) {
	int i;
	uint32_t m=0;
	for (i = 0; i<32; i++) {
		m = m << 1 | (n & 1);
		n >>= 1;
	}
	return m;
}
void main() {
	uint32_t n = 8;
	print_binary(revBit(n));
	puts("");
	print_binary(n);
	puts("");
}
