/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grim_reaper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:59:07 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/04 17:50:19 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	starvation(t_philo	*philo)
{
	pthread_mutex_lock(&philo->m_last_meal);
	if ((philo->last_food + get_pt(philo->main)) >= (philo->main->tt_die))
	{
		print_log(philo->number, DEAD, philo->main);
		return (1);
	}
	pthread_mutex_unlock(&philo->m_last_meal);
	return (0);
}

void	*monitor(void	*arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	while (1)
	{
		if (starvation(philo))
		{
			pthread_mutex_lock(&philo->m_chk_dead);
			philo->main->n_dead += 1;
			pthread_mutex_unlock(&philo->m_chk_dead);
			break;
		}
	}
	return (0);
}
