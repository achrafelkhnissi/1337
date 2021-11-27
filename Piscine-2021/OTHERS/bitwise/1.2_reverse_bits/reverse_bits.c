/**********************************************************************
** 1.2 : Reversing bits on an octet (octet means 8 bits or 1 byte)
**********************************************************************/

/*
** This a vanilla question for interviews :
** Write a function that takes a byte, reverses it, bit by bit (like the
** example) and returns the result.
** 
** Your function must be declared as follows:
** 
** unsigned char	reverse_bits(unsigned char octet);
** 
** Example:
** 
**   1 byte
** _____________
**  0100  0001
**      ||
**      \/
**  1000  0010
*/

#include "../bitwise.h"

/**********************************************************************
** 1st Method, for mortals like us ;)
***********************************************************************
** 1) As a byte is equal to 8 it means we will do it while (byte_len--)
**
** 2) We first check if b as a bit on the extreme right with (b & 1);
** if so we light bit 1 on r and move it juste 1 bit on the left by
** multiplying r by 2 with (r << 1)
**
** For novices: r = (r << 1) | (b & 1) might be easier to understand as:
**
**		if (b % 2)           | (b & 1)
**			r = r + 1         
**		r *= 2;              (r << 1) 
**
** 3) Then we divide our unsigned char b by 2 to erase
** the bit located on the extreme right of the variable b.
** For reminder b >>= 1; is equivalent to b /= 2;
*/

unsigned char reverse_bits(unsigned char b)
{
	unsigned char	r = 0;
	unsigned		byte_len = 8;

	while (byte_len--)
	{
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return (r);
}

/**********************************************************************
** 2nd Method, swap bits 4 by 4, 2 by 2 and then 1 by 1
***********************************************************************
**
** 1) The first formula swaps 4 by 4 by applying masks:
** (b & 0xF0) >> 4 applies a mask to the higher 4 bits
** (0x0F = 1111 0000) then move them to the right.
** (b & 0x0F) << 4 applies a mask to the lowest 4 bits
** (0x0F = 0000 1111) then move them to the left.
**
** 2) Now swapthem  2 by 2: 0xCC = 1100 1100 and 0x33 = 0011 0011
**
** 3) Finally swap 1 by 1: 0xAA = 1010 1010 and 0x55 = 0101 0101
**
** if you had byte b equal to 0111 0100 ('t') it will gradually becomes:
** 1)   0100     0111 ('G') 
** 2)  00 01    11 01 (character 29, group separator, not a printable char) 
** 3) 0 0 1 0  1 1 1 0 = 0010 1110 ('.') 
*/

unsigned char reverse_bits2(unsigned char b)
{
	b = (b & 0xF0) >> 4 | (b & 0x0F) << 4; // 1)
	b = (b & 0xCC) >> 2 | (b & 0x33) << 2; // 2)
	b = (b & 0xAA) >> 1 | (b & 0x55) << 1; // 3)
	return (b);
}

/**********************************************************************
** 3rd Method, attributed to Rich Schroeppel in the Programming Hacks
** section http://www.inwap.com/pdp10/hbaker/hakmem/hakmem.html
***********************************************************************
**
** 1) The multiply operation (b * 0x0202020202ULL) creates five separate
** copies of the 8-bit byte pattern to fan-out into a 64-bit value.
**
** 2) The AND operation (& 0x010884422010ULL) selects the bits that are in the
** correct (reversed) positions, relative to each 10-bit groups of bits.
**
** 3) Together the multiply and the AND operations copy the bits from the original
** byte so they each appear in only one of the 10-bit sets.
** The reversed positions of the bits from the original byte coincide with their
** relative positions within any 10-bit set.
**
** 4) The last step (% 0x3ff), which involves modulus division by 2^10 - 1
** has the effect of merging together each set of 10 bits
** (from positions 0-9, 10-19, 20-29, ...) in the 64-bit value.
** They do not overlap, so the addition steps underlying the modulus
** division behave like OR operations.
*/

unsigned char reverse_bits3(unsigned char b)
{
	b = (b * 0x0202020202ULL & 0x010884422010ULL) % 0x3ff;
	return (b);
}

/*
** Test program : . (equal to 046 in ASCII table, 00101110 in binary)
** becomes t (116 in ASCII table, 01110100 in binary).
** byte 00101110 ('.') is indeed the reverse of byte 01110100 ('t').
*/

int	main(void)
{
	unsigned char c;

	c = '.';
	write(1, &c, 1);
	write(1, "\n", 1);
	c = reverse_bits(c);
	write(1, &c, 1);
	write(1, "\n", 1);
	c = reverse_bits2(c);
	write(1, &c, 1);
	write(1, "\n", 1);
	c = reverse_bits3(c);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (0);
}
