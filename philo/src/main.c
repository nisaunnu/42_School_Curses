/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:54:49 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/10 17:54:50 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (parsing(ac, av))
		return (SUCCESS);
	if (set_up_table(&table, ac, av))
		return (clear_mutexes(&table), SUCCESS);
	if (being_life_cycle(&table))
		return (clear_mutexes(&table), SUCCESS);
	if (clear_mutexes(&table))
		return (SUCCESS);
	return (SUCCESS);
}
