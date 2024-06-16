unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}
// DRUGI PRZYKLAD

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned int	i;
	unsigned char	res = 0;

	i = 8;
	while (i--)
	{

		res = (res << 1) | (octet & 1);
		
		octet = octet >> 1;
	}
	return (res);
}