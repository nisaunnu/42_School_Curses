/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:54:53 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/10 17:54:54 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	plus_and_minus_calculate(char *str, size_t *number)
{
	if (*(str - 1) == '+')
		*number = (is_digit(*(str - 1)) * (*number * 10)) + (*str - '0');
	else
		*number = (*number * 10) + (*str - '0');
}

static int	is_sizet(char *str, size_t *result)
{
	size_t			number;

	if ((*str == '-' || *str == '+') && (!*(str + 1) || *(str + 1) == '0'))
		return (-1);
	if (*str == '0' && *(str + 1))
		return (-1);
	if (!is_numeric(str))
		return (-1);
	number = *str - '0';
	while (*(++str))
	{
		if (!(is_digit(*str)))
			return (-1);
		if (*(str - 1) == '-' && *str == '0')
			return (-1);
		plus_and_minus_calculate(str, &number);
		if (!(UNSIGNED_INT_MAX >= number))
			return (-1);
	}
	*result = (number);
	return (SUCCESS);
}

static int	arg_check(int ac, char **av)
{
	int		i;
	size_t	number;

	i = 0;
	while (++i < ac)
	{
		if (!av[i] || (is_sizet(av[i], &number) == -1))
			return (FAILURE);
		if (number <= 0)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	parsing(int ac, char **av)
{
	if (ac < 2)
		return (ft_putstr_fd(ERR_USE, ERR_FILENO), FAILURE);
	if (ac < 5 || 6 < ac)
		return (ft_putstr_fd(ERR_ARG, ERR_FILENO), FAILURE);
	if (arg_check(ac, av))
		return (ft_putstr_fd(ERR_NUM, ERR_FILENO), FAILURE);
	return (SUCCESS);
}
