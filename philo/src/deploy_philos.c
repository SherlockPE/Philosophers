/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:57:47 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/05 15:16:40 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>


int	checker(t_philo	*philo)
{
	pthread_mutex_lock(&philo->main->m_chk_dead);
	if (philo->main->n_dead >= 1)
		return (1);
	pthread_mutex_unlock(&philo->main->m_chk_dead);
	return (0);
}

void	*philos_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	philo->last_food = get_time() + philo->main->tt_die;

	//Si el id del filo es par, esperar 1 ms	
	if (philo->number % 2 == 0)
		ft_usleep(5);
	
	//Monitor vigilante
	if (pthread_create(&philo->grim_reaper, NULL, monitor, philo) != 0)
		return (0);

	//Rutina principal
	pthread_mutex_lock(&philo->main->m_chk_dead);
	while (philo->main->n_dead == 0)
	{
		pthread_mutex_unlock(&philo->main->m_chk_dead);

		take_forks(philo, philo->number);
		start_to_eat(philo, philo->number);
		start_to_sleep(philo, philo->number);
		start_to_think(philo, philo->number);

		pthread_mutex_lock(&philo->main->m_chk_dead);
	}
	pthread_mutex_unlock(&philo->main->m_chk_dead);

	if (pthread_join(philo->grim_reaper, NULL))
		return (0);
	return (0);
}

int	deploy_philos(t_main *data)
{
	int i;

	i = 0;
	data->time_init = get_time();
	while (i < data->count_ph)
	{
		if (pthread_create(&data->philos[i].pt, NULL, philos_routine, &data->philos[i]) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < data->count_ph)
	{
		if (pthread_join(data->philos[i].pt, NULL) != 0)
			return (0);
		printf("Hilo %d terminado\n", i + 1);
		i++;
	}
	return (1);
}



		// if (start_to_eat(philo, philo->number) && start_to_sleep(philo, philo->number)&& start_to_think(philo)))
		// {
			
		// 	write(1,"AQUI\n", 5);
		// 	break;
		// 	// philo->main->n_dead = 1;
		// }
		// printf("Cycle condition VALUE: %d\n", philo->main->n_dead);