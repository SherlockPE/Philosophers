/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:47:41 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/28 19:03:30 by flopez-r         ###   ########.fr       */
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
	int					is_dead;
	int					cant_eat;
	long long			time_now;

	pthread_t			pt;
	pthread_mutex_t		fork_lock;
	pthread_mutex_t		*next_fork_lock;
	t_main				*main;
}						t_philo;

struct					s_main
{
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

//LOGS
int				print_log(int	id, unsigned int status);

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
int				take_forks(t_main *data, int philo_number);
void			start_to_eat(t_main *data, int philo_number);
void			start_to_sleep(t_main	*data, int philo_number);

#endif