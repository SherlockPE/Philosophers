/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grim_reaper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:59:07 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/05 15:41:55 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	more_de_fome(t_philo	*philo)
{
	pthread_mutex_lock(&philo->m_last_meal);
	if (philo->last_food  <= get_time())
	{
		print_log(philo->number, DEAD, philo->main);
		pthread_mutex_lock(&philo->main->m_chk_dead);
		philo->main->n_dead = 1;
		pthread_mutex_unlock(&philo->main->m_chk_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->m_last_meal);
	return (0);
}

int	must_eat_opt(t_philo	*philo)
{
	// int	i;
	// if (philo->main->must_eat == -1)
	// 	return (0);

	// i = 0;
	// while (i < philo->main->must_eat)
	// {
	pthread_mutex_lock(&philo->m_cant_eat);
	if (philo->cant_eat == philo->main->must_eat)
	{
		pthread_mutex_lock(&philo->main->m_chk_dead);
		philo->main->n_dead = 1;
		pthread_mutex_unlock(&philo->main->m_chk_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->m_cant_eat);
	// }
	return (0);
}

void	*monitor(void	*arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	while (1)
	{
		if (more_de_fome(philo) || must_eat_opt(philo))
			break;
	}
	return (0);
}
