/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:54:20 by nunnu             #+#    #+#             */
/*   Updated: 2024/02/10 17:54:21 by nunnu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>

# define NO 0
# define YES 1
# define FAILURE 1
# define SUCCESS 0
# define ERR_FILENO 2
# define UNSIGNED_INT_MAX 4294967295

# define ERR_INIT_TABLE "\n\tInitialization Error : \
Table initialization failure\n"
# define ERR_INIT_MUTEX "\n\tInitialization Error : \
Mutex initialization failure\n"
# define ERR_INIT_PHILO "\n\tInitialization Error : \
Philosopher initialization failure\n"
# define ERR_JOIN_THREAD "\n\tThread Error : Failed to join new thread\n"
# define ERR_THREAD "\n\tThread Error : Failed to create new thread\n"
# define ERR_USE "\033[33m\n\tUsage : ./philo <number1> <number2> <number3> \
<number4> <number5>\n"
# define ERR_ARG "\033[31m\n\tParameter Error : Invalid number of parameters\n"
# define ERR_NUM "\033[31m\n\tNumber Error : Non-positive or non-zero numbers\n"

typedef struct s_philo
{
	unsigned int	id;						// Felsefeci kimliği
	unsigned int	forks[2];				// Felsefeciye ait iki çatal
	pthread_mutex_t	eating_mutex;			// Yeme işlemini kontrol etmek için mutex
	unsigned int	meals_count;			// Toplam yenmesi gereken yemek sayısı
	long long		time_to_meal;			// Bir yemek süresi
	int				return_mutex_eating;	// Yeme işlemi için init'lenen mutex'in dönüş değerini tutan değişken
	pthread_t		thread;					// Felsefeciye ait iş parçacığı (thread)
	struct s_table	*table_rules;			// Felsefeciye ait yemek masası kuralları
}	t_philo;

typedef struct s_table
{
	int				number_philo;			// Yemek masasındaki toplam felsefeci sayısı
	int				time_to_die;			// Ölme süresi
	int				time_to_eat;			// Yeme süresi
	int				time_to_sleep;			// Uyuma süresi
	int				meal_count_limit;		// Her felsefeci tarafından yenmesi gereken toplam yemek sayısı
	int				stop_simulation;		// Simülasyonu durdurma bayrağı
	pthread_t		meal_checker;			// Yemek kontrolcüsü iş parçacığı (thread)
	long long		simulation_start_time;	// Simülasyon başlangıç zamanı
	int				return_mutex_fork;		// Çatal alma durumu için init'lenen mutex'in dönüş değerini tutan değişken
	int				return_mutex_checker;	// Kontrol işlemi için init'lenen mutex'in dönüş değerini tutan değişken
	int				return_mutex_print;		// Yazdırma işlemi için init'lenen mutex'in dönüş değerini tutan değişken
	pthread_mutex_t	*fork_mutexes;			// Çatal kontrolü için mutex dizisi
	pthread_mutex_t	meal_checker_mutex;		// Yemek kontrolcüsü için mutex
	pthread_mutex_t	print_mutex;			// Yazdırma işlemleri için mutex
	t_philo			*philo;					// Yemek masasındaki felsefecilerin listesi
}	t_table;

typedef enum e_philo_status
{
	FORK1_IN_USE,		// Filozof, çatalı 1'i kullanıyor durumu
	FORK2_IN_USE,		// Filozof, çatalı 2'yi kullanıyor durumu
	DIED,				// Filozofun öldü durumu
	THINKING,			// Filozofun düşünme durumu
	EATING,				// Filozofun yemek yeme durumu
	SLEEPING,			// Filozofun uyuma durumu
}	t_philo_status;

// LIBFT_UTILS
int			is_digit(char c);
int			ft_atoi(const char *str);
bool		is_numeric(const char *s);
void		ft_putstr_fd(char *s, int fd);

// CHECKER
void		*state_checker(void *argument);

// FLAG_CONTROL
void		update_stop_flag(t_table *table, int flag);
int			stop_simulation_flag_control(t_table *table);

// FREE
int			clear_mutexes(t_table *table);

// INIT
int			set_up_table(t_table *table, int ac, char **av);

// LIFE_CYCLE
void		*philosopher_life_cycle(void *argument);

// PARSING
int			parsing(int ac, char **av);

// PHILO_THREAD
int			being_life_cycle(t_table *table);

// PRINT
void		err_print(t_table *table, char *message);
void		log_philo_status(t_philo *philo, t_philo_status status, int die);

// TIME
long long	ms_system_time(void);
void		wait_until_time(long long time);
void		stop_until_time(t_table *table, time_t time_to_spend);

#endif
