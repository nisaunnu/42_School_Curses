#include <stdlib.h>

int *ft_range(int start, int end)
{
	int *tab;
	int size = 0;
	int i = 0;

	if (start > end)
		size = start - end + 1;
	else
		size = end - start + 1;
	tab = (int *)malloc(sizeof(int) * (size + 1));
	if (start > end)
	{
		while(start >= end)
		{
			tab[i] = start;
			start--;
			i++;
		}
	}
	else
	{
		while(start <= end)
		{
			tab[i] = start;
			start++;
			i++;
		}
	}
	return(tab);
}
