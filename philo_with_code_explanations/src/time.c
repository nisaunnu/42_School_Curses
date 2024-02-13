/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:55:04 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/10 18:16:55 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <sys/time.h>
#include <unistd.h>

// Sistem saatini milisaniye cinsinden döndüren fonksiyon
long long	ms_system_time(void)
{
	struct timeval	time_value;

	gettimeofday(&time_value, NULL); // gettimeofday fonksiyonu ile sistem saatini al
	return ((time_value.tv_sec * 1000) + (time_value.tv_usec / 1000)); // milisaniyeye çevir
}

// Belirtilen milisaniye değerine kadar bekleyen fonksiyon
void	wait_until_time(long long time)
{
	while (ms_system_time() < time)
		continue ; // sistem saatine kadar bekleme yapar
}

// Belirtilen süre boyunca bekleyen fonksiyon
void	stop_until_time(t_table *table, time_t time_to_spend)
{
	long long	time_to_go;

	time_to_go = ms_system_time() + time_to_spend; // belirtilen süreyi ekleyerek hedef zamanı belirle
	while (ms_system_time() < time_to_go)
	{
		if (stop_simulation_flag_control(table) == 1) // simülasyon durdurma bayrağı kontrolü yap ve 1 ise döngüden çık
			break ;
		usleep(100); // 100 mikrosaniye bekle
	}
}
