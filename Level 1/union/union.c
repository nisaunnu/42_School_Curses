#include <unistd.h>

int check(char *str, char c, int n)
{
	int i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return 0;
		i++;
	}
	return 1;
}

int main(int ac, char **av)
{
	int i = 0;
	int j = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			if (check(av[1], av[1][i], i))
				write(1, &av[1][i], 1);
			i++;
		}
		while (av[2][j])
		{
			if (check(av[2], av[2][j], j) && check(av[1], av[2][j], i))
				write(1, &av[2][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
}
