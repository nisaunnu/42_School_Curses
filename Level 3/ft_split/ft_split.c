#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

char	*ft_strcpy(char *src, char *dst, int size)
{
	int i = 0;
	while (i < size)
	{
		src[i] = dst[i];
		i++;
	}
	return src;
}

char	**ft_split(char *str)
{
	int i,j,k,len;
	i = 0;
	j = 0;
	k = 0;
	len = ft_strlen(str);
	int word_count = 0;
	char **split;
	while (i < len)
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
		{
			word_count++;
			while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
				i++;
		}
	}
	split = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return NULL;
	i = 0;
	while (i < len)
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
		{
			j = i;
			while (str[j] && str[j] != ' ' && str[j] != '\t' && str[j] != '\n')
				j++;
			split[k] = (char *)malloc(sizeof(char) * j - i + 1);
			if(!split[k])
				return NULL;
			ft_strcpy(split[k], str + i, j - i);
			split[k][j - i] = '\0';
			k++;
			i = j;
		}
	}
	split[k] = NULL;
	return split;	
}