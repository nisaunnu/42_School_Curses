/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:55:00 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/10 18:20:52 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdio.h>

// Belirli bir filozofun durumunu ve o anki zamanı yazdıran fonksiyon
static void	print_status(t_philo *philo, long long time, t_philo_status status)
{
	printf ("\033[33mtime : %lld \t", time); // zaman bilgisini yazdır
	printf ("\033[36mphilo : %d \t", philo->id + 1); // filozofun numarasını yazdır

	// filozofun durumuna göre durumu yazdır
	if (status == FORK1_IN_USE)
		printf ("\033[32mstate : has taken a fork (left fork)");
	else if (status == FORK2_IN_USE)
		printf ("\033[32mstate : has taken a fork (right fork)");
	else if (status == EATING)
		printf ("\033[35mstate : is eating");
	else if (status == SLEEPING)
		printf ("\033[33mstate : is sleeping");
	else if (status == THINKING)
		printf ("\033[37mstate : is thinking");
	else if (status == DIED)
		printf ("\033[31mstate : died");
	printf ("\033[0m\n");
}

// Filozofun durumunu ve o anki zamanı loglayan fonksiyon
void	log_philo_status(t_philo *philo, t_philo_status status, int die)
{
	long long	temporary;

	pthread_mutex_lock(&philo->table_rules->print_mutex);
	if (stop_simulation_flag_control(philo->table_rules) == 1 && die == 0) // simülasyon durdurma bayrağının kontrolünü yap; bayrak 1 ve filozof ölmediyse işlem yapma
	{
		pthread_mutex_unlock(&philo->table_rules->print_mutex);
		return ;
	}
	temporary = ms_system_time() - philo->table_rules->simulation_start_time; // filozofun durumunu ve geçen süreyi hesapla
	print_status(philo, temporary, status); // yazdırma işlemini gerçekleştiren fonksiyonu çağır
	pthread_mutex_unlock(&philo->table_rules->print_mutex);
}

// Hata durumlarını yazdıran fonksiyon
void	err_print(t_table *table, char *message)
{
	pthread_mutex_lock(&table->print_mutex);
	printf("\033[31m%s\033[0m\n", message); // hata mesajını yazdır
	pthread_mutex_unlock(&table->print_mutex);
}
