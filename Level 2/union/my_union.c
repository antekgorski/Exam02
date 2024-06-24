#include <unistd.h>

int	check(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	spr(char *str1, char *str2)
{
	char	spr[256] = {0};
	int		i;

	i = 0;
	while (*str1)
	{
		if (!check(spr, *str1))
		{
			spr[i] = *str1;
			write(1, &spr[i], 1);
            i++;
		}
		str1++;
	}

    	while (*str2)
	{
		if (!check(spr, *str2))
		{
			spr[i] = *str2;
			write(1, &spr[i], 1);
            i++;
		}
		str2++;
	}

}


int	main(int argc, char **argv)
{
	if (argc == 3)
		spr(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
