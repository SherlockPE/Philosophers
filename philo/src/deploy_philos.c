/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:57:47 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/28 19:03:16 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	philos_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	take_forks(philo->main, philo->number);
	start_to_eat(philo->main, philo->number);
	start_to_sleep(philo->main, philo->number);
}

int	deploy_philos(t_main *data)
{
	int i;

	i = 0;
	while (i < data->count_ph)
	{
		if (pthread_create(&data->philos[i].pt, NULL, philos_routine, &data->philos[i]) != 0)
			return (0);
	}
	while (i < data->count_ph)
	{
		if (pthread_join(data->philos[i].pt, NULL) != 0)
			return (0);
	}
}
