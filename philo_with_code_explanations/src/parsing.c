/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:54:53 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/10 18:30:02 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

// Belirtilen string içindeki sayıları toplayan ve sonucu güncelleyen yardımcı fonksiyon
static void	plus_and_minus_calculate(char *str, size_t *number)
{
	// eğer önceki karakter '+' ise, mevcut sayıyı 10 ile çarpar ve yeni rakamı ekler.
	if (*(str - 1) == '+')
		*number = (is_digit(*(str - 1)) * (*number * 10)) + (*str - '0');
	else // aksi takdirde, sadece yeni rakamı ekler.
		*number = (*number * 10) + (*str - '0');
}

// Belirtilen string'in bir `size_t` türüne dönüştürülebilir olup olmadığını kontrol eden ve dönüşümü gerçekleştiren fonksiyon
static int	is_sizet(char *str, size_t *result)
{
	size_t			number;

	// ilk karakter '-' veya '+' ise ve bir sonraki karakter '0' veya boşsa sayıyı hesaplama
	if ((*str == '-' || *str == '+') && (!*(str + 1) || *(str + 1) == '0'))
		return (-1);

	// eğer ilk karakter '0' ise ve başka karakter varsa sayıyı hesaplama
	if (*str == '0' && *(str + 1))
		return (-1);

	// eğer string sayısal değilse veya dönüştürülemez bir değer içeriyorsa sayıyı hesaplama
	if (!is_numeric(str))
		return (-1);

	number = *str - '0';
	while (*(++str)) // string üzerinde dolaşarak sayıyı oluşturur.
	{
		if (!(is_digit(*str))) // eğer karakter sayısal değilse sayıyı hesaplama
			return (-1);
		if (*(str - 1) == '-' && *str == '0') // önceki karakter '-' ve mevcut karakter '0' ise sayıyı hesaplama
			return (-1);
		plus_and_minus_calculate(str, &number); // sayıyı güncelleyen yardımcı fonksiyonu çağır
		if (!(UNSIGNED_INT_MAX >= number)) // dönüştürülen sayı `size_t` sınırları içinde mi kontrol et
			return (-1);
	}
	*result = (number); // dönüştürülen sayıyı sonuç olarak güncelle
	return (SUCCESS);
}

// Komut satırı argümanlarını kontrol eden fonksiyon
static int	arg_check(int ac, char **av)
{
	int		i;
	size_t	number;

	i = 0;
	while (++i < ac) // argümanların geçerliliğini kontrol et
	{
		if (!av[i] || (is_sizet(av[i], &number) == -1)) // eğer argüman boşsa veya dönüştürülemez bir değer içeriyorsa dönüş başarısız olur
			return (FAILURE);
		if (number <= 0) // eğer dönüştürülen sayı 0 veya daha küçükse dönüş başarısız olur
			return (FAILURE);
	}
	return (SUCCESS);
}

// Komut satırı argümanlarını ayrıştırarak kontrol eden fonksiyon
int	parsing(int ac, char **av)
{
	if (ac < 2) // eğer argüman sayısı yetersizse, hata mesajını yazdır ve FAILURE döndür
		return (ft_putstr_fd(ERR_USE, ERR_FILENO), FAILURE);
	if (ac < 5 || 6 < ac) // eğer argüman sayısı uygun değilse, hata mesajını yazdır ve FAILURE döndür
		return (ft_putstr_fd(ERR_ARG, ERR_FILENO), FAILURE);
	if (arg_check(ac, av)) // argümanların geçerliliğini kontrol eden fonksiyonu çağır
		return (ft_putstr_fd(ERR_NUM, ERR_FILENO), FAILURE);
	return (SUCCESS);
}
