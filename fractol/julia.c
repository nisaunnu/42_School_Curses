/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:50:47 by nunnu             #+#    #+#             */
/*   Updated: 2023/12/08 14:46:35 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"
#include "mlx_opengl/mlx.h"

void	init_julia_check(t_fractal *fractal)
{
	fractal->julia_im = UNSET_VALUE;
	fractal->julia_re = UNSET_VALUE;
	fractal->julia_fixed = 0;
}

int	julia_motion(int x, int y, t_graph *graph)
{
	t_fractal	*fractal;

	fractal = graph->fractal;
	if (fractal->julia_fixed)
	{
		fractal->julia_re = 4 * ((double)x / WIN_WIDTH - 0.5);
		fractal->julia_im = 4 * ((double)(WIN_HEIGHT - y)
				/ WIN_HEIGHT - 0.5);
		draw_fractal(fractal, graph);
		mlx_put_image_to_window(graph->mlx_ptr, graph->window,
			graph->img_ptr, START_POINT_X, START_POINT_Y);
	}
	return (0);
}

void	init_julia(t_fractal *fractal)
{
	fractal->min_re = -2.0;
	fractal->max_re = 2.0;
	fractal->min_im = -2.0;
	fractal->max_im = 2.0;
	fractal->max_iteration = MAX_ITER;
	fractal->calculate_fractal = calculate_julia;
	if ((fractal->julia_re == UNSET_VALUE) || fractal->julia_im == UNSET_VALUE)
	{
		fractal->julia_re = -0.78;
		fractal->julia_im = 0.3;
	}
}

int	calculate_julia(double re, double im, t_fractal *fractal)
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
		r2 = pow(r, 2);
		i2 = pow(i, 2);
		if ((r2 + i2) > LIMIT)
			return (iter);
		i = 2 * r * i + fractal->julia_im;
		r = r2 - i2 + fractal->julia_re;
	}
	return (fractal->max_iteration);
}
