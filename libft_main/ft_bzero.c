/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 05:43:06 by nunnu             #+#    #+#             */
/*   Updated: 2023/07/23 18:33:54 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

// #include <stdio.h>

// int main()
// {
// 	char s[] = "nunnu";

// 	printf("Input: %s\t", s);
// 	ft_bzero(s, 3);
// 	printf("Output: %c\n", s[3]);
// }
