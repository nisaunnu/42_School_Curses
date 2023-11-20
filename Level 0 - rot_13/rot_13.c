#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		while(*av[1])
		{
			if (('a' <= *av[1] && *av[1] <= 'm') || ('A' <= *av[1] && *av[1] <= 'M'))
				*av[1] += 13;
			else if (('n' <= *av[1] && *av[1] <= 'z') || ('N' <= *av[1] && *av[1] <= 'Z'))
				*av[1] -= 13;
			write(1, av[1], 1);
			av[1]++;
		}
	}
	write(1, "\n", 1);
}

