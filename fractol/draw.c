/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:50:33 by nunnu             #+#    #+#             */
/*   Updated: 2023/12/08 14:24:42 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

unsigned int	get_math_color(int iteration)
{
	int	red;
	int	green;
	int	blue;

	red = (int)((sin(WAVE_LENGTH_R * iteration) + RANGE) * RATIO_R * RGB);
	green = (int)((sin(WAVE_LENGTH_G * iteration) + RANGE) * RATIO_G * RGB);
	blue = (int)((sin(WAVE_LENGTH_B * iteration) + RANGE) * RATIO_B * RGB);
	return ((red << 16) | (green << 8) | blue);
}

int	get_color(int iter, int max_iter, t_graph *graph)
{
	unsigned int	color;
	int				grey;

	grey = 0;
	if (iter == max_iter)
		return (BLACK);
	color = (get_math_color(iter));
	if (graph->color_mode == 1)
		color = ~color & WHITE;
	else if (graph->color_mode == 2)
	{
		grey = (int)(LUMA_R * ((color >> 16) & LOW_BIT) + LUMA_G * ((color >> 8)
					& LOW_BIT) + LUMA_B * (color & LOW_BIT));
		color = (grey << 16) | (grey << 8) | grey;
	}
	return (color);
}

void	put_pixel_to_image(t_graph *graph, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = graph->addr + (y * graph->line_lenght + x
				* (graph->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_fractal(t_fractal *fractal, t_graph *graph)
{
	int		x;
	int		y;
	int		iter;
	double	re;
	double	im;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			re = fractal->min_re + (fractal->max_re - fractal->min_re)
				* x / WIN_WIDTH;
			im = fractal->min_im + (fractal->max_im - fractal->min_im)
				* y / WIN_HEIGHT;
			iter = fractal->calculate_fractal(re, im, fractal);
			fractal->color = get_color(iter, fractal->max_iteration, graph);
			put_pixel_to_image(graph, x, y, fractal->color);
			x++;
		}
		y++;
	}
}
