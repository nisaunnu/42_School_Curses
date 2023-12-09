/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:50:43 by nunnu             #+#    #+#             */
/*   Updated: 2023/12/08 14:46:20 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define MAX_ITER 80

# define KEY_C 8
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_SPACE 49

# define SCROLL_UP 5
# define SCROLL_DOWN 4

# define LUMA_R 0.299
# define LUMA_G 0.587
# define LUMA_B 0.114
# define LOW_BIT 0xFF

# define WAVE_LENGTH_R 0.1
# define WAVE_LENGTH_G 0.1
# define WAVE_LENGTH_B 0.2

# define RATIO_R 0.2
# define RATIO_G 0.4
# define RATIO_B 0.5
# define RANGE 1
# define RGB 255

# define LIMIT 6.0

# define BLACK 0x000000
# define WHITE 0xFFFFFF

# define START_POINT_X 0
# define START_POINT_Y 0

# define UNSET_VALUE 123456789.0

typedef struct s_fractal	t_fractal;

typedef int					(*t_fractal_func)(double re, double im,
								t_fractal *fractal);

typedef struct s_zoom
{
	double	zoom_factor;
	double	mouse_re;
	double	mouse_im;
	double	range_re;
	double	range_im;
}			t_zoom;

typedef struct s_graph
{
	void		*mlx_ptr;
	void		*window;
	char		*window_title;
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
	int			color_mode;
	t_fractal	*fractal;
}				t_graph;

typedef struct s_fractal
{
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	double			julia_re;
	double			julia_im;
	int				max_iteration;
	int				julia_fixed;
	int				color;
	t_fractal_func	calculate_fractal;
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
