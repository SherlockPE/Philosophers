/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:57:47 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/06 17:21:15 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*p_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->last_meal);
	philo->time_eat = philo->main->time_init;
	pthread_mutex_unlock(&philo->last_meal);
	//Si el id del filo es par, esperar 1 ms
	if (philo->number % 2 == 0)
		ft_usleep(10);
	//Rutina principal
	pthread_mutex_lock(&philo->main->m_chk_dead);
	while (philo->main->n_dead == 0)
	{
		pthread_mutex_unlock(&philo->main->m_chk_dead);
		
		if (!take_forks(philo, philo->number))
			return (0);
		if (!start_to_eat(philo, philo->number))
			return (0);
		if (!start_to_sleep(philo, philo->number))
			return (0);
		if (!start_to_think(philo, philo->number))
			return (0);

		pthread_mutex_lock(&philo->main->m_chk_dead);
	}
	pthread_mutex_unlock(&philo->main->m_chk_dead);
	return (0);
}

int	deploy_philos(t_main *data)
{
	int	i;

	i = 0;
	data->time_init = get_time();
	if (data->time_init == -1)
		return (ft_exit("Fallo en la funcion gettime()", 0));
	while (i < data->count_ph)
	{
		if (pthread_create(&data->philos[i].pt, NULL, p_routine,&data->philos[i]))
			return (0);
		i++;
	}
	//Monitor vigilante
	if (pthread_create(&data->grim_reaper, NULL, monitoring, data))
		return (0);
	i = 0;
	while (i < data->count_ph)
	{
		if (pthread_join(data->philos[i].pt, NULL))
			return (0);
		// printf("Hilo %d terminado\n", i + 1);
		i++;
	}
	if (pthread_join(data->grim_reaper, NULL))
		return (0);
	return (1);
}

// if (start_to_eat(philo, philo->number) && start_to_sleep(philo,
			// philo->number)&& start_to_think(philo)))
// {

// 	write(1,"AQUI\n", 5);
// 	break ;
// 	// philo->main->n_dead = 1;
// }
// printf("Cycle condition VALUE: %d\n", philo->main->n_dead);