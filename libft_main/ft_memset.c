/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 05:57:38 by nunnu             #+#    #+#             */
/*   Updated: 2023/07/23 18:25:08 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

// #include <stdio.h>

// int main()
// {
// 	char s[] = "nunnu";

// 	printf("Input: %s\t", s);
// 	ft_memset(s, 'a', 4);
// 	printf("Output: %s\n", s);
// }
