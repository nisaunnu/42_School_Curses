/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:50:33 by nunnu             #+#    #+#             */
/*   Updated: 2023/12/09 13:51:59 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

// get_psy_color Fonksiyonu:
// Bu fonksiyon, belirli bir iterasyon sayısına göre renk üreten bir renk paletini döndürür.
// iteration parametresi, belirli bir tekrar sayısını temsil eder.
// Fonksiyon, sinüs fonksiyonları kullanarak kırmızı, yeşil ve mavi renk bileşenlerini belirler ve bu bileşenleri birleştirerek bir renk üretir.
unsigned int	get_math_color(int iteration)
{
	int	red;
	int	green;
	int	blue;

	// Iterasyon sayısına göre renk hesaplaması yapılır

	// Bu satırda, kırmızı bileşeni sin(WAVE_LENGTH_R * iteration) ifadesiyle belirlenir.
	// Burada iteration değeri, bir fraktal hesaplama iterasyon sayısını temsil eder.
	// Sinüs fonksiyonu [-1, 1] aralığında değer alabilir, bu nedenle RANGE'i ekleyerek (1 ekleyerek) sin'i [0, 2] aralığına taşırız.
	// Ardından, bu değeri RATIO_R ile çarparak istediğimiz aralığa ölçekleriz.
	// Son olarak, bu değeri 255 (RGB) ile çarparak 0 ile 255 arasında bir tam sayı elde ederiz.
	red = (int)((sin(WAVE_LENGTH_R * iteration) + RANGE) * RATIO_R * RGB);

	// Ancak, yeşil bileşenin sinüs fonksiyonu için kullanılan katsayı 0.1(WAVE_LENGTH_G)'dir, mavi bileşenin sinüs fonksiyonu için kullanılan katsayı ise 0.2(WAVE_LENGTH_B)'dir.
	// Bu, her bir bileşenin renk değişim hızını kontrol eder ve farklı dalgaboylarına sahip sinüs dalgalarını kullanarak renklerin dinamik bir şekilde değişmesini sağlar.
	// Bu sayılar, estetik tercihlere bağlı olarak seçilir ve istenen renk değişimini elde etmek için ayarlanabilir.
	green = (int)((sin(WAVE_LENGTH_G * iteration) + RANGE) * RATIO_G * RGB);
	blue = (int)((sin(WAVE_LENGTH_B * iteration) + RANGE) * RATIO_B * RGB);

	// RGB bileşenleri birleştirilerek renk oluşturulur
	return ((red << 16) | (green << 8) | blue);
}

// get_color Fonksiyonu:
// Bu fonksiyon, bir pikselin rengini belirler.
// Eğer iterasyon sayısı (iter) maksimum iterasyon sayısına (max_iter) eşitse, fonksiyon siyah rengi (0x000000) döndürür.
// Aksi takdirde, get_math_color fonksiyonu ile renk elde edilir.
// color_mode değişkeni, renk modunu kontrol eder. Eğer color_mode 1 ise, renk bitwise olarak terslenir. Eğer 2 ise, renk gri tonlamaya dönüştürülür.
int	get_color(int iter, int max_iter, t_graph *graph)
{
	unsigned int	color;
	int				grey;

	grey = 0;

	// Eğer iterasyon sayısı maksimum iterasyon sayısına eşitse siyah renk döndürülür
	if (iter == max_iter)
		return (BLACK);

	// Renk hesaplaması yapılır
	color = (get_math_color(iter));

	// Renk moduna göre işlem yapılır

	if (graph->color_mode == 1)
		color = ~color & WHITE;
	// ~color ifadesi, color değişkeninin tersini (bit düzeyinde) alır.
	// ~ operatörü, bir değişkenin bütün bitlerini tersine çevirir.
	// WHITE header kütüphanesinde 0xFFFFFF olarak tanımlanmıştır. Böyle tanımlanmasının nedeni HEX renk kodu olarak algılanması içindir.
	// & WHITE ifadesi, sadece en düşük 24 biti korur ve geri kalan bitleri sıfır yapar.
	// Bu işlem, 32 bitlik renk değerindeki en üstteki 8 biti (alfa kanalı) etkisiz hale getirir, yani sıfır yapar.
	// Sonuç olarak, color değişkeni, orijinal renk değerinin tersi alınmış ve alfa kanalı sıfır yapılmış haliyle güncellenir.

	else if (graph->color_mode == 2)
	{
		// Gri tonlamaya dönüştürme işlemi yapılır
		// color değeri bir tamsayıdır ve genellikle 0xRRGGBB biçimindedir, burada RR, GG ve BB sırasıyla kırmızı, yeşil ve mavi bileşenleri temsil eder.
		// 0xFF(LOW_BIT) değeri ile çarpma işlemi, bir tamsayının düşük sekiz bitini korumak için kullanılır.
		// İki önemli konsept bulunmaktadır: renk değerlerinin sınırları ve bit maskeleme.
		// color >> 16 ifadesi, color değerinden kırmızı bileşeni alır. "& LOW_BIT" ile bu değer 0-255 arasında sınırlanır.
		// color >> 8 ifadesi, color değerinden yeşil bileşeni alır. "& LOW_BIT" ile bu değer 0-255 arasında sınırlanır.
		// color & LOW_BIT ifadesi, color değerinden mavi bileşeni alır. Bu değer de 0-255 arasında sınırlanır.
		// Bu RGB bileşenleri, gri tonlamaya dönüştürmek için belirli ağırlıklarla toplanır.
		// Bu ağırlıklar, insan görsel algısına dayanarak seçilmiştir. Yani, kırmızının insan gözünde daha düşük bir ağırlığı vardır, yeşil ve mavi ise daha yüksektir.
		// Bu nedenle, her bileşen farklı bir ağırlıkla çarpılarak toplanır.
		// LUMA_R * ((color >> 16) & LOW_BIT): Kırmızı bileşenin ağırlıklı değeri.
		// LUMA_G * ((color >> 8) & LOW_BIT): Yeşil bileşenin ağırlıklı değeri.
		// LUMA_B * (color & LOW_BIT): Mavi bileşenin ağırlıklı değeri.
		// Bu ağırlıklar, gri tonlama için standart bir formül olan Luma (Y') dönüşümünü temsil eder.
		// Bu ağırlıklı değerler toplanarak grey adlı bir değişken elde edilir. Bu değişken, gri tonlamaya dönüştürülmüş renk değerini temsil eder.
		grey = (int)(LUMA_R * ((color >> 16) & LOW_BIT) + LUMA_G * ((color >> 8)
					& LOW_BIT) + LUMA_B * (color & LOW_BIT));

		// Son olarak, color değeri gri tonlamaya dönüştürülen grey değeriyle güncellenir.
		// grey değeri, kırmızı, yeşil ve mavi bileşenlere eşit olduğu için, yeni renk değeri gri tonlamaya dönüştürülmüş olur.
		color = (grey << 16) | (grey << 8) | grey;
	}

	// Renk döndürülür
	return (color);
}

// put_pixel_to_image Fonksiyonu:
// Bu fonksiyon, bir pikselin rengini belirli bir koordinata yerleştirir.
// Koordinatlar (x ve y) pencerenin sınırları içindeyse, ilgili piksele renk atanır.
void	put_pixel_to_image(t_graph *graph, int x, int y, int color)
{
	char	*dst;

	// Eğer koordinatlar geçerliyse
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		// Pencere üzerindeki konumu hesapla
		dst = graph->addr + (y * graph->line_lenght + x
				* (graph->bits_per_pixel / 8));

		// Renk bilgisini ata
		*(unsigned int *)dst = color;
	}
}

// draw_fractal Fonksiyonu:
// Bu fonksiyon, belirtilen bir fractalın grafiğini çizer.
// İki iç içe döngü kullanılarak her pikselin koordinatları hesaplanır (x ve y).
// Her pikselin gerçek ve sanal kısmı (re ve im) fractal hesaplama fonksiyonuna geçirilir.
// Hesaplanan iterasyon sayısı ve diğer parametreler kullanılarak bir renk elde edilir.
// Elde edilen renk, put_pixel_to_image fonksiyonu aracılığıyla ilgili piksele atanır.
void	draw_fractal(t_fractal *fractal, t_graph *graph)
{
	int		x;
	int		y;
	int		iter;
	double	re;
	double	im;

	y = 0;

	// Her y koordinatı için
	while (y < WIN_HEIGHT)
	{
		x = 0;

		// Her x koordinatı için
		while (x < WIN_WIDTH)
		{
			// Gerçek ve sanal kısmı hesapla
			re = fractal->min_re + (fractal->max_re - fractal->min_re)
				* x / WIN_WIDTH;
			im = fractal->min_im + (fractal->max_im - fractal->min_im)
				* y / WIN_HEIGHT;

			// Fractal hesaplaması yap ve iterasyon sayısını al
			iter = fractal->calculate_fractal(re, im, fractal);

			// Renk hesapla
			fractal->color = get_color(iter, fractal->max_iteration, graph);

			// Pikseli ilgili renkle doldur
			put_pixel_to_image(graph, x, y, fractal->color);
			x++;
		}
		y++;
	}
}
