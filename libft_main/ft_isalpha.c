/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 05:47:20 by nunnu             #+#    #+#             */
/*   Updated: 2023/07/23 15:43:55 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

// #include <stdio.h>

// int main()
// {
// 	printf("Input: n    Output: %d\n", ft_isalpha('n'));
// 	printf("Input: N    Output: %d\n", ft_isalpha('N'));
// 	printf("Input: 1    Output: %d\n", ft_isalpha('1'));
// }
