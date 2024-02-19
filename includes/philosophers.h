/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:47:41 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/19 12:30:58 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>

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


typedef struct s_philo
{
	struct timeval	time_init;
	struct timeval	time_now;

	int				*number;
	int				*tt_die;
	int				*tt_eat;
	int				*tt_sleep;
	int				*must_eat;
}					t_philo;

// DEPLOY
int			start_clock(t_philo *data);
int			deploy(t_philo *data, char **args, int optional);

// UTILS
int			print_time(t_philo *data);
int			ft_usleep(unsigned int time);
int			ft_atoi(const char *str);
void		free_all(t_philo *data, int optional);

//LOGS
int			print_log(t_philo *data, unsigned int status, int philosopher);

#endif