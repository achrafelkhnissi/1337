unsigned char   reverse_bits(unsigned char octet)
{
	unsigned char rev;
	int	bits;

	bits = 0;
	rev = 0;
	while (bits < 8)
	{
		rev = (rev << 1) | (octet & 1);
		octet >>= 1;
		bits++;
	}
	return (rev);
}
