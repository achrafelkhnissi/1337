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

unsigned char rev_bits1(unsigned char b)
{
	unsigned char	r = 0;
	unsigned	byte_len = 8;

	while (byte_len--)
	{
		r = (r << 1) | (b & 1);
		b >>= 1;
	}
	return (r);
}
