## Purpose
I created these files as a way to better understand bitwise operators and practical use
When developers are challenged by memory limitation or have high speed requirement as for
embedded systems (FR : systemes embarques) like drones, bitwise operators come in handy.

* 1.0 Introduction to <a href ="https://github.com/agavrel/42-Bitwise_Operators/blob/master/1.0_introduction.c">Bitwises operators.</a>
* 1.1 Learn how to <a href ="https://github.com/agavrel/42-Bitwise_Operators/blob/master/1.1_printing_bits.c">print (display) bits.</a>
* 1.2 Learn how to <a href ="https://github.com/agavrel/42-Bitwise_Operators/blob/master/1.2_reverse_bits.c">reverse a byte.</a>
* 1.3 Check if <a href ="https://github.com/agavrel/42-Bitwise_Operators/blob/master/1.3_is_power_of_2.c">a number is power of 2 or not.</a>
* 1.4 Learn how to use bitwise operators to <a href ="https://github.com/agavrel/42-Projects/blob/master/ft_ls/srcs/parsing.c">save memory when parsing.</a>
* 1.5 Learn <a href ="https://github.com/agavrel/42-Bitwise_Operators/blob/master/1.5_clear_all_bits.c">how to clear all bits.</a>
* 1.6 Check <a href ="https://github.com/agavrel/42-Bitwise_Operators/blob/master/1.6_binary_gap.c">the binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.</a>
* 1.7 Learn <a href ="https://github.com/agavrel/42-Bitwise_Operators/blob/master/1.7_align_size.c">how use bit shifts and bit mask to align the size of a given number.</a>

### Reverse bits inside Byte(s)

*There are many ways to reverse bits depending on what you mean the "simplest way".*

---
### Reverse by Rotation
Probably the most logical, consists in rotating the byte while applying a mask on the first bit ```(n & 1)```:
```c++
unsigned char reverse_bits(unsigned char b)
{
	unsigned char	r = 0;
	unsigned		byte_len = 8;

	while (byte_len--) {
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return r;
}
```

1) As the length of an unsigner char is 1 byte, which is equal to 8 bits, it means we will scan each bit ```while (byte_len--)```

2) We first check if b as a bit on the extreme right with ```(b & 1)```;
if so we set bit 1 on r with ```|``` and move it just 1 bit to the left by
multiplying r by 2 with ```(r << 1)```

3) Then we divide our unsigned char b by 2 with ```b >>=1``` to erase
the bit located at the extreme right of variable b.
As a reminder, b >>= 1; is equivalent to b /= 2;

---
### Reverse in One Line

This solution is attributed to [Rich Schroeppel in the Programming Hacks section](http://www.inwap.com/pdp10/hbaker/hakmem/hakmem.html)

```c++
unsigned char reverse_bits3(unsigned char b)
{
	return (b * 0x0202020202ULL & 0x010884422010ULL) % 0x3ff;
}
```

1) The multiply operation (b * 0x0202020202ULL) creates five separate copies of the 8-bit byte pattern to fan-out into a 64-bit value.

2) The AND operation (& 0x010884422010ULL) selects the bits that are in the
correct (reversed) positions, relative to each 10-bit groups of bits.

3) Together the multiply and the AND operations copy the bits from the original
byte so they each appear in only one of the 10-bit sets.
The reversed positions of the bits from the original byte coincide with their
relative positions within any 10-bit set.

4) The last step (% 0x3ff), which involves modulus division by 2^10 - 1
has the effect of merging together each set of 10 bits
(from positions 0-9, 10-19, 20-29, ...) in the 64-bit value.
They do not overlap, so the addition steps underlying the modulus
division behave like OR operations.

---
### Divide and Conquer Solution

```c++
unsigned char reverse(unsigned char b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return b;
}
```
This is the most upvoted answer and despite some explanations, I think that for most people it feels difficult to visualize whats 0xF0, 0xCC, 0xAA, 0x0F, 0x33 and 0x55 truly means.  

It does not take advantage of '0b' which is a [GCC extension](https://gcc.gnu.org/onlinedocs/gcc/Binary-constants.html) and is included since the C++14 standard, release in December 2014, so a while after this answer dating from April 2010

> Integer constants can be written as binary constants, consisting of a sequence of ‘0’ and ‘1’ digits, prefixed by ‘0b’ or ‘0B’. This is particularly useful in environments that operate a lot on the bit level (like microcontrollers).

Please check below code snippets to remember and understand even better this solution where we move half by half:


```c++
unsigned char reverse(unsigned char b) {
   b = (b & 0b11110000) >> 4 | (b & 0b00001111) << 4;
   b = (b & 0b11001100) >> 2 | (b & 0b00110011) << 2;
   b = (b & 0b10101010) >> 1 | (b & 0b01010101) << 1;
   return b;
}
```

NB: The ```>> 4``` is because there are 8 bits in 1 byte, which is an unsigned char so we want to take the other half, and so on.

We could easily apply this solution to 4 bytes with only two additional lines and following the same logic. Since both mask complement each other we can even use ~ in order to switch bits and saving some ink:

```c++
uint32_t reverse_integer_bits(uint32_t b) {
   uint32_t mask = 0b11111111111111110000000000000000;
   b = (b & mask) >> 16 | (b & ~mask) << 16;
   mask = 0b11111111000000001111111100000000;
   b = (b & mask) >> 8 | (b & ~mask) << 8;
   mask = 0b11110000111100001111000011110000;
   b = (b & mask) >> 4 | (b & ~mask) << 4;
   mask = 0b11001100110011001100110011001100;
   b = (b & mask) >> 2 | (b & ~mask) << 2;
   mask = 0b10101010101010101010101010101010;
   b = (b & mask) >> 1 | (b & ~mask) << 1;
   return b;
}
```

---
### [C++ Only] Reverse Any Unsigned ! (Template)

The above logic can be summarized with a loop that would work on any type of unsigned:
```c++
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
```

Try it yourself with inclusion of above function:
```c++
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

template <class T>
void print_binary(T n)
{	T mask = 1ULL << ((sizeof(n) * 8) - 1);  // will set the most significant bit
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
```

---
### Bonus, Assembly code, refer to 1.9
```asm
	mov cx, 8           ; we will reverse the 8 bits contained in one byte
loop:                   ; while loop
	ror di              ; rotate `di` (containing value of the first argument of callee function) to the Right in a non-destructive manner
	adc ax, ax          ; shift `ax` left and add the carry, the carry is equal to 1 if one bit was rotated from 0b1 to MSB from previous operation
	dec cx              ; Decrement cx
	jnz short loop      ; Jump if cx register Not equal to Zero else end loop and return ax
```

## Contact & contribute
To contact me and helping me to (fix bugs || improve) 42-Bitwises_Operators, feel free to e-mail me at **angavrel at student dot 42 dot fr**
