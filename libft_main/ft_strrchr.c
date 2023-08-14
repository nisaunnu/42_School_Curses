/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:02:10 by nunnu             #+#    #+#             */
/*   Updated: 2023/07/16 22:02:10 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

// #include <stdio.h>

// int main()
// {
// 	char s[] = "nunnu";
// 	printf("Input: %s \t Output: %s\n", s, ft_strrchr(s, 'n'));
// 	printf("Input: %s \t Output: %s\n", s, ft_strrchr(s, 'c'));
// }
