/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 05:42:36 by nunnu             #+#    #+#             */
/*   Updated: 2023/07/27 03:59:30 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	s2 = (char *)malloc(len + 1);
	if ((s2) == NULL)
		return (NULL);
	ft_memcpy(s2, s1, len + 1);
	return (s2);
}

// #include <stdio.h>

// int main()
// {
// 	char *s = "nisa";
// 	char *p1;
// 	char *p2;

// 	p1 = s;
// 	printf("Input:  %s \t Address: %p\n", p1, p1);

// 	p2 = ft_strdup(s);
// 	printf("Output: %s \t Address: %p\n", p2, p2);

// 	free(p2);
// 	return (0);
// }
