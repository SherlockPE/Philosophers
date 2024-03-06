/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:47:41 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/06 17:02:47 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;97m"
# define OR_WH "\033[0;203m"
# define RESET "\033[0m"

# define DEAD 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define TK_FORK 4

typedef struct s_main	t_main;

typedef struct s_philo
{
	long long			time_eat; // <-- This variable saves the last time that a philosopher eat
	int					number; // <-- id of philos
	int					cant_eat; // <-- variable for the optional value

	pthread_t			pt; //<-Philo thread

	pthread_mutex_t		fork_lock; //mutex for philo
	pthread_mutex_t		*next_fork_lock; //pointer mutex for the next philo

	pthread_mutex_t		last_meal; //mutex for checking the value of the last time a philo eat
	t_main				*main; //Pointer to the main structure
}						t_philo;

struct					s_main
{
	int					n_dead;
	t_philo				*philos; //<--- Array of philos

	pthread_t			grim_reaper; // <--Monitor thread
	pthread_mutex_t		m_chk_dead; //For check de end
	pthread_mutex_t		mem_lock; // <-- for check the n_dead value
	// pthread_mutex_t		print_lock;

	int					main_cant_eat; // <-- for check the optional value is done

	int					count_ph;
	int					tt_die;
	int					tt_eat;
	int					tt_sleep;
	int					must_eat;
	long long			time_init;
};

//UTILS
// int						ft_usleep_L(unsigned int time, int number);
int						ft_usleep(unsigned int time);
void					free_all(t_philo *data, int optional);
long long				get_time(void);
long long				get_pt(t_main *data);
int						ft_exit(char *message, int exit_c);
int						check_is_dead(t_main *main);

//LOGS
int						print_log(int id, unsigned int status, t_main *data);
// int				print_log(int	id, unsigned int status);

// GRIMM REAPER
void					*monitor(void *arg);
void					*monitoring(void	*arg);

//Checker an initialize
int						checker_arguments(t_main *data, int argc, char **argv);

//LIBFT UTILS
int						ft_atoi(const char *str);
int						ft_strlen(char *string);
int						if_isdigit(int c);

//SET PHILOS
int						free_philos(t_main *data, int max);
int						set_philos(t_main *data);

//DEPLOY PHILOS
int						deploy_philos(t_main *data);

//PHILO ACTIONS
int						take_forks(t_philo *philo, int philo_number);
int						start_to_eat(t_philo *philo, int philo_number);
int						start_to_sleep(t_philo *philo, int philo_number);
int						start_to_think(t_philo *philo, int philo_number);

#endif