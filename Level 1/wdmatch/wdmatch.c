#include <unistd.h>

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

void putstr(char *s)
{
	int i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	int len = 0;
	int i = 0;
	int j = 0;
	int count = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			while (av[2][j])
			{
				if (av[1][i] == av[2][j])
				{
					count++;
					break;
				}
				j++;
			}
			i++;
		}
		len = ft_strlen(av[1]);
		if (len == count)
			putstr(av[1]);
	}
	write(1, "\n", 1);
}
