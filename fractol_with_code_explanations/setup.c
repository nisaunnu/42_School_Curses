/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:51:14 by nunnu             #+#    #+#             */
/*   Updated: 2023/12/06 15:11:51 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"
#include "mlx_opengl/mlx.h"

// Bu fonksiyon, program sonlandırıldığında veya bir hata durumunda çağrılır.
// Öncelikle, grafik nesnesinin (graph) içindeki img_ptr (image pointer) değeri varsa, bu img_ptr için ayrılmış belleği serbest bırakır.
// Ardından pencere (window) varsa, pencereyi kapatır ve bağlı olduğu grafik nesnesinin pencere işaretçisini (window) NULL'a ayarlar.
// Son olarak, exit(0) fonksiyonu ile programdan çıkılır.
void	cleanup(t_graph *graph)
{
	if (graph->img_ptr && graph->img_ptr) // Eğer image pointer (img_ptr) varsa
	{
		mlx_destroy_image(graph->mlx_ptr, graph->img_ptr); // Image pointer için ayrılan belleği serbest bırak
		graph->window = NULL; // Grafik nesnesinin pencere işaretçisini NULL'a ayarla
	}
	if (graph->window && graph->window) // Eğer pencere (window) varsa
	{
		mlx_destroy_window(graph->mlx_ptr, graph->window); // Pencereyi kapat
		graph->window = NULL; // Grafik nesnesinin pencere işaretçisini NULL'a ayarla
	}
	exit(EXIT_SUCCESS); // Programı sonlandır
}

// Bu fonksiyon, bir grafik nesnesinin (graph) içindeki img_ptr'yi (image pointer) başlatır.
// Eğer mlx_new_image fonksiyonu başarısız olursa, bir hata mesajı yazdırılır ve program EXIT_FAILURE ile sonlandırılır.
// Ardından, mlx_get_data_addr fonksiyonu ile image pointer'ın adresini (addr) alır.
// Bu bilgi, daha sonra grafik işlemlerinde kullanılır.
void	init_img(t_graph *graph)
{
	graph->img_ptr = mlx_new_image(graph->mlx_ptr, WIN_WIDTH, WIN_HEIGHT); // Image pointer'ı başlat
	if (!graph->img_ptr) // Eğer mlx_new_image fonksiyonu başarısız olursa
	{
		ft_putstr_fd("\n\033[31mError : mlx_new_image failed\033[0m\n", 2); // Hata mesajı yazdır
		exit(EXIT_FAILURE); // Programı EXIT_FAILURE ile sonlandır
	}

	// Image pointer'ın adresini (addr) al
	graph->addr = mlx_get_data_addr(graph->img_ptr,
			&(graph->bits_per_pixel), &(graph->line_lenght), &(graph->endian));
}

// Bu fonksiyon, grafik arayüzünü başlatmak için kullanılır.
// İlk olarak, MinilibX bağlamını başlatır (mlx_init). Başlatma başarılı olmazsa, fonksiyon EXIT_FAILURE ile sonlanır.
// Daha sonra, bir pencere başlığı belirlenir ve mlx_new_window fonksiyonu ile bir pencere oluşturulur.
// Pencere oluşturma başarısız olursa, fonksiyon yine EXIT_FAILURE ile sonlanır. Son olarak, init_img fonksiyonu çağrılarak image pointer'ı ve ilgili bilgileri başlatılır.
int	gui_setup(t_graph *graph)
{
	graph->mlx_ptr = mlx_init(); // MinilibX bağlamını başlat

	// Başlatma başarılı olmazsa EXIT_FAILURE ile fonksiyonu sonlandır
	if (!graph->mlx_ptr)
		return (EXIT_FAILURE);

	graph->window_title = "42 FRACT'OL BY NUNNU"; // Pencere başlığını belirle

	// mlx_new_window fonksiyonu ile bir pencere oluştur
	graph->window = mlx_new_window(graph->mlx_ptr,
			WIN_WIDTH, WIN_HEIGHT, graph->window_title);

	// Pencere oluşturma başarısız olursa EXIT_FAILURE ile fonksiyonu sonlandır
	if (!graph->window)
		return (EXIT_FAILURE);

	init_img(graph); // init_img fonksiyonunu çağırarak image pointer'ı ve ilgili bilgileri başlat
	return (EXIT_SUCCESS); // Başarı durumunu döndür
}
