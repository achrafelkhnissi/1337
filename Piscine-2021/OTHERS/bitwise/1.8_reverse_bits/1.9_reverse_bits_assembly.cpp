#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>
#include <x86intrin.h>
// Compile with g++ -masm=intel a.cpp && ./a.out 

template <class T>
T reverse_bits(T n) {
	short bits = sizeof(n) * 8; 
	T mask = ~T(0); // equivalent to uint32_t mask = 0b11111111111111111111111111111111;

	while (bits >>= 1) {
		mask ^= mask << (bits); // will convert mask to 0b00000000000000001111111111111111;
		n = (n & ~mask) >> bits | (n & mask) << bits; // divide and conquer
	}

	return n;
}


unsigned char reverse_bits1(unsigned char c) {
	__asm__ __volatile__ (R"(
		or cx, 8       
	myloop:                   
		ror di          
		adc ax, ax      
		dec cx          
		jnz short myloop  
    ;)");
}

uint32_t reverse_bits2(uint32_t a) {
	__asm__ __volatile__ (R"(
      		mov ecx, 32
	loop2:
		shr edi
		rcl eax
		dec cl
		jnz short loop2
	;)");
}


uint32_t reverse_bits4(uint32_t n) {
//	uint32_t a = n;
// add .intel_syntax
 // mov     edi, DWORD PTR [rbp-8] 
	__asm__ __volatile__ (R"(
            bswap   edi
            mov     edx, edi
            shr     edi, 4
            sal     edx, 4
            and     edi, 252645135
            and     edx, -252645136
            or      edi, edx
            mov     edx, edi
            sal     edi, 2
            shr     edx, 2
            and     edi, -858993460
            and     edx, 858993459
            or      edx, edi
            mov     eax, edx
            add     edx, edx
            shr     eax
            and     edx, -1431655766
            and     eax, 1431655765
            or      eax, edx
	
        ;)");

	//mov     DWORD PTR [rbp-8], eax 
	//return a;
}


uint32_t reverse_bits5(uint32_t n) {
	uint32_t a = n;

	__asm__ __volatile__ (R"(
		xor eax, eax
		inc eax
	myloop3:
		shr edi, 1
		adc eax, eax
		jnc short myloop3
        ;)");
}


	template <class T>
void print_binary(T n)
{	T mask = 1UL << ((sizeof(n) * 8) - 1);  // will set the most significant bit
	for(; mask != 0; mask >>= 1) putchar('0' + !!(n & mask));
	putchar('\n');
}

int main() {
	unsigned int n = 12534534U | 1U << 31;

	print_binary(n);
	unsigned int o = reverse_bits5(n);
	print_binary(o);
	n = reverse_bits(n);
	print_binary(n);

	/*
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
	   print_binary(l);*/
	return 0;
}
