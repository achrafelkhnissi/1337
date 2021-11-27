#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

template <class T>
T reverse_bits(T n) {
	short bits = sizeof(n) * 8;
	T mask = ~T(0); // equivalent to uint32_t mask = 0b11111111111111111111111111111111;
	
	while (bits >>= 1) {
		mask ^= mask << (bits); // will convert mask to 0b00000000000000001111111111111111;
		n = (n & ~mask) >> bits | (n & mask) << bits; // we need ~mask for the upper part and mask for the lower part
	}

	return n;
}

template <class T>
void print_binary(T n)
{	
	T mask = 1UL << ((sizeof(n) * 8) - 1);  // will set the most significant bit
	for(; mask != 0; mask >>= 1) putchar('0' | !!(n & mask));
	putchar('\n');
}

int main() {
	uint32_t n = 12;
	print_binary(n);
	n = reverse_bits(n); 
	print_binary(n);
	unsigned char c = 'a';
	print_binary(c);
	c = reverse_bits(c);
	print_binary(c);
	uint16_t s = 12;
	print_binary(s);
	s = reverse_bits(s);
	print_binary(s);
	uint64_t l = 12;
	print_binary(l);
	l = reverse_bits(l);
	print_binary(l);

	return 0;
}
