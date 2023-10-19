/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:33:21 by nunnu             #+#    #+#             */
/*   Updated: 2023/10/19 17:30:49 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>

static void	data_transmission(char data, int pid)
{
	// data, char olarak tanımlı olduğundan bellekte 1 byte'lık yer kaplar
	// SIGUSR1 ve SIGUSR2 sinyallerini kullandığımızdan veri gönderilirken bit şeklinde gönderilmesi gerekmektedir
	// karakterin (data) her bir biti, sırayla SIGUSR1 veya SIGUSR2 sinyali olarak temsil edilerek iletilir
	int	i; // bitlerin basamak sayısını saymak için tanımlandı
	int	error; // kill fonksiyonunun dönüş değerini saklayıp hata kontrolü yapmak için tanımlandı

	i = 0;
	error = 0;
	while (i < 8) // 1 byte = 8 bit olduğundan 0'dan 7'ye kadar (7 dahil) işlemi döndürür
	{
		if (data << i & 0b10000000) // verinin belirli bir biti (en solundaki biti - MSB) kontrol ediyoruz
			error = kill(pid, SIGUSR1); // eğer bu bit 1 ise (verinin en yüksek değeri temsil ediyor), SIGUSR1 sinyali gönderilir.
		else
			error = kill(pid, SIGUSR2); // eğer bu bit 0 ise, SIGUSR2 sinyali gönderilir.
		i++;
		usleep(250); // usleep, belirtilen süre boyunca (250 mikrosaniye) işlemi duraklatır
	}
	if (error == -1) // hata kontrolü gerçekleştirilir
	{
		ft_putstr("\n\033[31mCLIENT PID error : "); // eğer kill işlemi hata verirse, hata mesajı yazdırılır
		ft_putstr("Incorrect PID entered\033[0\n\n");
		exit(1); // program çıkış kodu olarak 1 ile sonlandırılır
	}
}

int	main(int ac, char **av)
{
	int	pid; // PID'yi bir değişkene atamak için tanımlandı
	int	i; // index için tanımlı

	i = 0;
	if (ac == 3) // argüman olarak PID ve gönderilecek string'in girilip girilmediğini kontrol eder
	{
		pid = ft_atoi(av[1]); // argüman olarak girilen PID değeri, işlem yapılabilmesi için ft_atoi ile integer'a dönüştürülür
		while (av[2][i]) // girilen string'teki i'inci karakter boş değilse döngüye girilir
			data_transmission(av[2][i++], pid); // veri gönderimi için PID ve i'inci karakter data_transmission fonksiyonuna gönderilir
	}
	else
	{
		ft_putstr("\n\033[31mCLIENT format error : invalid arguments\033[0m\n"); // yanlış format girilmesi durumunda verilen hata mesajıdır
		ft_putstr("\n\033[33mCorrect format : ./client <PID> <STRING_TO_SEND>"); // doğru girdi formatı gösterilmektedir
		ft_putstr("\033[0m\n\n");
	}
}
