/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:50:47 by nunnu             #+#    #+#             */
/*   Updated: 2023/12/09 13:35:12 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"
#include "mlx_opengl/mlx.h"

// Bu fonksiyon, Julia Fraktalı hesaplama işlemi için kullanılan t_fractal yapısal veri türündeki bir nesnenin başlangıç değerlerini ayarlar.
// julia_re ve julia_im değerleri Julia Fraktalı'nın sabit bileşenlerini temsil eder.
// julia_fixed ise Julia Fraktalı'nın sabit olup olmadığını (mouse imleci ile birlikte fractal2ın hareket edip etmeyeceğini) belirten bir bayraktır.
void	init_julia_check(t_fractal *fractal) // Julia Fraktalı için başlangıç değerlerini ayarlayan fonksiyon
{
	fractal->julia_im = UNSET_VALUE;
	fractal->julia_re = UNSET_VALUE;
	fractal->julia_fixed = 0;
}

// Bu fonksiyon, fare hareketlerini izleyerek Julia Fraktalı'nın sabit bileşenlerini günceller.
// Eğer julia_fixed bayrağı ayarlıysa, fare hareketi sonucu elde edilen koordinatları kullanarak julia_re ve julia_im değerlerini günceller ve ardından fraktalı tekrar çizer.
// Bu işlem, kullanıcı fareyi hareket ettirdiğinde Julia Fraktalı'nın görüntüsünü dinamik olarak değiştirmek için kullanılır.
int	julia_motion(int x, int y, t_graph *graph) // Fare hareketlerine tepki veren fonksiyon
{
	t_fractal	*fractal;

	fractal = graph->fractal;
	if (fractal->julia_fixed)
	{
		// Fare koordinatlarından Julia Fraktalı'nın sabit bileşenlerini güncelle
		fractal->julia_re = 4 * ((double)x / WIN_WIDTH - 0.5);
		fractal->julia_im = 4 * ((double)(WIN_HEIGHT - y)
				/ WIN_HEIGHT - 0.5);

		// Julia Fraktalını çiz
		draw_fractal(fractal, graph);

		// Fraktalı pencereye yerleştir
		mlx_put_image_to_window(graph->mlx_ptr, graph->window,
			graph->img_ptr, START_POINT_X, START_POINT_Y);
	}
	return (0);
}

// Bu fonksiyon, Julia Fraktalı için başlangıç değerlerini ayarlar.
// Fraktalın genel sınırlarını (min_re, max_re, min_im, max_im), maksimum iterasyon sayısını (max_iteration),
// hesaplama fonksiyonunu (calculate_julia) ve başlangıçta sabit bir reel ve imaginary sayısı olmayan Julia Fraktalı'nın bileşenlerini (julia_re ve julia_im) belirler.
// Eğer başlangıçta belirli bir sabit bileşen değeri yoksa, varsayılan değerler atanır.
void	init_julia(t_fractal *fractal) // Julia Fraktalı için başlangıç değerlerini ayarlayan fonksiyon
{
	// Fraktalın genel sınırları
	fractal->min_re = -2.0;
	fractal->max_re = 2.0;
	fractal->min_im = -2.0;
	fractal->max_im = 2.0;

	//  NOT: -2.0 ve 2.0 değerleri, genellikle fraktal geometrisini incelemek için kullanılan standart bir aralıktır.
	//       Bu aralık, birçok fraktal türü için uygun bir başlangıç noktası sağlar.

	// Maksimum iterasyon sayısı
	fractal->max_iteration = MAX_ITER;

	// Fraktal hesaplama fonksiyonunu belirle
	fractal->calculate_fractal = calculate_julia;

	// Eğer Julia Fraktalı'nın başlangıç sabit bileşen değerleri belirtilmemişse, varsayılan değerleri ata
	if ((fractal->julia_re == UNSET_VALUE) || fractal->julia_im == UNSET_VALUE)
	{
		fractal->julia_re = -0.78;
		fractal->julia_im = 0.3;
	}
}

// Bu fonksiyon, Julia Fraktalı'nın hesaplanmasından sorumludur.
// Verilen koordinatlarda (re ve im) Julia Fraktalı'nın iteratif hesaplamasını gerçekleştirir ve iterasyon sayısını döndürür.
// Fraktal hesaplaması, belirli bir iterasyon sayısına veya bir sınıra ulaşıldığında sonlandırılır.
int	calculate_julia(double re, double im, t_fractal *fractal) // Julia Fraktalı'nın hesaplanmasını gerçekleştiren fonksiyon
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

	// Maksimum iterasyon sayısına ulaşana veya bir sınıra ulaşana kadar iteratif hesaplama yap
	while (++iter < fractal->max_iteration)
	{
		// Karelerini hesapla (pow komutu ile)
		r2 = pow(r, 2);
		i2 = pow(i, 2);

		// Eğer belirli bir sınıra ulaşıldıysa iterasyon sayısını döndür
		if ((r2 + i2) > LIMIT)
			return (iter);

		// Julia Fraktalı iterasyon formülü
		i = 2 * r * i + fractal->julia_im;
		r = r2 - i2 + fractal->julia_re;
	}
	// Maksimum iterasyon sayısına ulaşıldığında, maksimum iterasyon sayısını döndür
	return (fractal->max_iteration);
}
