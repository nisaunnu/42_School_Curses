/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:54:32 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/10 17:54:33 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	stop_simulation_flag_control(t_table *table)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&table->meal_checker_mutex);
	if (table->stop_simulation == 1)
		flag = 1;
	pthread_mutex_unlock(&table->meal_checker_mutex);
	return (flag);
}

void	update_stop_flag(t_table *table, int flag)
{
	pthread_mutex_lock(&table->meal_checker_mutex);
	table->stop_simulation = flag;
	pthread_mutex_unlock(&table->meal_checker_mutex);
}
