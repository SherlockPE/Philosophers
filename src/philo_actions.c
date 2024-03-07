/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:42:28 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/03/07 23:51:16 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void    take_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->own_fork);
    print_status(philo->main, philo->id, TK_FORK);
    if (philo->main->cant_phi == 1)
    {
        ft_usleep(philo->main->tt_die);
        pthread_mutex_unlock(&philo->own_fork);
        return ;
    }
    pthread_mutex_lock(philo->right_fork);
    print_status(philo->main, philo->id, TK_FORK);
}

void    start_to_eat(t_philo *philo)
{
    print_status(philo->main, philo->id, EAT);
    reload_last_meal(philo);
    update_n_meals(philo);
    ft_usleep(philo->main->tt_sleep);
    pthread_mutex_unlock(&philo->own_fork);
    pthread_mutex_unlock(philo->right_fork);
}

void    start_to_sleep(t_philo *philo)
{
    print_status(philo->main, philo->id, SLEEP);
    ft_usleep(philo->main->tt_sleep);
}

void    start_to_think(t_philo *philo)
{
    print_status(philo->main, philo->id, THINK);
}

// void    take_forks(t_philo *philo)
// {
// 	// printf("Philo %d entro\n", philo->number);
// 	pthread_mutex_lock(&philo->own_fork);
// 	if (!checker_death(philo->main))
// 	{
//         print_status(philo->main, philo->id, TK_FORK);
// 		if (philo->main->cant_phi == 1)
// 		{
// 			pthread_mutex_unlock(&philo->own_fork);
// 			ft_usleep(philo->main->tt_die);
// 			return ;
// 		}
// 	}
// 	if (!checker_death(philo->main))
// 	{
// 		pthread_mutex_lock(philo->right_fork);
//         print_status(philo->main, philo->id, TK_FORK);
// 		return ;
// 	}
// 	return ;
// }
