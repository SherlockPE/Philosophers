/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:42:28 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/03/08 14:40:02 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void    take_forks(t_philo *philo)
{
	// printf("Philo %d entro\n", philo->number);
	pthread_mutex_lock(&philo->own_fork);
	if (!checker_death(philo->main))
	{
        print_status(philo->main, philo->id, TK_FORK);
		if (philo->main->cant_phi == 1)
		{
			pthread_mutex_unlock(&philo->own_fork);
			ft_usleep(philo->main->tt_die);
			return ;
		}
	}
	pthread_mutex_lock(philo->right_fork);
	if (!checker_death(philo->main))
        print_status(philo->main, philo->id, TK_FORK);
	return ;
}

void    start_to_eat(t_philo *philo)
{
	if (!checker_death(philo->main))
	{
    	print_status(philo->main, philo->id, EAT);
    	reload_last_meal(philo);
    	update_n_meals(philo);
    	ft_usleep(philo->main->tt_eat);
	}
	pthread_mutex_unlock(&philo->own_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void    start_to_sleep(t_philo *philo)
{
	if (!checker_death(philo->main))
	{
		print_status(philo->main, philo->id, SLEEP);
		ft_usleep(philo->main->tt_sleep);
	}
}

void    start_to_think(t_philo *philo)
{
	if (!checker_death(philo->main))
    	print_status(philo->main, philo->id, THINK);
}

