#include <unistd.h>

void	write_last(char *start, char *end)
{
	while (start < end)
	{
		write(1, start, 1);
		start++;
	}
}

int	main(int argc, char **argv)
{
	char	*start_word;
	char	*end_word;
	char	*str;

	if (argc > 1)
	{
		str = argv[1];
		while (*str == ' ' || *str == '\t')
			str++;
		start_word = str;
		while (*str && *str != ' ' && *str != '\t')
			str++;
		end_word = str;
		while (*str == ' ' || *str == '\t')
			str++;
		if (*str)
		{
			while (*str)
			{
				if (*str == ' ' || *str == '\t')
				{
					while (*(str + 1) == ' ' || *(str + 1) == '\t')
						str++;
					write(1, " ", 1);
				}
				else
					write(1, str, 1);
				str++;
			}
			write(1, " ", 1);
		}
		write_last(start_word, end_word);
	}
	write(1, "\n", 1);
}
