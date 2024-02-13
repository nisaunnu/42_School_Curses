/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:54:27 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/10 17:54:28 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <unistd.h>

static int	check_ended(t_philo *philo)
{
	long long	current;

	current = ms_system_time();
	if ((current - philo->time_to_meal) >= philo->table_rules->time_to_die)
	{
		update_stop_flag(philo->table_rules, YES);
		log_philo_status(philo, DIED, YES);
		pthread_mutex_unlock(&philo->eating_mutex);
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	check_program_termination(t_table *table)
{
	int			i;
	long long	meal_count;
	long long	meal_limit;
	int			eating_status;

	i = -1;
	eating_status = 1;
	while (++i < table->number_philo)
	{
		pthread_mutex_lock(&table->philo[i].eating_mutex);
		if (check_ended(&table->philo[i]) == 1)
			return (FAILURE);
		if (table->meal_count_limit != -1)
		{
			meal_count = (long long)table->philo[i].meals_count;
			meal_limit = (long long)table->meal_count_limit;
			if (meal_count < meal_limit)
				eating_status = 0;
		}
		pthread_mutex_unlock(&table->philo[i].eating_mutex);
	}
	if ((table->meal_count_limit != -1) && eating_status == 1)
		return (update_stop_flag(table, YES), FAILURE);
	return (SUCCESS);
}

void	*state_checker(void *argument)
{
	t_table	*table;

	if (!argument)
		return (NULL);
	table = (t_table *)argument;
	update_stop_flag(table, NO);
	wait_until_time(table->simulation_start_time);
	while (1)
	{
		if (check_program_termination(table) == 1)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
