## Exericse

```
======================================./2-4-print_bits.txt=========================================
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
---------------------------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"
===================================================================================================
```

### Algorithm

- First we got through each bit of a byte which is 8 bits.
- we check if the result of (byte & 128)
	- if 1 we return '1'.
	- if 0 we return '0'.
- Then we left shift that byte by 1.
- And go to the next bit.
- Finally we print a new line.
