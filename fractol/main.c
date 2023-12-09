/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:50:55 by nunnu             #+#    #+#             */
/*   Updated: 2023/12/08 14:08:43 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"
#include "mlx_opengl/mlx.h"

int	main(int ac, char **av)
{
	int			check;
	t_graph		graph;
	t_fractal	fractal;

	check = ((ac == 4) && (ft_strcmp(av[1], "Julia") == 0));
	init_julia_check(&fractal);
	if (gui_setup(&graph) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	graph.fractal = &fractal;
	if (check)
	{
		fractal.julia_re = ft_atof(av[2]);
		fractal.julia_im = ft_atof(av[3]);
	}
	if ((ac == 2 || check == 1) && select_fractal(av[1], &fractal))
	{
		draw_fractal(&fractal, &graph);
		mlx_put_image_to_window(graph.mlx_ptr, graph.window, graph.img_ptr,
			START_POINT_X, START_POINT_Y);
		setup_hooks(&graph);
		mlx_loop(graph.mlx_ptr);
	}
	else
		error_message();
	return (EXIT_SUCCESS);
}
