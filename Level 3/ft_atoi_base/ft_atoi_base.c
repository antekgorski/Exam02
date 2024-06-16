// char	to_lower(char c)
// {
// 	if (c >= 'A' && c <= 'Z')
// 		return (c + ('a' - 'A'));
// 	return (c);
// }

// int get_digit(char c, int digits_in_base)
// {
// 	int max_digit;
// 	if (digits_in_base <= 10)
// 		max_digit = digits_in_base + '0';
// 	else
// 		max_digit = digits_in_base - 10 + 'a';
// 	if (c >= '0' && c <= '9' && c <= max_digit)
// 		return (c - '0');
// 	else if (c >= 'a' && c <= 'f' && c <= max_digit)
// 		return (10 + c - 'a');
// 	else
// 		return (-1);
// }

// int ft_atoi_base(const char *str, int str_base)
// {
// 	int result = 0;
// 	int sign = 1;
// 	int digit;

// 	if (*str == '-')
// 	{
// 		sign = -1;
// 		++str;
// 	}

// 	while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
// 	{
// 		result = result * str_base;
// 		result = result + (digit * sign);
// 		++str;
// 	}
// 	return (result);
// }



int		ft_atoi_base(const char *str, int str_base)
{
	int i;
	int n;
	int len;
	int result;

	i = 0;
	n = 1;
	result = 0;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		result *= str_base;
		if (str[i] >= '0' && str[i] <= '9')
			result += str[i] - 48;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			result += str[i] - 55;
		else if (str[i] >= 'a' && str[i] <= 'z')
			result += str[i] - 87;
		i++;
	}
	return (result * n);
}