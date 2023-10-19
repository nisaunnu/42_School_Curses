/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:47:52 by nunnu             #+#    #+#             */
/*   Updated: 2023/10/15 20:22:16 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

static void	handler(int signal)
{
	static int	i; // i ve c değişkenleri her çağrıda sıfırlanmaz, sadece ilk kez tanımlandığında başlatılırlar
	static char	c;

	if (signal == SIGUSR1) // SIGUSR1 sinyali alınırsa aşağıdaki kod satırı çallıştırılır
		c = (c << 1) | 1; 	// c değişkeninin en düşük biti, 1 bit sola kaydırılır ve son bit 1 ile toplanır. Böylelikle en düşük bit, 1 ile değiştirilir
	else if (signal == SIGUSR2) // SIGUSR2 sinyali alınırsa aşağıdaki kod çalıştırılır
		c = (c << 1); 		// c değişkeninin en düşük biti, sola bit kaydırma yaparak 0'a çevrilir
	i++; // her fonksiyon çağrısında i artırılır
	if (i == 8) // bir karakter, 1 byte (8 bit) bellekte yer kaplar. 8 bit işlendikten sonra 1 byte olacağından bellek dolar ve karakterin ekrana yazdırılıp/gerekli işlem yaptırılıp sıfırlanması gerekir
	{
		ft_putchar(c); // eğer i değişkeni 8'e ulaşırsa, c değişkeni bir çıktı işleminde kullanılır
		i = 0;  // i ve c değişkenleri sıfırlanır
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid(); // sunucu işleminin PID'sini alır.
	ft_putstr("\n\033[32mServer started\n\nServer PID : \033[0m"); // sunucu başladı mesajını yazdırır
	ft_putnbr(pid); 	// PID'yi yazdırır
	ft_putstr("\n\n");
	signal(SIGUSR1, handler);  // SIGUSR1 ve SIGUSR2 sinyallerini `handler` işlevine atar
	signal(SIGUSR2, handler);
	while (1)
		pause(); // sonsuz döngü, işlemi bekletir ve sinyal işlemcisini çalışır halde tutar
	return (0);
}
