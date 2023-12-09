/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:50:55 by nunnu             #+#    #+#             */
/*   Updated: 2023/12/06 15:11:38 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fractol.h"
#include "mlx_opengl/mlx.h"

int	main(int ac, char **av)
{
	int			check; // Julia fractal'ının girilip girilmediğini  kontrol etmek için tanımlanır.
	t_graph		graph; // pencerenin ve resmin özelliklerini tutar.
	t_fractal	fractal; // fractal'ların reel ve imaginary sayılarını, renklerini, hesaplarını tutmak için tanımlanır.

	check = ((ac == 4) && (ft_strcmp(av[1], "Julia") == 0)); // Argüman sayısı 4 ise Julia fractalının reel ve imaginary değerleri girilmiş olmalıdır. Fractal olarak Mandelbrot ve Burning_ship yazılma ihtimaline karşın fraktalın Julia olup olmadığı kontrol edilir.
	init_julia_check(&fractal); // Julia'nın reel ve imaginary sayıları yoksa diye rastgele değer ataması gerçekleştiriyoruz. (Olası bir kullanma ihtimaline karşın)
	if (gui_setup(&graph) == EXIT_FAILURE) // mlx başlatma, yeni pencere oluşturma ve yeni resim oluşturma yapılır.
		return (EXIT_FAILURE); // Eğer ki başlatmalar olmazsa EXIT_FAILURE döndürülür.
	graph.fractal = &fractal; // graph'ta yer alan fractalın içerisine kendi oluşturduğumuz fractalın adresini gönderiyoruz.
	if (check) // Eğer check 1 ise julia'nın reel ve imaginary değerlerinin fractal'daki reel ve imaginary'ye ataması gerçekleştirilir.
	{
		fractal.julia_re = ft_atof(av[2]); // julia'nın reel sayısı atof fonksiyonu kullanarak ascii'yi float sayısına dönüştürüyoruz.
		fractal.julia_im = ft_atof(av[3]); // julia'nın imaginary sayısı atof fonksiyonu kullanarak ascii'yi float sayısına dönüştürüyoruz.
	}

	// Argüman sayısı 2 ise: Mandelbrot ya da Burning_ship fractalı girilmiştir veya Julia fractalı girilip imaginary ve reel sayıları girilmemiş olabilir.
	//select_fractal ile hangi fractalın girildiğini kontrol edip o fraktala ait işlemler gerçekleştirilir.
	if ((ac == 2 || check == 1) && select_fractal(av[1], &fractal))
	{
		draw_fractal(&fractal, &graph); // Fractalın işlemleri bittikten sonra fractalın çizimi yapılır. Görüntüye pixeller eklenerek bir resim oluşturulur.

		// Yapılan bu resim önceden açtığımız pencereye gönderilir.
		mlx_put_image_to_window(graph.mlx_ptr, graph.window, graph.img_ptr,
			START_POINT_X, START_POINT_Y);

		setup_hooks(&graph); // Yön tuşları ile hareket etme, mouse hareketleri gibi özellikler ayarlanır.

		// mlx_loop; pencerenin açık kalmasını, kullanıcının etkeleşimlerine tepki vermeyi, pencere içeriğini güncellemeyi sağlayan bir döngü oluşturur.
		// Bu döngü içinde pencerenin durumunu takip eder ve olaylar gerçekleştiğinde belirli fonksiyonları çağırır.
		mlx_loop(graph.mlx_ptr);
	}
	else
		error_message(); // Yanlış veya eksik bir argüman girildiğinde ekrana hata mesajı yazdırılır.
	return (EXIT_SUCCESS);
}
