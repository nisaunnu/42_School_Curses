/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 05:45:45 by nunnu             #+#    #+#             */
/*   Updated: 2023/07/23 15:43:47 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

// #include <stdio.h>

// int main()
// {
// 	printf("Input: 4           Output: %d\n", ft_isalnum('4'));
// 	printf("Input: C           Output: %d\n", ft_isalnum('C'));
// 	printf("Input: c           Output: %d\n", ft_isalnum('c'));
// 	printf("Input: new line    Output: %d\n", ft_isalnum('\n'));
// }
