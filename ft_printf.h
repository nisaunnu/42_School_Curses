/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 03:23:24 by nunnu             #+#    #+#             */
/*   Updated: 2023/08/10 22:59:20 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_int(int w);
int	ft_check(char str);
int	ft_putchar(char x);
int	ft_string(char *str);
int	ft_unsigned(unsigned int w);
int	ft_hex(unsigned int d, char w);
int	ft_point(unsigned long w, int i);
int	ft_format(va_list *args, char w);
int	ft_printf(const char *format, ...);

#endif
