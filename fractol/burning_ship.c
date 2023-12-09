/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:50:26 by nunnu             #+#    #+#             */
/*   Updated: 2023/12/08 14:46:43 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

void	init_burning_ship(t_fractal *fractal)
{
	fractal->min_re = -2.0;
	fractal->max_re = 1.5;
	fractal->min_im = -2.0;
	fractal->max_im = 1.0;
	fractal->max_iteration = MAX_ITER;
	fractal->calculate_fractal = calculate_burning_ship;
}

int	calculate_burning_ship(double re, double im, t_fractal *fractal)
{
	int		iter;
	double	r;
	double	i;
	double	r2;
	double	i2;

	iter = -1;
	r = re;
	i = im;
	while (++iter < fractal->max_iteration)
	{
		r = fabs(r);
		i = fabs(i);
		r2 = pow(r, 2);
		i2 = pow(i, 2);
		if ((r2 + i2) > LIMIT)
			return (iter);
		i = 2 * r * i + im;
		r = r2 - i2 + re;
	}
	return (fractal->max_iteration);
}
