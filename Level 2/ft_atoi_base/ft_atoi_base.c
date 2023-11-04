int tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return c;
}

int getdigit(char c, int base)
{
	int maxdigit;
	if (base <= 10)
		maxdigit += base - '0';
	else
		maxdigit += base + 97 - 10;
	if (c >= '0' && c <= '9' && c <= maxdigit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= maxdigit)
		return (c - 97 + 10);
	else
		return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int digit;
	int result;
	while ((digit = getdigit(tolower(*str),str_base)) >= 0)
	{
		result *= str_base;
		result += digit;
		str++;
	}
	return (result);
}

#include <stdio.h>

int main()
{
	printf("%d\n", ft_atoi_base("26", 16));
}
