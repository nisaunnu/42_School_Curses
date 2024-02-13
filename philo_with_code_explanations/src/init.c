/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:54:38 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/10 18:47:02 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdlib.h>

static int	initialize_table(int ac, char **av, t_table *table)
{
	table->number_philo = ft_atoi(av[1]);
	table->fork_mutexes = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->number_philo);
	table->philo = (t_philo *)malloc(sizeof(t_philo) * table->number_philo);
	if (!table->fork_mutexes || !table->philo)
		return (FAILURE);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->return_mutex_fork = 0;
	table->return_mutex_print = 0;
	table->return_mutex_checker = 0;
	table->time_to_sleep = ft_atoi(av[4]);
	table->stop_simulation = 0;
	table->meal_count_limit = -1;
	table->simulation_start_time = 0;
	if (ac == 6)
		table->meal_count_limit = ft_atoi(av[5]);
	else
		table->meal_count_limit = -1;
	return (SUCCESS);
}

static int	initialize_philosophers(t_table *table)
{
	int	i;

	if (!table)
		return (FAILURE);
	i = -1;
	while (++i < table->number_philo)
	{
		table->philo[i].id = i;
		table->philo[i].meals_count = 0;
		table->philo[i].return_mutex_eating = 0;
		table->philo[i].thread = 0;
		table->philo[i].time_to_meal = table->simulation_start_time;
		table->philo[i].forks[0] = i;
		table->philo[i].forks[1] = ((i + 1) % table->number_philo);
		if (i % 2)
		{
			table->philo[i].forks[0] = ((i + 1) % table->number_philo);
			table->philo[i].forks[1] = i;
		}
		table->philo[i].table_rules = table;
	}
	return (SUCCESS);
}

static int	initialize_mutexes(t_table *table)
{
	int	i;
	int	re_eat;
	int	re_fork;
	int	re_check;
	int	re_print;

	if (!table)
		return (FAILURE);
	i = table->number_philo;
	while (--i >= 0)
	{
		re_fork = pthread_mutex_init(&table->fork_mutexes[i], NULL);
		table->return_mutex_fork = re_fork;
		re_eat = pthread_mutex_init(&table->philo[i].eating_mutex, NULL);
		table->philo[i].return_mutex_eating = re_eat;
		if (re_fork != 0 || re_eat != 0)
			return (FAILURE);
	}
	re_check = pthread_mutex_init(&table->meal_checker_mutex, NULL);
	table->return_mutex_checker = re_check;
	re_print = pthread_mutex_init(&table->print_mutex, NULL);
	table->return_mutex_print = re_print;
	if (re_check != 0 || re_print != 0)
		return (FAILURE);
	return (SUCCESS);
}

int	set_up_table(t_table *table, int ac, char **av)
{
	if (initialize_table(ac, av, table))
		return (err_print(table, ERR_INIT_TABLE), FAILURE);
	if (initialize_philosophers(table))
		return (err_print(table, ERR_INIT_PHILO), FAILURE);
	if (initialize_mutexes(table))
		return (err_print(table, ERR_INIT_MUTEX), FAILURE);
	return (SUCCESS);
}
