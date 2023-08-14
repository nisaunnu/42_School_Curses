/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 05:43:30 by nunnu             #+#    #+#             */
/*   Updated: 2023/07/23 22:13:28 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc(count * size);
	if (ret)
		ft_bzero(ret, count * size);
	return (ret);
}

// #include <stdio.h>

// int main()
// {
// 	void *ptr;
// 	size_t count;
// 	size_t size;

// 	count = 2;
// 	size = 4;
// 	ptr = ft_calloc(count, size);

// 	if (ptr)
// 		printf("Address: %p\n", ptr);
// 	else
// 		printf("Address: NULL\n");
// 	free(ptr);
// 	return (0);
// }
