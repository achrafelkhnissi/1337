## Exercise

```
======================================./2-0-reverse_bits.txt=========================================
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
-----------------------------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
=====================================================================================================
```

### Solution

#### Simple Explanation
1. We check the first bit of 'b' is 1 with `b & 1`;
	- if so we set the first bit of 'rev' to 1 with `|`
	- And shift it to the left with `rev << 1` to make room for the next.
2. Then we shift 'b' to the right with `b >> 1` to erase the previously checked first bit.
3. Repeat the process 8 times which is the number of bits in 1 byte.

#### Detailed Explanation
1. First we create an empty `char` "rev" with 0 `0000 0000` 
2. Then we check the first bit in the input "byte"
	- `rev = (rev << 1) | (byte & 1)`
	- The first half `rev << 1` is to make room to the new 'bit' by shifting the variable's bits (the first bit will always be 0 by shifting to the left by 1).
	- The second half `b & 1` is the check the first bit of "byte" if it's 1 or 0, We can achieve that with `& 1` since the first bit of 1 is 1 and the rest is 0. If the first bit of byte is 1 the return value is 1 otherwise it returns 0. 
	- Finally we assign the result of the first half __OR__ second half, because the second half is either 1 or 0. Only the first bit of the first half can be changed with `|`.. the rest will remain unchanged.
3. We shift the bits of bits to the right `byte >>= 1` so we can get rid of the first bit that we already checked in step(2).
4. We repeat the process 8 times.. Which is the number of bits in a byte.
