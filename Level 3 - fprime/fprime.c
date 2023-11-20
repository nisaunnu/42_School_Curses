#include <stdio.h>
#include <stdlib.h>

unsigned int prime_check(unsigned int prime)
{
	unsigned int i = 2;
	while(prime > i)
	{
		if (prime % i == 0)
			return(1);
		i++;
	}
	return(0);
}

int main(int ac, char **av)
{
	unsigned int avg = 0;
	unsigned int prime = 2;

	if (ac == 2 && av[1][0] != '-')
	{
		avg = atoi(av[1]);
		if (avg == 1)
			printf("1");
		while(avg >= prime)
		{
			if (prime_check(prime) == 0)
			{
				while (avg % prime == 0)
				{
					printf("%d", prime);
					if (avg > prime)
						printf("*");
					avg /= prime;
				}
			}
			prime++;
		}
	}
	printf("\n");
}
