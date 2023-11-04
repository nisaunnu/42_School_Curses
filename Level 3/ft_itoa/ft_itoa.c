#include <stdlib.h>

int check(int nb)
{
	int count = 0;
	if (nb == 0)
		return 1;
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb != 0)
	{
		count++;
		nb /= 10;
	}
	return count;
}

char	*ft_itoa(int nbr)
{
	int op = 1;
	int len = check(nbr);
	char *result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return NULL;
	result[len] = '\0';
	if (nbr == 0)
		result[0] = '0';
	if (nbr < 0)
	{
		op = -1;
		nbr *= -1;
	}
	len--;
	while (nbr != 0)
	{
		result[len] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	if (op == -1)
	{
		result[0] = '-';
	}
	return result;
}