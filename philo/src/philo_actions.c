/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:40:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/05 20:11:50 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	take_forks(t_philo *philo, int philo_number)
{
	// printf("Philo %d entro\n", philo->number);
	pthread_mutex_lock(&philo->fork_lock);
	if (!check_is_dead(philo->main))
		return (0);
	print_log(philo_number, TK_FORK, philo->main);
	if (philo->main->count_ph == 1)
	{
		pthread_mutex_unlock(&philo->fork_lock);
		ft_usleep(philo->main->tt_die);
		return (0);
	}
	if (!check_is_dead(philo->main))
		return (0);
	pthread_mutex_lock(philo->next_fork_lock);
	print_log(philo_number, TK_FORK, philo->main);
	// printf("Philo %d salió\n", philo->number);
	return (1);
}

int	start_to_eat(t_philo *philo, int philo_number)
{
	print_log(philo_number, EAT, philo->main);
	ft_usleep(philo->main->tt_eat);
	pthread_mutex_lock(&philo->last_meal);
	philo->last_food = get_time();
	philo->cant_eat++;
	pthread_mutex_lock(&philo->main->mem_lock);
	if (philo->cant_eat == philo->main->must_eat)
		philo->main->main_cant_eat++;
	pthread_mutex_unlock(&philo->main->mem_lock);
	pthread_mutex_unlock(&philo->last_meal);
	pthread_mutex_unlock(&philo->fork_lock);
	pthread_mutex_unlock(philo->next_fork_lock);
	return (1);
}

int	start_to_sleep(t_philo *philo, int philo_number)
{
	print_log(philo_number, SLEEP, philo->main);
	ft_usleep(philo->main->tt_sleep);
	return (1);
}

int	start_to_think(t_philo *philo, int philo_number)
{
	print_log(philo_number, THINK, philo->main);
	return (1);
}
