#include <unistd.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_atoi(char *str)
{
	int i = 0;
	int op = 1;
	int result;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
	{
		op = -1;
		i++;
	}
	else if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * op);
	
}

void ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(nb % 1000000000 * -1);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		ft_putnbr(nb);
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}


int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 1;
		int nbr = ft_atoi(av[1]);
		while (i <= 9)
		{
			ft_putnbr(i);
			write(1," x ", 3);
			ft_putnbr(nbr);
			write(1, " = ", 3);
			ft_putnbr(i * nbr);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}