/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:51:05 by nunnu             #+#    #+#             */
/*   Updated: 2023/12/09 13:39:13 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

// init_mandelbrot fonksiyonu, Mandelbrot fractal için başlangıç sınırlarını, maksimum iterasyon sayısını ve hesaplama fonksiyonunu belirler.
void	init_mandelbrot(t_fractal *fractal)
{
	// Mandelbrot fractal için başlangıç sınırlarını belirle (bu sınırlarda mandelbrot fractal'ı daha iyi görüntülenir)
	fractal->min_re = -2.0;
	fractal->max_re = 1.0;
	fractal->min_im = -1.5;
	fractal->max_im = 1.5;

	fractal->max_iteration = MAX_ITER; // Maksimum iterasyon sayısını belirle
	fractal->calculate_fractal = calculate_mandelbrot; // Hesaplama fonksiyonunu belirle
}

// calculate_mandelbrot fonksiyonu, Mandelbrot fractal için iterasyonları hesaplar.
// Her bir iterasyonda, gerçel ve sanal kısımları modül kontrolü yaparak günceller.
// Modül büyükse iterasyon sayısını döndürür.
// Maksimum iterasyon sayısına ulaşılırsa, maksimum iterasyonu döndürür.
int	calculate_mandelbrot(double re, double im, t_fractal *fractal)
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
		// Karelerini hesapla
		r2 = pow(r, 2);
		i2 = pow(i, 2);

		// Modül kontrolü yap, eğer büyükse iterasyonu döndür
		if ((r2 + i2) > LIMIT)
			return (iter);

		// Yeni değerleri hesapla
		i = 2 * r * i + im;
		r = r2 - i2 + re;
	}
	return (fractal->max_iteration); // Maksimum iterasyon sayısına ulaşılmışsa, maksimum iterasyonu döndür
}
