/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 05:53:33 by nunnu             #+#    #+#             */
/*   Updated: 2023/07/23 15:44:10 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

// #include <stdio.h>

// int main()
// {
// 	printf("Input: 2     Output: %d\n", ft_isdigit('2'));
// 	printf("Input: 50    Output: %d\n", ft_isdigit(50));
// 	printf("Input: 2     Output: %d\n", ft_isdigit(2));
// }
