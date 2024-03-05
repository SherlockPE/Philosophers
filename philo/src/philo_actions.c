/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:40:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/05 15:30:50 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

/* int	reaper(t_philo	*philo)
{
	pthread_mutex_lock(&philo->chk_dead);
	if (philo->main->n_dead >= 1)
	{
		printf(RED"Alguien a muerto\n"RESET);
		return (0);
	}
	pthread_mutex_unlock(&philo->chk_dead);
	return (1);
} */


int	take_forks(t_philo	*philo, int philo_number)
{
	pthread_mutex_lock(&philo->fork_lock);
	print_log(philo_number, TK_FORK, philo->main);
	if (philo->main->count_ph == 1)
	{
		ft_usleep(philo->main->tt_die);
		return (0);
	}
	pthread_mutex_lock(philo->next_fork_lock);
	print_log(philo_number, TK_FORK, philo->main);
	return(1);
}

int start_to_eat(t_philo *philo, int philo_number)
{
	print_log(philo_number, EAT, philo->main);
	ft_usleep(philo->main->tt_eat);
	
	pthread_mutex_lock(&philo->m_last_meal);
	philo->last_food = get_time() + philo->main->tt_die;
	pthread_mutex_unlock(&philo->m_last_meal);

	pthread_mutex_lock(&philo->m_cant_eat);
	philo->cant_eat++;
	pthread_mutex_unlock(&philo->m_cant_eat);

	pthread_mutex_unlock(&philo->fork_lock);
	pthread_mutex_unlock(philo->next_fork_lock);
	return(1);
}

int	start_to_sleep(t_philo *philo, int philo_number)
{
	print_log(philo_number, SLEEP, philo->main);
	ft_usleep(philo->main->tt_sleep);
	return(1);
}

int	start_to_think(t_philo *philo, int philo_number)
{
	print_log(philo_number, THINK, philo->main);
	return(1);
}
