#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_main	t_main;

typedef struct s_philo
{
	int					id;
	int					n_meals_eaten;
	long long			meal_time;

	pthread_mutex_t		own_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		meal_mutex;
	pthread_t			philo_thread;

	t_main				*main;
}						t_philo;

struct					s_main
{
	t_philo				*philos;
	long long			start_time;

	int					cant_phi;
	int					tt_die;
	int					tt_eat;
	int					tt_sleep;
	int					must_eat;
	int					cant_meals;
	int					end;

	pthread_mutex_t		mem_lock;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		end_mutex;
};
//===== Colors section =====

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;97m"
# define OR_WH "\033[0;203m"
# define RESET "\033[0m"

//===== Status section =====

# define TK_FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DEAD 4

//===== Utils Section =====
/* Libft utils */
int						if_isdigit(int c);
int						ft_strlen(char *string);
int						ft_atoi(const char *str);

/* Error utils */
int						ft_exit(char *message, int exit_c);
void					free_program(t_main *main, int max);

/* Init mutex */
int						init_main_mutex(t_main *main);
int						init_philo_mutex(t_philo *philo);

/* Time utils */
long long				get_time(void);
int						ft_usleep(unsigned int time);
void					reload_last_meal(t_philo *philo);
void					update_n_meals(t_philo *philo);

/* Checkers */
int						check_arguments(int argc, char **argv);
int						check_positive(t_main *main);
int						checker_death(t_main *main);

/* Print status */
void					print_status(t_main *main, int id, int status);

//===== Init Section =====
int						init_main(int argc, char **argv, t_main *main);
int						init_philos(t_main *main);
#endif

//===== Threads Section =====
int						create_threads(t_main *main);

//===== Philos actions =====

void					take_forks(t_philo *philo);
void					start_to_eat(t_philo *philo);
void					start_to_sleep(t_philo *philo);
void					start_to_think(t_philo *philo);
