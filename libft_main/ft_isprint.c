/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 05:54:10 by nunnu             #+#    #+#             */
/*   Updated: 2023/07/23 15:44:49 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}

// #include <stdio.h>

// int main()
// {
// 	printf("Input: 4          Output: %d\n", ft_isprint('4'));
// 	printf("Input: C          Output: %d\n", ft_isprint('C'));
// 	printf("Input: space      Output: %d\n", ft_isprint(32));
// 	printf("Input: del        Output: %d\n", ft_isprint(127));
// }
