/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:54:35 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/10 18:11:52 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include <stdlib.h>

// Mutex'leri temizleyen fonksiyon
int	clear_mutexes(t_table *table)
{
	int	i;

	i = -1;
	if (!table) // geçersiz bir table gönderildiyse, FAILURE değerini döndür
		return (FAILURE);
	while (++i < table->number_philo) // her bir filozof için mutex'leri temizle
	{
		if (table->return_mutex_fork) // eğer mutex init'leme işlemi başarılıysa,
			pthread_mutex_destroy(&table->fork_mutexes[i]); // filozofun çatal mutex'ini temizle
		if (table->philo[i].return_mutex_eating) // eğer filozofun yeme mutex'ini init'leme işlemi başarılıysa,
			pthread_mutex_destroy(&table->philo[i].eating_mutex); // yeme mutex'ini temizle
	}
	if (table->return_mutex_checker) // eğer checker_mutex init'leme işlemi başarılıysa,
		pthread_mutex_destroy(&table->meal_checker_mutex); // checker mutex'ini temizle
	if (table->return_mutex_print) // eğer print_mutex init'leme işlemi başarılıysa,
		pthread_mutex_destroy(&table->print_mutex); // print mutex'ini temizle

	// dinamik olarak tahsis edilen belleği serbest bırak
	free(table->philo);
	free(table->fork_mutexes);

	return (SUCCESS); // fonksiyon başarıyla tamamlandığında, SUCCESS değeri döndür
}
