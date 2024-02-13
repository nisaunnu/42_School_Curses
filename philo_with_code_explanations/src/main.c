/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:54:49 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/10 18:22:47 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (parsing(ac, av)) // komut satırı argümanlarını ayrıştırmak için parsing fonksiyonunu çağır
		return (SUCCESS);
	if (set_up_table(&table, ac, av)) // yemek masası kurulumunu gerçekleştirmek için set_up_table fonksiyonunu çağır
		return (clear_mutexes(&table), SUCCESS);
	if (being_life_cycle(&table)) // filozofların yaşam döngülerini başlatmak için being_life_cycle fonksiyonunu çağır
		return (clear_mutexes(&table), SUCCESS);
	if (clear_mutexes(&table)) // mutex'leri temizlemek için clear_mutexes fonksiyonunu çağır
		return (SUCCESS);
	return (SUCCESS);
}
