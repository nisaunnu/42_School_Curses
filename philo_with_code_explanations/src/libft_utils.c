/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:54:42 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/10 18:13:58 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

// Belirtilen dosya tanımlayıcısına string yazan fonksiyon
void	ft_putstr_fd(char *s, int fd)
{
	while (s && *s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

// Belirtilen karakterin bir rakam olup olmadığını kontrol eden fonksiyon
int	is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

// Belirtilen string'in tamamen sayısal olup olmadığını kontrol eden fonksiyon
bool	is_numeric(const char *s)
{
	while (*s && *s <= ' ')
		s++;
	if (*s == '-' || *s == '+')
		s++;
	while (is_digit(*s))
		s++;
	if (*s != '\0')
		return (false);
	return (true);
}

// Belirtilen string'i bir size_t türüne çeviren fonksiyon
size_t	ft_atoi(const char *str)
{
	int		sign;
	size_t	result;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	if (*str == '-' || *str == '+')
		return (-1);
	while (is_digit(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}
