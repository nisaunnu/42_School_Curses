/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 05:58:02 by nunnu             #+#    #+#             */
/*   Updated: 2023/07/23 21:08:41 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	s_len;

	s_len = ft_strlen(s);
	while (s_len >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
		s_len--;
	}
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
// 	char s[] = "nisa";
// 	printf("Input: %s \t Output: %s\n", s, ft_strchr(s, 's'));
// 	printf("Input: %s \t Output: %s\n", s, ft_strchr(s, 'c'));
// }
