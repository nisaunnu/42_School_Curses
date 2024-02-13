/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:54:46 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/12 12:23:41 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	philo_fork_eat_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->table_rules->fork_mutexes[philo->forks[0]]);
	log_philo_status(philo, FORK1_IN_USE, NO);
	pthread_mutex_lock(&philo->table_rules->fork_mutexes[philo->forks[1]]);
	log_philo_status(philo, FORK2_IN_USE, NO);
	log_philo_status(philo, EATING, NO);
	pthread_mutex_lock(&philo->eating_mutex);
	philo->time_to_meal = ms_system_time();
	pthread_mutex_unlock(&philo->eating_mutex);
	stop_until_time(philo->table_rules, philo->table_rules->time_to_eat);
	if (stop_simulation_flag_control(philo->table_rules) == 0)
	{
		pthread_mutex_lock(&philo->eating_mutex);
		philo->meals_count++;
		pthread_mutex_unlock(&philo->eating_mutex);
	}
	log_philo_status(philo, SLEEPING, NO);
	pthread_mutex_unlock(&philo->table_rules->fork_mutexes[philo->forks[0]]);
	pthread_mutex_unlock(&philo->table_rules->fork_mutexes[philo->forks[1]]);
	stop_until_time(philo->table_rules, philo->table_rules->time_to_sleep);
}

static void	philo_think(t_philo *philo, int think_flag)
{
	long long	think_time;
	int			die_time;
	int			meal_time;
	int			eat_time;

	pthread_mutex_lock(&philo->eating_mutex);
	die_time = philo->table_rules->time_to_die;
	meal_time = ms_system_time() - philo->time_to_meal;
	eat_time = philo->table_rules->time_to_eat;
	think_time = (die_time - meal_time - eat_time) / 2;
	pthread_mutex_unlock(&philo->eating_mutex);
	if (think_time < 0)
		think_time = 0;
	if (think_time == 0 && think_flag == 1)
		think_time = 1;
	if (think_time > 600)
		think_time = 200;
	if (think_flag == 0)
		log_philo_status(philo, THINKING, NO);
	stop_until_time(philo->table_rules, think_time);
}

static void	*one_philosopher(t_philo *philo)
{
	pthread_mutex_lock(&philo->table_rules->fork_mutexes[philo->forks[0]]);
	log_philo_status(philo, FORK1_IN_USE, NO);
	stop_until_time(philo->table_rules, philo->table_rules->time_to_die);
	log_philo_status(philo, DIED, NO);
	pthread_mutex_unlock(&philo->table_rules->fork_mutexes[philo->forks[0]]);
	return (NULL);
}

void	*philosopher_life_cycle(void *argument)
{
	t_philo	*philo;
	t_table	*table;

	if (argument)
	{
		philo = (t_philo *)argument;
		table = philo->table_rules;
		pthread_mutex_lock(&philo->eating_mutex);
		philo->time_to_meal = table->simulation_start_time;
		pthread_mutex_unlock(&philo->eating_mutex);
		wait_until_time(table->simulation_start_time);
		if (table->number_philo == 1)
			return (one_philosopher(philo));
		else if (philo->id % 2)
			philo_think(philo, YES);
		while (stop_simulation_flag_control(table) == 0)
		{
			philo_fork_eat_sleep(philo);
			philo_think(philo, NO);
		}
	}
	return (NULL);
}
