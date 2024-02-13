/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:55:00 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/12 12:09:07 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

static void	print_status(t_philo *philo, long long time, t_philo_status status)
{
	printf ("\033[33m%lld \t", time);
	printf ("\033[36m%d \t", philo->id + 1);
	if (status == FORK1_IN_USE)
		printf ("\033[32mhas taken a fork (left fork)");
	else if (status == FORK2_IN_USE)
		printf ("\033[32mhas taken a fork (right fork)");
	else if (status == EATING)
		printf ("\033[35mis eating");
	else if (status == SLEEPING)
		printf ("\033[33mis sleeping");
	else if (status == THINKING)
		printf ("\033[37mis thinking");
	else if (status == DIED)
		printf ("\033[31mdied");
	printf ("\033[0m\n");
}

void	log_philo_status(t_philo *philo, t_philo_status status, int die)
{
	long long	temporary;

	pthread_mutex_lock(&philo->table_rules->print_mutex);
	if (stop_simulation_flag_control(philo->table_rules) == 1 && die == 0)
	{
		pthread_mutex_unlock(&philo->table_rules->print_mutex);
		return ;
	}
	temporary = ms_system_time() - philo->table_rules->simulation_start_time;
	print_status(philo, temporary, status);
	pthread_mutex_unlock(&philo->table_rules->print_mutex);
}

void	err_print(t_table *table, char *message)
{
	pthread_mutex_lock(&table->print_mutex);
	printf("\033[31m%s\033[0m\n", message);
	pthread_mutex_unlock(&table->print_mutex);
}
