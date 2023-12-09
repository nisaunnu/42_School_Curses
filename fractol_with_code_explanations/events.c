/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:50:37 by nunnu             #+#    #+#             */
/*   Updated: 2023/12/07 15:33:17 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_opengl/mlx.h"

// handle_arrow_keys fonksiyonu, ok tuşlarına göre fractalın görüntüsünü hareket ettirir.
// move_step değişkeni, her tuşa basıldığında yapılacak hareketin büyüklüğünü belirler.
void	handle_arrow_keys(int keycode, t_graph *graph)
{
	double	move_step;

	// Hareket adım büyüklüğünü hesapla
	move_step = (graph->fractal->max_re - graph->fractal->min_re) * 0.02;

	// Klavye tuşuna göre hareketi gerçekleştir
	if (keycode == KEY_UP)
	{
		graph->fractal->min_im -= move_step;
		graph->fractal->max_im -= move_step;
	}
	else if (keycode == KEY_DOWN)
	{
		graph->fractal->min_im += move_step;
		graph->fractal->max_im += move_step; 
	}
	else if (keycode == KEY_LEFT)
	{
		graph->fractal->min_re -= move_step;
		graph->fractal->max_re -= move_step;
	}
	else if (keycode == KEY_RIGHT)
	{
		graph->fractal->min_re += move_step;
		graph->fractal->max_re += move_step;
	}
}

// handle_key_press fonksiyonu, klavye tuşlarına basılmasını ele alır.
// ESC tuşuna basılırsa cleanup fonksiyonunu çağırarak programı sonlandırır.
// SPACE tuşuna basılırsa Julia setin sabit noktasını değiştirir.
// C tuşuna basılırsa renk modunu değiştirir.
// Yukarı, aşağı, sol, sağ ok tuşlarına basılırsa handle_arrow_keys fonksiyonunu çağırarak görüntüyü hareket ettirir.
int	handle_key_press(int keycode, t_graph *graph)
{
	// ESC tuşuna basılırsa programı sonlandır
	if (keycode == KEY_ESC)
		cleanup(graph);

	// SPACE tuşuna basılırsa Julia setin sabit noktasını değiştir
	else if (keycode == KEY_SPACE)
		graph->fractal->julia_fixed = !graph->fractal->julia_fixed;

	// C tuşuna basılırsa renk modunu değiştir
	else if (keycode == KEY_C)
		graph->color_mode = (graph->color_mode + 1) % 3;

	 // Yukarı, aşağı, sol, sağ ok tuşlarına basılırsa fraktalın görüntüsünü (handle_arrow_keys fonksiyonu sayesinde) hareket ettir
	else if (keycode == KEY_UP || keycode == KEY_DOWN
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		handle_arrow_keys(keycode, graph);

	draw_fractal(graph->fractal, graph); // Fractalı tekrar çiz

	// Çizilen fractalı pencereye yerleştir
	mlx_put_image_to_window(graph->mlx_ptr, graph->window,
		graph->img_ptr, START_POINT_X, START_POINT_Y);

	return (0); // İşlemin başarılı olduğunu döndür
}

// handle_close fonksiyonu, pencere kapatılma olayını ele alır.
// Parametre olarak gelen pointer'ı (param) grafik nesnesine çevirir.
// cleanup fonksiyonunu çağırarak programı sonlandırır.
int	handle_close(void *param)
{
	t_graph	*graph;

	graph = (t_graph *)param; // Parametre olarak gelen pointer'ı grafik nesnesine çevir
	cleanup(graph); // Cleanup fonksiyonunu çağırarak programı sonlandır
	return (0);
}

// handle_mouse_scroll fonksiyonu, fare tekerleğinin yukarı veya aşağı kaydırılmasını ele alır.
// Fare tekerleği yukarı kaydırılırsa, zoom_factor'ü 0.9 olarak ayarlar.
// Fare tekerleği aşağı kaydırılırsa, zoom_factor'ü 1.1 olarak ayarlar.
// Diğer durumlarda işlemi sonlandırır.
// Zoom parametrelerini hesaplar ve fractal sınırlarını günceller.
// Fractali tekrar çizer ve çizilen fractali pencereye yerleştirir.
int	handle_mouse_scroll(int button, int x, int y, t_graph *graph)
{
	t_fractal	*fractal;
	t_zoom		zoom;

	// Graph nesnesinin içindeki fractal ve zoom yapılarını al
	fractal = graph->fractal;
	zoom.mouse_re = (double)x / (WIN_WIDTH / (fractal->max_re
				- fractal->min_re)) + fractal->min_re;
	zoom.mouse_im = (double)y / (WIN_HEIGHT / (fractal->max_im
				- fractal->min_im)) + fractal->min_im;

	if (button == SCROLL_UP) // Fare tekerleği yukarı kaydırılırsa, zoom_factor'ü 0.9 olarak ayarlanır ve fractal yakınlaştırılır
		zoom.zoom_factor = 0.9;
	else if (button == SCROLL_DOWN) // Fare tekerleği aşağı kaydırılırsa, zoom_factor'ü 1.1 olarak ayarlanır ve fractal uzaklaştırılır
		zoom.zoom_factor = 1.1;
	else
		return (0);

	// Zoom parametrelerini hesapla
	zoom.range_re = (fractal->max_re - fractal->min_re) * zoom.zoom_factor;
	zoom.range_im = (fractal->max_im - fractal->min_im) * zoom.zoom_factor;

	// Fractal sınırlarını güncelle
	fractal->min_re = zoom.mouse_re - (x / (double)WIN_WIDTH) * zoom.range_re;
	fractal->max_re = fractal->min_re + zoom.range_re;
	fractal->min_im = zoom.mouse_im - (y / (double)WIN_HEIGHT) * zoom.range_im;
	fractal->max_im = fractal->min_im + zoom.range_im;

	// Fractali tekrar çiz
	draw_fractal(fractal, graph);

	// Çizilen fractalı pencereye yerleştir
	mlx_put_image_to_window(graph->mlx_ptr, graph->window, graph->img_ptr,
		START_POINT_X, START_POINT_Y);
	return (0);
}

// setup_hooks fonksiyonunda MiniLibX'in pencere olaylarını yöneten hook fonksiyonları atanır.
// mlx_hook fonksiyonu ile pencerenin çeşitli olaylarına karşılık gelen fonksiyonlar atanır.
void	setup_hooks(t_graph *graph)
{
	// Pencere olaylarını yöneten hook fonksiyonları atanır

	// 2: Key Press olayını temsil eden bir değer.
	// 1L << 0: Bu, birinci tuşu ifade eder (solmost bit, sol tarafta 0'dır, diğer tüm bitler 1'dir). 1L << n genellikle 2^n'e eşdeğerdir. Burada, 2^0 = 1'i ifade eder.
	// handle_key_press: Key Press olayı gerçekleştiğinde çağrılacak olan fonksiyonun adı.
	// graph: Fonksiyona geçirilen ekstra veri (grafik bağlamı).
	mlx_hook(graph->window, 2, 1L << 0, handle_key_press, graph);

	// 17: Window Close olayını temsil eden bir değer.
	// 0L: Tuşa basma olaylarının uyandırılma sırasında başka bir olayın etkilenmemesi için kullanılan bir masked değer (0L burada tüm bitlerin 0 olduğunu belirtir).
	// handle_close: Window Close olayı gerçekleştiğinde çağrılacak olan fonksiyonun adı.
	// graph: Fonksiyona geçirilen ekstra veri (grafik bağlamı).
	mlx_hook(graph->window, 17, 0L, handle_close, graph);

	// 4: Mouse Scroll olayını temsil eden bir değer.
	// 0L: Mouse olaylarının uyandırılma sırasında başka bir olayın etkilenmemesi için kullanılan bir masked değer (0L burada tüm bitlerin 0 olduğunu belirtir).
	// handle_mouse_scroll: Mouse Scroll olayı gerçekleştiğinde çağrılacak olan fonksiyonun adı.
	// graph: Fonksiyona geçirilen ekstra veri (grafik bağlamı).
	mlx_hook(graph->window, 4, 0L, handle_mouse_scroll, graph);

	// 6: Mouse Motion olayını temsil eden bir değer.
	// 0L: Mouse olaylarının uyandırılma sırasında başka bir olayın etkilenmemesi için kullanılan bir masked değer (0L burada tüm bitlerin 0 olduğunu belirtir).
	// julia_motion: Mouse Motion olayı gerçekleştiğinde çağrılacak olan fonksiyonun adı.
	// graph: Fonksiyona geçirilen ekstra veri (grafik bağlamı).
	mlx_hook(graph->window, 6, 0L, julia_motion, graph);
}
