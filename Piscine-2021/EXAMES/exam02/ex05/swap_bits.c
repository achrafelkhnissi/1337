unsigned char   swap_bits(unsigned char octet)
{
	octet = (octet & 0b11110000) >> 4 | (octet & 0b00001111) << 4;
	return (octet);
}

