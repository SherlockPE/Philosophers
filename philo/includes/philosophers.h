/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:47:41 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/29 19:13:18 by flopez-r         ###   ########.fr       */
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
	int					number;
	int					cant_eat;
	long long			time_now;
	int					is_dead;

	pthread_t			pt;
	pthread_t			grim_reaper;

	pthread_mutex_t		fork_lock;
	pthread_mutex_t		*next_fork_lock;
	pthread_mutex_t		chk_dead;
	t_main				*main;
}						t_philo;

struct					s_main
{
	int					n_dead;
	t_philo				*philos;

	pthread_mutex_t		mem_lock;
	pthread_mutex_t		print_lock;

	int					count_ph;
	int					tt_die;
	int					tt_eat;
	int					tt_sleep;
	int					must_eat;
	long long			time_init;
};

//UTILS
int				ft_usleep(unsigned int time);
void			free_all(t_philo *data, int optional);
long long		get_time(void);
long long		get_pt(t_main *data);

//LOGS
int				print_log(int	id, unsigned int status, t_main *data);
// int				print_log(int	id, unsigned int status);

//LIBFT UTILS
int				ft_atoi(const char *str);
int				ft_strlen(char *string);
int				if_isdigit(int c);

//SET PHILOS
int				free_philos(t_main *data, int max);
int				set_philos(t_main *data);

//DEPLOY PHILOS
int				deploy_philos(t_main *data);


//PHILO ACTIONS
int				take_forks(t_philo	*philo, int philo_number);
int				start_to_eat(t_philo *philo, int philo_number);
int				start_to_sleep(t_philo *philo, int philo_number);
int				start_to_think(t_philo *philo);

#endif