/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:54:32 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/10 18:07:42 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// Simülasyon durdurma bayrağını kontrol eden fonksiyon
int	stop_simulation_flag_control(t_table *table)
{
	int	flag;

	flag = 0; 							// flag'i başlangıçta 0 olarak ayarla
	pthread_mutex_lock(&table->meal_checker_mutex); 	// simülasyon durdurma bayrağını kontrol etmeden önce mutex kilidi al
	if (table->stop_simulation == 1)	// meal_checker_mutex kilidi ile güvenli bir şekilde simülasyon durdurma bayrağını kontrol et
		flag = 1; 						// eğer durdurma bayrağı 1 ise, flag'i 1 olarak ayarla
	pthread_mutex_unlock(&table->meal_checker_mutex);	// mutex kilidini serbest bırak
	return (flag);
}

// Simülasyon durdurma bayrağını güncelleyen fonksiyon
void	update_stop_flag(t_table *table, int flag)
{
	pthread_mutex_lock(&table->meal_checker_mutex);		// simülasyon durdurma bayrağını güncellemeden önce mutex kilidi al
	table->stop_simulation = flag;						// simülasyon durdurma bayrağını belirtilen flag değeriyle güncelle
	pthread_mutex_unlock(&table->meal_checker_mutex);	// simülasyon durdurma bayrağını güncellemeden önce mutex kilidi bırak
}
