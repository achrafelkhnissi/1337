## Exercise

```
======================================./2-0-swap_bits.txt=========================================
Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
==================================================================================================
```

## Algorithm

- First we shift the result of (octet & 0b11110000) to the left by 4
	```
		0100 0001		
	  &			
		1111 0000		0100 0000 >> 4
		---------	->	---------
		0100 0000		0000 0100
	```
- Then we shift the result of (octet & 0b0000111) to the right by 4
	```
		0100 0001		
	  &		
		0000 1111		0000 0001 << 4
		---------	->	---------
		0000 0001		0001 0000
	```
- Then we combing the result of the two using AND operator (|)
	```
		0000 0100		
	  |
		0001 0000
		---------
		0001 0100
	```
- Finally we assign the result of "octet" and return it.


