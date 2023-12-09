/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:50:26 by nunnu             #+#    #+#             */
/*   Updated: 2023/12/09 13:43:08 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

// init_burning_ship fonksiyonu, Burning Ship fractal için başlangıç sınırlarını, maksimum iterasyon sayısını ve hesaplama fonksiyonunu belirler.
void	init_burning_ship(t_fractal *fractal)
{
	// Burning Ship fractal için başlangıç sınırlarını belirle
	fractal->min_re = -2.0;
	fractal->max_re = 1.5;
	fractal->min_im = -2.0;
	fractal->max_im = 1.0;

	// Maksimum iterasyon sayısını belirle
	fractal->max_iteration = MAX_ITER;

	// Hesaplama fonksiyonunu belirle
	fractal->calculate_fractal = calculate_burning_ship;
}

// calculate_burning_ship fonksiyonu, Burning Ship fractal için iterasyonları hesaplar.
// Her bir iterasyonda, gerçel ve sanal kısımları modül kontrolü yaparak günceller.
// Modül büyükse iterasyon sayısını döndürür.
// Maksimum iterasyon sayısına ulaşılırsa, maksimum iterasyonu döndürür.
int	calculate_burning_ship(double re, double im, t_fractal *fractal)
{
	int		iter;
	double	r;
	double	i;
	double	r2;
	double	i2;

	// İterasyon sayısını sıfıra başlat
	iter = -1;

	// Başlangıçta gerçel ve sanal kısımları r ve i'ye ata
	r = re;
	i = im;

	// Maksimum iterasyon sayısına kadar devam et
	while (++iter < fractal->max_iteration)
	{
		// Gerçel ve sanal kısımları mutlak değere al
		r = fabs(r);
		i = fabs(i);

		// Karelerini hesapla
		r2 = pow(r, 2);
		i2 = pow(i, 2);

		// Modül kontrolü yap, eğer LIMIT sınırından büyükse iterasyonu döndür
		if ((r2 + i2) > LIMIT)
			return (iter);

		// Yeni değerleri hesapla
		i = 2 * r * i + im;
		r = r2 - i2 + re;
	}

	// Maksimum iterasyon sayısına ulaşılmışsa, maksimum iterasyonu döndür
	return (fractal->max_iteration);
}
