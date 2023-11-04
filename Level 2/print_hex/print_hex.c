#include <unistd.h>

void	ft_print(int n)
{
	if (n > 15)
		ft_print(n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
}

int	ft_atoi(char *str)
{
	int result = 0;
	int i = 0;

	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_print(ft_atoi(av[1]));
	write(1, "\n", 1);
}
