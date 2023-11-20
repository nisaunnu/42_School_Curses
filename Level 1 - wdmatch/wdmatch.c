#include <unistd.h>

void ft_putstr(char *s)
{
	while(*s)
	{
		write(1, s, 1);
		s++;
	}
}

int main(int ac, char **av)
{
	int i = 0;
	int j = 0;
	if (ac == 3)
	{
		while(av[2][j])
		{
			if (av[1][i] == av[2][j])
				i++;
			j++;
		}
		if(!av[1][i])
			ft_putstr(av[1]);
	}
	write(1, "\n", 1);
}
