#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac != 3)
	{
		printf("\n");
		return 0;
	}
	int s1 = atoi(av[1]);
	int s2 = atoi(av[2]);
	if (s1 >0 && s2 > 0)
	{
		while (s1 != s2)
		{
			if (s1 > s2)
				s1 -= s2;
			else
				s2 -= s1;
		}
		printf("%d", s1);
	}
}
