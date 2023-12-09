/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:51:10 by nunnu             #+#    #+#             */
/*   Updated: 2023/12/08 14:53:46 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"

void	error_message(void)
{
	ft_putstr_fd("\n\033[31;1mWRONG INPUT FORMAT\n\n", 1);
	ft_putstr_fd("\033[33mInput Format: ./fractol", 1);
	ft_putstr_fd("<fractol_type> <parameters>\n\n", 1);
	ft_putstr_fd("\tfractol_type           : Julia, Mandelbrot or ", 1);
	ft_putstr_fd("Burning_ship\n", 1);
	ft_putstr_fd("\tparameters (for julia) : between -2 and 2\n\n", 1);
	ft_putstr_fd("\033[36mCommands:\n", 1);
	ft_putstr_fd("\texit                 : press esc\n", 1);
	ft_putstr_fd("\tmove                 : ← ↑ → ↓ or left mouse click\n", 1);
	ft_putstr_fd("\tzoom                 : mouse scroll\n", 1);
	ft_putstr_fd("\tcolor change         : press c\n", 1);
	ft_putstr_fd("\ttrack mouse location : press space and move mouse", 1);
	ft_putstr_fd("\n\n\033[0m", 1);
	exit(EXIT_FAILURE);
}

int	select_fractal(char *fractal_name, t_fractal *fractal)
{
	if (ft_strcmp(fractal_name, "Julia") == 0)
	{
		init_julia(fractal);
		return (1);
	}
	else if (ft_strcmp(fractal_name, "Mandelbrot") == 0)
	{
		init_mandelbrot(fractal);
		return (1);
	}
	else if (ft_strcmp(fractal_name, "Burning_ship") == 0)
	{
		init_burning_ship(fractal);
		return (1);
	}
	else
	{
		error_message();
		return (0);
	}
}
