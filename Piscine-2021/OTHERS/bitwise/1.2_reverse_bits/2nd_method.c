unsigned char rev_bits2(unsigned char b)
{
	b = (b & 0xF0) >> 4 | (b & 0x0F) << 4; // 1)
	b = (b & 0xCC) >> 2 | (b & 0x33) << 2; // 2)
	b = (b & 0xAA) >> 1 | (b & 0x55) << 1; // 3)
	return (b);
}

/*
unsigned char reverse(unsigned char b) 
{
	b = (b & 0b11110000) >> 4 | (b & 0b00001111) << 4;
	b = (b & 0b11001100) >> 2 | (b & 0b00110011) << 2;
	b = (b & 0b10101010) >> 1 | (b & 0b01010101) << 1;
	return b;
}
*/
