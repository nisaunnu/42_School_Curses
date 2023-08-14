/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 05:58:25 by nunnu             #+#    #+#             */
/*   Updated: 2023/07/23 20:45:51 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d;
	size_t	s;

	d = ft_strlen(dst);
	s = ft_strlen((char *)src);
	i = 0;
	if (dstsize <= d)
	{
		return (dstsize + s);
	}
	while (src[i] != '\0' && d + i + 1 < dstsize)
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (d + s);
}

// #include <stdio.h>

// int main()
// {
// 	char dst[10] = "nisa";
// 	char src[5] = "ceren";
// 	size_t size;

// 	printf("Input: %s\t", dst);

// 	size = ft_strlcat(dst, src, 10);

// 	printf("Output: %s\t", dst);
// 	printf("Size: %zu\n", size);
// }
