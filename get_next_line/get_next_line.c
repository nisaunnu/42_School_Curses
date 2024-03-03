#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char *ft_substr(char *str, int i)
{
	char *s = malloc(i + 1);
	int j = 0;
	while (str[j] && j < i)
	{
		s[j] = str[j];
		j++;
	}
	s[j] = '\0';
	return (s);
}

int	check(char *line)
{
	if (!line)
		return (-1);
	int i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	int i = 0;
	int j = 0;
	while (s1 && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
	return (s);
}

char *next_line(char *line, int fd)
{
	char *s;
	int bytes_read = 1;
	while (bytes_read != 0 && check(line) < 0)
	{
		s = malloc(BUFFER_SIZE + 1);
		bytes_read = read(fd, s, BUFFER_SIZE);
		if (bytes_read < 0 )
			return (free (line), free(s), NULL);
		if (bytes_read == 0 && !line)
			return (free(s), NULL);
		s[bytes_read] = '\0';
		line = ft_strjoin(line, s);
		free (s);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	static char *line = NULL;
	char *str;
	line = next_line(line, fd);
	int i = check(line);
	char *tmp;
	if (line != NULL)
	{
		if (i != -1)
		{
			tmp = line;
			str = ft_substr(line, i + 1);
			line = ft_substr(&line[i + 1], ft_strlen(line) - i);
			free (tmp);
		}
		else
		{
			str = ft_substr(line, ft_strlen(line));
			free (line);
			line = NULL;
		}
		return (str);
	}
	return (NULL);
}
