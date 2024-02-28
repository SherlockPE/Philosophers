/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:40:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/28 19:02:17 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	take_forks(t_main *data, int philo_number)
{
	pthread_mutex_lock(&data->philos[philo_number].fork_lock);
	print_log(philo_number, TK_FORK);
	pthread_mutex_lock(data->philos[philo_number].next_fork_lock);
	print_log(philo_number, TK_FORK);
}

void start_to_eat(t_main	*data, int philo_number)
{
	print_log(philo_number, EAT);
	ft_usleep(data->tt_eat);
	pthread_mutex_lock(&data->philos[philo_number].fork_lock);
	pthread_mutex_lock(data->philos[philo_number].next_fork_lock);
}

void	start_to_sleep(t_main	*data, int philo_number)
{
	print_log(philo_number, SLEEP);
	ft_usleep(data->tt_sleep);
}
