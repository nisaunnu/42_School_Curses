#include <unistd.h>

void ft_print(int nb)
{
	if (nb > 10)
		ft_print(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}

int main()
{
	int i = 1;
	while (i <= 100)
	{
		if (i % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if(i % 5 == 0)
			write(1,"buzz", 4);
		else
			ft_print(i);
		write(1, "\n", 1);
		i++;
	}
}
