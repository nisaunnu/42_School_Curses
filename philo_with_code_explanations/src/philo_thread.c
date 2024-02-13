/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:54:56 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/10 18:37:11 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// Filozof iş parçacıklarını oluşturan fonksiyon
static int	create_philosopher_threads(t_table *table)
{
	int	i;

	i = 0;
	table->simulation_start_time = ms_system_time(); // simülasyonun başlangıç zamanını kaydet
	while (i < table->number_philo) // belirtilen sayıda filozof iş parçacığını oluştur
	{
		// pthread_create fonksiyonu ile filozof iş parçacığını başlat
		// philosopher_life_cycle fonksiyonu, filozofun yaşam döngüsünü temsil eder
		if (pthread_create(&table->philo[i].thread, NULL,
				&philosopher_life_cycle, &table->philo[i]))
			return (FAILURE); // iş parçacığı (thread) oluşturma başarısız olursa FAILURE değerini döndür
		i++;
	}
	if (table->number_philo > 1) // eğer filozof sayısı 1'den fazlaysa, yemek kontrolcüsü iş parçacığını (thread'i) başlat
	{
		if (pthread_create(&table->meal_checker, NULL, &state_checker, table)) // yemek kontrolcüsü iş parçacığı başlatma başarısız olursa
			return (FAILURE); // FAILURE değerini döndür
	}
	return (SUCCESS); // iş parçacıkları (thread'ler) başarıyla oluşturulursa SUCCESS değerini döndür
}

// Filozof iş parçacıklarının tamamlanmasını bekleyen fonksiyon
static int	join_philosopher_threads(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->number_philo) // tüm filozof iş parçacıklarının tamamlanmasını bekle
		pthread_join(table->philo[i].thread, NULL);
	if (table->number_philo > 1) // filozof sayısı 1'den fazlaysa, yemek kontrolcüsü iş parçacığının tamamlanmasını bekle
		pthread_join(table->meal_checker, NULL);
	return (SUCCESS); // iş parçacıkları başarıyla tamamlanırsa SUCCESS değerini döndür
}

// Filozof iş parçacıklarını oluşturan ve tamamlanmasını bekleyen ana fonksiyon
int	being_life_cycle(t_table *table)
{
	if (create_philosopher_threads(table)) // filozofların iş parçacıklarını oluşturan fonksiyonu çağır
		return (err_print(table, ERR_THREAD), FAILURE); // oluşturma başarısız olursa hata mesajı yazdır ve FAILURE değerini döndür
	if (join_philosopher_threads(table)) // filozofların iş parçacıklarının tamamlanmasını bekleyen fonksiyonu çağır
		return (err_print(table, ERR_JOIN_THREAD), FAILURE); // tamamlanma beklemesi başarısız olursa hata mesajı yazdır ve FAILURE değerini döndür
	return (SUCCESS);
}
