unsigned char rev_bits3(unsigned char b)
{
	b = (b * 0x0202020202ULL & 0x010884422010ULL) % 0x3ff;
return (b);
}
