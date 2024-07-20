/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu     <nunnu@student.42kocaeli.c>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:25:37 by nunnu             #+#    #+#             */
/*   Updated: 2024/05/15 18:13:32 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_check(char str)
{
	return (str == 'c' || str == 'd' || str == 'i' || str == 'u' || str == '%'
		|| str == 's' || str == 'x' || str == 'X' || str == 'p');
}

int	ft_format(va_list *arg, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg((*arg), int)));
	else if (format == 's')
		return (ft_string(va_arg((*arg), char *)));
	else if (format == 'p')
		return (ft_point(va_arg((*arg), unsigned long), 1));
	else if (format == 'd' || format == 'i')
		return (ft_int(va_arg((*arg), int)));
	else if (format == 'u')
		return (ft_unsigned(va_arg((*arg), unsigned int)));
	else if (format == 'X' || format == 'x')
		return (ft_hex(va_arg((*arg), unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	int		value;
	va_list	arg;

	i = -1;
	len = 0;
	va_start(arg, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%' && ft_check(format[i + 1]))
		{
			value = ft_format(&arg, format[++i]);
			if (value == -1)
				return (-1);
			len += value - 1;
		}
		else if (ft_putchar(format[i]) == -1)
			return (-1);
		len++;
	}
	va_end(arg);
	return (len);
}
