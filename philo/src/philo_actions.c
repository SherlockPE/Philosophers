/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:40:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/03 21:53:12 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	reaper(t_philo	*philo)
{
	pthread_mutex_lock(&philo->chk_dead);
	if (philo->main->n_dead >= 1)
		return (0);
	pthread_mutex_unlock(&philo->chk_dead);
	return (1);
}


int	take_forks(t_philo	*philo, int philo_number)
{
	pthread_mutex_lock(&philo->fork_lock);
	if (!reaper(philo))
		return (0);
	print_log(philo_number, TK_FORK, philo->main);
	pthread_mutex_lock(philo->next_fork_lock);
	if (!reaper(philo))
		return (0);
	print_log(philo_number, TK_FORK, philo->main);
	return(1);
}

int start_to_eat(t_philo *philo, int philo_number)
{
	if (!reaper(philo))
		return (0);
	print_log(philo_number, EAT, philo->main);
	pthread_mutex_lock(&philo->chk_dead);
	if (philo->tt_eat >= philo->tt_die)
	{
		ft_usleep(philo->tt_die);
		philo->is_dead = 1;
		pthread_mutex_unlock(&philo->fork_lock);
		pthread_mutex_unlock(philo->next_fork_lock);
		pthread_mutex_unlock(&philo->chk_dead);	
		return (0);
	}
	pthread_mutex_unlock(&philo->chk_dead);
	ft_usleep(philo->tt_eat);
	pthread_mutex_unlock(&philo->fork_lock);
	pthread_mutex_unlock(philo->next_fork_lock);
	return(1);
}

int	start_to_sleep(t_philo *philo, int philo_number)
{
	if (!reaper(philo))
		return (0);
	print_log(philo_number, SLEEP, philo->main);
	pthread_mutex_lock(&philo->chk_dead);
	if (philo->tt_sleep >= philo->tt_die)
	{
		ft_usleep(philo->tt_die);
		philo->is_dead = 1;
		pthread_mutex_unlock(&philo->chk_dead);	
		return (0);
	}
	pthread_mutex_unlock(&philo->chk_dead);
	ft_usleep(philo->tt_sleep);
	return(1);
}

int	start_to_think(t_philo *philo)
{
	if (!reaper(philo))
		return (0);
	// printf("Voy a dormir: %d ms", philo->);
	print_log(philo->number, THINK, philo->main);
	return(1);
}
