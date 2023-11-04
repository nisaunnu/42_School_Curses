#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_print(int nb)
{
    if(nb > 9)
        ft_print(nb / 10);
    write(1, &"0123456789"[nb % 10], 1);
}

int ft_atoi(char *str)
{
    int i = 0;
    int rslt = 0;
    while(str[i] && str[i] >= '0' && str[i] <= '9')
        rslt = (rslt * 10) + (str[i++] - '0');
    return(rslt);
}

int is_prime(int nb)
{
	int i = 2;
	if (nb <= 1)
		return 0;
	while (i < nb)
	{
		if (nb % i == 0)
			return 0;
		i++;
	}
	return 1;
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int number = ft_atoi(av[1]);
		int sum = 0;
		while (number > 0)
		{
			if (is_prime(number--))
				sum += number + 1;
		}
		ft_print(sum);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}
