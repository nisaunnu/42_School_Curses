#include <unistd.h>
#include <stdlib.h>

char	**ft_split(char *str)
{
	int i = 0;
	int j;
	int k = 0;
	char **split;
	split = (char **)malloc(sizeof(char *) * 256);
	if (!split)
		return NULL;
	while (str[i] <= 32)
		i++;
	while (str[i])
	{
		j = 0;
		split[k] = (char *)malloc(sizeof(char) * 4096);
		if (!split)
			return NULL;
		while (str[i] > 32 && str[i])
		{
			split[k][j] = str[i];
			j++;
			i++;
		}
		while (str[i] <= 32 && str[i])
			i++;
		split[k][j] = '\0';
		k++;
	}
	split[k] = NULL;
	return split;
}

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	
}

int main(int ac, char **av)
{
	int i = 1;
	char **str;
	if (ac > 1)
	{
		str = ft_split(av[1]);
		while (str[i])
		{
			ft_putstr(str[i]);
			write(1, " ", 1);
			i++;
		}
		ft_putstr(str[0]);
	}
	write(1, "\n", 1);
}