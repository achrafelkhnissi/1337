# Reversing bits on an octet (octet means 8 bits or 1 byte)

### 1st method 

```c
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

### 2nd Method: swap bits 4 by 4, 2 by 2 and then 1 by 1

```c
unsigned char reverse(unsigned char b) {
   b = (b & 0b11110000) >> 4 | (b & 0b00001111) << 4;
   b = (b & 0b11001100) >> 2 | (b & 0b00110011) << 2;
   b = (b & 0b10101010) >> 1 | (b & 0b01010101) << 1;
   return b;
}
```

