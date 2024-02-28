/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:21:55 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/28 18:57:33 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	free_philos(t_main *data, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		pthread_mutex_destroy(&data->philos[i].fork_lock);
		i++;
	}
	free(data->philos);
	return (0);
}

int	set_philos(t_main *data)
{
	int	i;

	i = 0;
	data->philos = malloc(data->count_ph - 1 * sizeof(t_philo));
	if (!data->philos)
		return (0);
	while (i < data->count_ph)
	{
		data->philos[i].number = i + 1;
		data->philos[i].is_dead = 0;
		data->philos[i].cant_eat = 0;
		data->philos[i].main = data;
		if (pthread_mutex_init(&data->philos[i].fork_lock, NULL) == -1)
			return (free_philos(data, i));
		i++;
	}
	i = 0;
	while (i < data->count_ph - 1)
	{
		data->philos[i].next_fork_lock = &data->philos[i + 1].fork_lock;
		i++;
	}
	data->philos[i].next_fork_lock = &data->philos[0].fork_lock;
}

// 1->2->3->4->5
// 5->1
