/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:40:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/29 19:46:13 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	take_forks(t_philo	*philo, int philo_number)
{
	pthread_mutex_lock(&philo->fork_lock);
	print_log(philo_number, TK_FORK, philo->main);
	// if (philo->main->count_ph != 1)
	// {
	pthread_mutex_lock(philo->next_fork_lock);
	print_log(philo_number, TK_FORK, philo->main);
	// }
	return(1);
}

int start_to_eat(t_philo *philo, int philo_number)
{
	print_log(philo_number, EAT, philo->main);
	if (philo->main->tt_eat >= philo->main->tt_die)
	{
		ft_usleep(philo->main->tt_die);
		pthread_mutex_lock(&philo->chk_dead);
		philo->is_dead = 1;
		pthread_mutex_unlock(&philo->chk_dead);
		return (0);
	}
	ft_usleep(philo->main->tt_eat);
	pthread_mutex_unlock(&philo->fork_lock);
	// if (philo->main->count_ph > 1)
	pthread_mutex_unlock(philo->next_fork_lock);
	return(1);
}

int	start_to_sleep(t_philo *philo, int philo_number)
{
	print_log(philo_number, SLEEP, philo->main);
	if (philo->main->tt_sleep >= philo->main->tt_die)
	{
		ft_usleep(philo->main->tt_die);
		pthread_mutex_lock(&philo->chk_dead);
		philo->is_dead = 1;
		pthread_mutex_unlock(&philo->chk_dead);
		return (0);
	}
	ft_usleep(philo->main->tt_sleep);
	return(1);
}

int	start_to_think(t_philo *philo)
{
	print_log(philo->number, THINK, philo->main);
	return(1);
}
