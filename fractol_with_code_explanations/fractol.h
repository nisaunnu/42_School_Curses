/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:50:43 by nunnu             #+#    #+#             */
/*   Updated: 2023/12/09 13:57:56 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 800	// Pencerinin genişliği
# define WIN_HEIGHT 800	// Pencerinin yüksekliği
# define MAX_ITER 80	// Tekrar edilecek sayı

# define KEY_C 8 		// "C" tuşu
# define KEY_ESC 53		// "ESC" tuşu
# define KEY_UP 126		// Yukarı ok tuşu
# define KEY_DOWN 125	// Aşağı ok tuşu
# define KEY_LEFT 123	// Sol ok tuşu
# define KEY_RIGHT 124	// Sağ ok tuşu
# define KEY_SPACE 49	// "SPACE" tuşu

# define SCROLL_UP 5	// Fare tekerleğinin yukarı kaydırılması olayı
# define SCROLL_DOWN 4	// Fare tekerleğinin aşağı kaydırılması olayı

# define LUMA_R 0.299	// Kırmızı renginin LUMA katsayısı
# define LUMA_G 0.587	// Yeşil renginin LUMA katsayısı
# define LUMA_B 0.114	// Mavi renginin LUMA katsayısı
# define LOW_BIT 0xFF	// En düşük 8 biti maskelemeyen makro

# define WAVE_LENGTH_R 0.1	// Kırmızı renginin dalga boyu
# define WAVE_LENGTH_G 0.1	// Yeşil renginin dalga boyu
# define WAVE_LENGTH_B 0.2	// Mavi renginin dalga boyu

# define RATIO_R 0.2	// Kırmızı renginin hangi oranda renk olarak kullanılacağı
# define RATIO_G 0.4	// Yeşil renginin hangi oranda renk olarak kullanılacağı
# define RATIO_B 0.5	// Mavi renginin hangi oranda renk olarak kullanılacağı
# define RANGE 1		// Sinüs fonksiyonunun değer aralığının 1 arttırılmasında kullanılır
# define RGB 255		// Hesaplanılan rengin RGB renk değer aralığına getirir

# define LIMIT 6.0		// Fraktal hesaplaması yapılırken kullanılan LIMIT değeri

# define BLACK 0x000000	// Siyah renginin HEX kodu tanımlanır
# define WHITE 0xFFFFFF	// Beyaz renginin HEX kodu tanımlanır

# define START_POINT_X 0 // mlx_put_to_image ve mlx_put_image_to_window fonksiyonlarında kullanılır
# define START_POINT_Y 0 // mlx_put_to_image ve mlx_put_image_to_window fonksiyonlarında kullanılır

# define UNSET_VALUE 123456789.0 // Belirli bir değeri temsil etmek için kullanılan özel bir değer

typedef struct s_fractal	t_fractal;

// Fraktalı hesaplamak için kullanılan fonksiyon tipi
typedef int					(*t_fractal_func)(double re, double im,
								t_fractal *fractal);

typedef struct s_zoom 		// Zoom işlemleri için kullanılan struct
{
	double	zoom_factor;	// Zoom faktörü
	double	mouse_re;		// Fare konumuna karşılık gelen gerçel (real) kısım
	double	mouse_im;		// Fare konumuna karşılık gelen sanal (imaginary) kısım
	double	range_re;		// Yeni gerçel (real) kısım aralığı
	double	range_im;		// Yeni sanal (imaginary) kısım aralığı
}			t_zoom;

typedef struct s_graph				// Grafiksel öğeleri içeren ana struct
{
	void		*mlx_ptr;			// MinilibX bağlamı işaretçisi
	void		*window;			// Pencere işaretçisi
	char		*window_title;		// Pencere başlığı
	void		*img_ptr;			// Image işaretçisi
	char		*addr;				// Image'nin bellekteki adresi
	int			bits_per_pixel;		// Image'deki her pikselin bit sayısı
	int			line_lenght;		// Image'nin satır uzunluğu
	int			endian;				// Image'nin byte sıralama düzeni
	int			color_mode;			// Renk modu
	t_fractal	*fractal;			// İlgili fraktalın veri struct'ı
}				t_graph;

typedef struct s_fractal				// Bir Fraktal'ı temsil eden ana veri struct'ı
{
	double			min_re;				// Gerçel (real) kısmın minimum değeri
	double			max_re;				// Gerçel (real) kısmın maksimum değeri
	double			min_im;				// Sanal (imaginary) kısmın minimum değeri
	double			max_im;				// Sanal (imaginary) kısmın maksimum değeri
	double			julia_re;			// Julia kümesi için gerçel (real) kısım
	double			julia_im;			// Julia kümesi için sanal (imaginary) kısım
	int				max_iteration;		// Maksimum iterasyon sayısı
	int				julia_fixed;		// Julia kümesi sabit mi (1) yoksa değişken mi (0) (SPACE tuşuna basılıp basılmadığını takip eden bayrak)
	int				color;				// Fraktalın renk değeri
	t_fractal_func	calculate_fractal;	// Fraktalı hesaplamak için kullanılan fonksiyon
}			t_fractal;

// LIBFT_UTILS
int		ft_isdigit(int c);
double	ft_atof(char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_skip_space_sign(char *str, int *is_neg);

// JULIA
void	init_julia(t_fractal *fractal);
void	init_julia_check(t_fractal *fractal);
int		julia_motion(int x, int y, t_graph *graph);
int		calculate_julia(double re, double im, t_fractal *fractal);

// MANDELBROT
void	init_mandelbrot(t_fractal *fractal);
int		calculate_mandelbrot(double re, double im, t_fractal *fractal);

// BURNING_SHIP
void	init_burning_ship(t_fractal *fractal);
int		calculate_burning_ship(double re, double im, t_fractal *fractal);

// SETUP
void	cleanup(t_graph *graph);
void	init_img(t_graph *graph);
int		gui_setup(t_graph *graph);

// PARSING
void	error_message(void);
void	examples_julia_sets(void);
int		select_fractal(char *fractal_name, t_fractal *fractal);

// DRAW
void	draw_fractal(t_fractal *fractal, t_graph *graph);
int		get_color(int iter, int max_iter, t_graph *graph);
void	put_pixel_to_image(t_graph *graph, int x, int y, int color);

// EVENTS
int		handle_close(void *param);
void	setup_hooks(t_graph *graph);
int		handle_key_press(int keycode, t_graph *graph);
void	handle_arrow_keys(int keycode, t_graph *graph);
int		handle_mouse_scroll(int button, int x, int y, t_graph *graph);

#endif
