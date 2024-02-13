/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:55:04 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/10 17:55:05 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <sys/time.h>
#include <unistd.h>

long long	ms_system_time(void)
{
	struct timeval	time_value;

	gettimeofday(&time_value, NULL);
	return ((time_value.tv_sec * 1000) + (time_value.tv_usec / 1000));
}

void	wait_until_time(long long time)
{
	while (ms_system_time() < time)
		continue ;
}

void	stop_until_time(t_table *table, time_t time_to_spend)
{
	long long	time_to_go;

	time_to_go = ms_system_time() + time_to_spend;
	while (ms_system_time() < time_to_go)
	{
		if (stop_simulation_flag_control(table) == 1)
			break ;
		usleep(100);
	}
}
