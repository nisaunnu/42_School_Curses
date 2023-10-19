/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:33:05 by nunnu             #+#    #+#             */
/*   Updated: 2023/10/15 19:48:15 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c) // karakterleri ekrana yazdırmak için ft_putchar fonksiyonu kullanıldı
{
	write(1, &c, 1);
}

void	ft_putstr(char *str) // uzun dizeleri yazdırabilmek amaçlı ft_putstr kullanıldı
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int nb) // SERVER'ın ekrana PID yazdırmasını gerçekleştirmek için ft_putnbr kullanıldı
{
	if (nb == -2147483648)
		write(1, "-2147483648", 1);
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
			ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

int	ft_atoi(const char *str) // CLIENT'ın argümanlardan PID string'ini integer'a çevirmesi için ft_atoi kullanıldı
{
	unsigned int	result;

	result = 0;
	while (*str <= 32)
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}
