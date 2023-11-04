#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac == 4)
	{
		int s1 = atoi(av[1]);
		int s2 = atoi(av[3]);
		char c = av[2][0];
		if (c == '+')
			printf("%d", s1 + s2);
		else if (c == '-')
			printf("%d", s1 - s2);
		else if (c == '*')
			printf("%d", s1 * s2);
		else if (c == '/')
			printf("%d", s1 / s2);
		else if (c == '%')
			printf("%d", s1 % s2);
	}
	printf("\n");
	return (0);
}
