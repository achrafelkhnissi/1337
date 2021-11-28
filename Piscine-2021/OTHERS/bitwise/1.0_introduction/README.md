# 1.0: Introduction to bitwise operators

- NB: an integer contains 4 bytes, as one byte = 8 bits it means that an integer is equivalent to 32 bits.
- octet and byte means the same thing.
- an unsigned char has only 1 byte (8 bits).
- Now what is a bit ? It is simple, a bit is either true or false, equal to 1 or to 0. Binary is same as our decimal system except base is 2 instead of 10: 1 will be 1 but 10 will be 2 and 11 will be 3.
- to illustrate better this system take a glance at the table below:

```
 base 10 <=> base 2
 1 <=>  1     4 <=>  100
 2 <=> 10     5 <=>  101      and so on...
 3 <=> 11     6 <=>  110

```

- Read more : https://en.wikipedia.org/wiki/Bit

----

#### Now our program to understand bitwise operators (following explanations)

1. We set out integer to 3 `00000000 00000000 00000000 00000011` and our `unsigned char` to `46` -> `00101110`
2. LEFT SHIFT `<<`: `byte = byte << 1`;
	- equivalent to `byte * 2`.
	- `0011` will slide to the left to become `0110`
	- In the example `0011` (3) becomes `0110` (6)
3. RIGHT SHIFT `>>`: `byte = byte >> 1`;
	- byte now divided by 2
	- with the modulo being lost forever
	- If we had 7 it will become 3.
4. Bitwise __AND__ operator `&`: We now use a mask `&` with 1
	- `&= 1` is equivalent to `%= 2`
	- Hence we will check if the value is odd.
5. Bitwise __OR__ operator `|`: `nb |= 1`
	- We add 1 to the `nb` if it was even (multiple of 2)
	- If it was already odd nothing will change.
6. Bitwise __AND__ operator `&` with clearing `~`: `nb &~ 1`
	- We substract 1 to the number if it was odd
	- If it was already even, nothing will change
7. Bitwise __EXCLUSIVE OR__ operator `^`:
	- Compares each bit of its first operand to the corresponding bit of its second operand.
	- If on bit is `0` and the other bit is `0`, the corresponding result bit is set to `1`.
	- Otherwise, the corresponding result bit is set to `0`
	- In short: It will become `1` is bits are opposite and `0` if is not.
	```
	  10101110
	^
	  11010000
	= 
	  11111110
	```
	
