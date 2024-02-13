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

// Yemek masası ve filozofları başlatan fonksiyon
static int	initialize_table(int ac, char **av, t_table *table)
{
	// yemek masası bilgilerini başlat
	table->number_philo = ft_atoi(av[1]);
	table->fork_mutexes = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->number_philo);
	table->philo = (t_philo *)malloc(sizeof(t_philo) * table->number_philo);

	// bellek tahsisi başarısız olursa hata döndür
	if (!table->fork_mutexes || !table->philo)
		return (FAILURE);

	// yemek masası kurallarını başlat
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->return_mutex_fork = 0;
	table->return_mutex_print = 0;
	table->return_mutex_checker = 0;
	table->time_to_sleep = ft_atoi(av[4]);
	table->stop_simulation = 0;
	table->meal_count_limit = -1;
	table->simulation_start_time = 0;

	// eğer argüman sayısı 6 ise (her filozofun yemesi gereken en az yemek sayısı girilmişse), yemek sınırlamasını belirle
	if (ac == 6)
		table->meal_count_limit = ft_atoi(av[5]);
	else
		table->meal_count_limit = -1;

	return (SUCCESS);
}

// Filozofları başlatan fonksiyon
static int	initialize_philosophers(t_table *table)
{
	int	i;

	// yemek masası bilgisini kontrol et
	if (!table)
		return (FAILURE);
	i = -1;
	while (++i < table->number_philo) // her filozofun değerlerini başlat
	{
		// filozofun temel bilgilerini başlat
		table->philo[i].id = i;
		table->philo[i].meals_count = 0;
		table->philo[i].return_mutex_eating = 0;
		table->philo[i].thread = 0;
		table->philo[i].time_to_meal = table->simulation_start_time;

		// filozofun sahip olduğu çatal dizisini (sağ ve sol çatal) belirle
		table->philo[i].forks[0] = i;
		table->philo[i].forks[1] = ((i + 1) % table->number_philo);
		if (i % 2)
		{
			table->philo[i].forks[0] = ((i + 1) % table->number_philo);
			table->philo[i].forks[1] = i;
		}
		table->philo[i].table_rules = table; // filozofun bağlı olduğu yemek masasını belirle
	}

	return (SUCCESS);
}

// Mutex'leri başlatan fonksiyon
static int	initialize_mutexes(t_table *table)
{
	int	i;
	int	re_eat;
	int	re_fork;
	int	re_check;
	int	re_print;

	// yemek masası bilgisini kontrol et
	if (!table)
		return (FAILURE);

	// her çatal için mutex'leri başlat
	i = table->number_philo;
	while (--i >= 0)
	{
		re_fork = pthread_mutex_init(&table->fork_mutexes[i], NULL);
		table->return_mutex_fork = re_fork;
		re_eat = pthread_mutex_init(&table->philo[i].eating_mutex, NULL);
		table->philo[i].return_mutex_eating = re_eat;

		// mutex başlatma başarısız olursa hata döndür
		if (re_fork != 0 || re_eat != 0)
			return (FAILURE);
	}
	// yemek kontrol ve ekrana yazdırma için mutex'leri başlat
	re_check = pthread_mutex_init(&table->meal_checker_mutex, NULL);
	table->return_mutex_checker = re_check;
	re_print = pthread_mutex_init(&table->print_mutex, NULL);
	table->return_mutex_print = re_print;

	 // mutex başlatma başarısız olursa hata döndür
	if (re_check != 0 || re_print != 0)
		return (FAILURE);

	return (SUCCESS);
}

// Yemek masasını ve filozofları başlatan ana fonksiyon
int	set_up_table(t_table *table, int ac, char **av)
{
	// yemek masasını başlatma başarısız olursa hata mesajını yazdır ve FAILURE döndür
	if (initialize_table(ac, av, table))
		return (err_print(table, ERR_INIT_TABLE), FAILURE);

	// filozofları başlatma başarısız olursa hata mesajını yazdır ve FAILURE döndür
	if (initialize_philosophers(table))
		return (err_print(table, ERR_INIT_PHILO), FAILURE);

	// mutex'leri başlatma başarısız olursa hata mesajını yazdır ve FAILURE döndür
	if (initialize_mutexes(table))
		return (err_print(table, ERR_INIT_MUTEX), FAILURE);

	return (SUCCESS);
}
