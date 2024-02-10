#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i = 0;
	while (str && str[i])
		i++;
	return i;
}

char *ft_strjoin(char *str1, char *str2)
{
	char *tmp = malloc(ft_strlen(str1) + ft_strlen(str2) + 1 );
	int i = 0;
	while (str1 && str1[i])
	{
		tmp[i] = str1[i];
		i++;
	}
	int j = 0;
	while(str2 && str2[j])
	{
		tmp[i + j] = str2[j];
		j++;
	}
	tmp[i + j] = '\0';
	return(tmp);
}

char *ft_substr(char *str, int i)
{
	char *tmp = malloc(i + 1);
	int j = 0;
	while (str[i] && j < i)
	{
		tmp[j] = str[j];
		j++;
	}
	tmp[j] = '\0';
	return(tmp);
}

int check(char *line)
{
	if(!line)
		return -1;
	int i = 0;
	while (line[i])
	{
		if(line[i] == '\n')
			return i;
		i++;
	}
	return -1;
}

char *next_line(char *line, int fd)
{
	int i = 1;
	char *tmp;
	while (check(line) < 0 && i != 0)
	{
		tmp = malloc(BUFFER_SIZE + 1);
		i = read(fd, tmp, BUFFER_SIZE);
		if(i < 0)
		{
			free(line);
			free(tmp);
			return NULL;
		}
		if(i == 0 && !line)
			return(free(tmp), NULL);
		tmp[i] = '\0';
		line = ft_strjoin(line, tmp);
		free(tmp);
	}
	return (line);
}

char *get_next_line(int fd)
{
	if(BUFFER_SIZE <= 0 || fd < 0)
		return NULL;
	static char *line = NULL;
	line = next_line(line, fd);
	char *str;
	int i = check(line);
	char *tmp;
	if(line != NULL)
	{
		if(i != -1)
		{
			tmp = line;
			str = ft_substr(line, i + 1);
			line = ft_substr(&line[i + 1], ft_strlen(line) - i);
			free(tmp);
		}
		else
		{
			str = ft_substr(line, ft_strlen(line));
			line = NULL;
			free(line);
		}
	return (str);
	}
	return NULL;
}
