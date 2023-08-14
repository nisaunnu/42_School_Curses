/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 05:52:57 by nunnu             #+#    #+#             */
/*   Updated: 2023/07/23 15:44:03 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

// #include <stdio.h>

// int main()
// {
// 	printf("Input: 4           Output: %d\n", ft_isascii('4'));
// 	printf("Input: C           Output: %d\n", ft_isascii('C'));
// 	printf("Input: c           Output: %d\n", ft_isascii('c'));
// 	printf("Input: new line    Output: %d\n", ft_isascii('\n'));
// }
