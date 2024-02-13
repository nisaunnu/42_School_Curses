/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:54:27 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/10 18:03:29 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <unistd.h>

// Belirli bir filozofun ölüp ölmediğini kontrol eden fonksiyon
static int	check_ended(t_philo *philo)
{
	long long	current;

	current = ms_system_time(); // şu anki sistem zamanını al
	if ((current - philo->time_to_meal) >= philo->table_rules->time_to_die) // filozofun yemek süresi ile şu anki zamandaki farkı kontrol et
	{
		update_stop_flag(philo->table_rules, YES); // ölüm durumunu aktif et
		log_philo_status(philo, DIED, YES); // filozofun durumunu öldü olarak yazdır
		pthread_mutex_unlock(&philo->eating_mutex);
		return (FAILURE);
	}
	return (SUCCESS);
}

// Programın sonlanıp sonlanmadığını kontrol eden fonksiyon
static int	check_program_termination(t_table *table)
{
	int			i;
	long long	meal_count;
	long long	meal_limit;
	int			eating_status;

	i = -1;
	eating_status = 1;
	while (++i < table->number_philo) // her bir filozof için kontrol yap
	{
		pthread_mutex_lock(&table->philo[i].eating_mutex);
		if (check_ended(&table->philo[i]) == 1) // filozofun ölüp ölmediğini kontrol et
			return (FAILURE);
		if (table->meal_count_limit != -1) // eğer genel bir yemek sınırlaması varsa,
		{
			meal_count = (long long)table->philo[i].meals_count;
			meal_limit = (long long)table->meal_count_limit;
			if (meal_count < meal_limit) // mevcut yemek sayısını kontrol et
				eating_status = 0;
		}
		pthread_mutex_unlock(&table->philo[i].eating_mutex);
	}
	if ((table->meal_count_limit != -1) && eating_status == 1) // eğer genel bir yemek sınırlaması varsa ve bütün filozoflar yemek yemeyi tamamladıysa, programı sonlandır
		return (update_stop_flag(table, YES), FAILURE);
	return (SUCCESS);
}

// Simülasyon durumunu kontrol eden iş parçacığı (thread)
void	*state_checker(void *argument)
{
	t_table	*table;

	if (!argument) // argüman kontrolü
		return (NULL);
	table = (t_table *)argument; // argümanı doğru türe dönüştür
	update_stop_flag(table, NO); // simülasyon durumunu sıfırla
	wait_until_time(table->simulation_start_time); // başlangıç zamanını bekleyerek başla
	while (1) // sonsuz bir döngü içinde programın sonlanıp sonlanmadığını kontrol et
	{
		if (check_program_termination(table) == 1)
			return (NULL);
		usleep(1000); // bir sonraki kontrol için kısa bir bekleme süresi ekle
	}
	return (NULL);
}
