/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:51:14 by nunnu             #+#    #+#             */
/*   Updated: 2023/12/06 20:32:34 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"
#include "mlx_opengl/mlx.h"

void	cleanup(t_graph *graph)
{
	if (graph->img_ptr && graph->img_ptr)
	{
		mlx_destroy_image(graph->mlx_ptr, graph->img_ptr);
		graph->window = NULL;
	}
	if (graph->window && graph->window)
	{
		mlx_destroy_window(graph->mlx_ptr, graph->window);
		graph->window = NULL;
	}
	exit(EXIT_SUCCESS);
}

void	init_img(t_graph *graph)
{
	graph->img_ptr = mlx_new_image(graph->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!graph->img_ptr)
	{
		ft_putstr_fd("\n\033[31mError : mlx_new_image failed\033[0m\n", 2);
		exit(EXIT_FAILURE);
	}
	graph->addr = mlx_get_data_addr(graph->img_ptr,
			&(graph->bits_per_pixel), &(graph->line_lenght), &(graph->endian));
}

int	gui_setup(t_graph *graph)
{
	graph->mlx_ptr = mlx_init();
	if (!graph->mlx_ptr)
		return (EXIT_FAILURE);
	graph->window_title = "42 FRACT'OL BY NUNNU";
	graph->window = mlx_new_window(graph->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, graph->window_title);
	if (!graph->window)
		return (EXIT_FAILURE);
	init_img(graph);
	return (EXIT_SUCCESS);
}
