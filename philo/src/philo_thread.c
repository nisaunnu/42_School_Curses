/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:54:56 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/10 17:54:57 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	create_philosopher_threads(t_table *table)
{
	int	i;

	i = 0;
	table->simulation_start_time = ms_system_time();
	while (i < table->number_philo)
	{
		if (pthread_create(&table->philo[i].thread, NULL,
				&philosopher_life_cycle, &table->philo[i]))
			return (FAILURE);
		i++;
	}
	if (table->number_philo > 1)
	{
		if (pthread_create(&table->meal_checker, NULL, &state_checker, table))
			return (FAILURE);
	}
	return (SUCCESS);
}

static int	join_philosopher_threads(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->number_philo)
		pthread_join(table->philo[i].thread, NULL);
	if (table->number_philo > 1)
		pthread_join(table->meal_checker, NULL);
	return (SUCCESS);
}

int	being_life_cycle(t_table *table)
{
	if (create_philosopher_threads(table))
		return (err_print(table, ERR_THREAD), FAILURE);
	if (join_philosopher_threads(table))
		return (err_print(table, ERR_JOIN_THREAD), FAILURE);
	return (SUCCESS);
}
