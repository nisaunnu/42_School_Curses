int is_power_2(unsigned int n)
{
	int i = 2;
	while (i > 1 && n % i == 0)
		n /= 2;
	return (n == 1);
}