/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 11:25:20 by nunnu             #+#    #+#             */
/*   Updated: 2024/01/28 14:23:14 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Verilen bir karakter dizisinin uzunluğunu hesaplayan fonksiyon
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

// Verilen bir karakter dizisini kopyalayan fonksiyon
char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	int		i;

	i = 0;
	len = ft_strlen(s) + 1;
	dup = (char *)malloc(len);
	if (!dup)
		return (NULL);
	while (*s)
		dup[i++] = *s++;
	dup[i] = '\0';
	return (dup);
}

// İki karakter dizisini birleştiren fonksiyon
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *)malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (*s1)
		new_str[i++] = *s1++;
	while (*s2)
		new_str[i++] = *s2++;
	new_str[i] = '\0';
	return (new_str);
}

// Bir karakter dizisinden belirli bir aralığı kopyalayan fonksiyon
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	calc_len;

	calc_len = ft_strlen(s);
	if (!s || len <= 0)
		return (NULL);
	if (len > calc_len)
		len = calc_len;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = start;
	j = 0;
	while (i < calc_len && j < len)
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

// Bellek bloğunu serbest bırakan ve stash'i temizleyen fonksiyon
void	*ft_free_stash(char **stash, int create_line)
{
	char	*line;

	if (!*stash) // Stash boşsa NULL döndür
		return (NULL);
	// create_line değerine bağlı olarak işlemleri gerçekleştir
	if (create_line == 0) // create_line, 0 ise;
	{
		if (*stash) // stash varsa,
		{
			// stash'i temizle ve belleği serbest bırak
			free(*stash);
			*stash = NULL;
		}
		return (NULL);
	}
	else if (create_line == 1) // create_line, 1 ise;
	{
		line = ft_strdup(*stash); // stash'i kopyala
		free(*stash); // stash'in belleğini serbest bırak
		*stash = NULL;
		return (line); // kopyalanan stash'i (line'ı) döndür
	}
	return (NULL); // create_line değeri 0 veya 1 değilse NULL döndür
}
