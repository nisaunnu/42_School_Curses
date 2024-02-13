/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:54:35 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/10 17:54:36 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdlib.h>

int	clear_mutexes(t_table *table)
{
	int	i;

	i = -1;
	if (!table)
		return (FAILURE);
	while (++i < table->number_philo)
	{
		if (table->return_mutex_fork)
			pthread_mutex_destroy(&table->fork_mutexes[i]);
		if (table->philo[i].return_mutex_eating)
			pthread_mutex_destroy(&table->philo[i].eating_mutex);
	}
	if (table->return_mutex_checker)
		pthread_mutex_destroy(&table->meal_checker_mutex);
	if (table->return_mutex_print)
		pthread_mutex_destroy(&table->print_mutex);
	free(table->philo);
	free(table->fork_mutexes);
	return (SUCCESS);
}
