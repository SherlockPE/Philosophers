/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:29:47 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/03/07 19:17:48 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *) arg;
	pthread_mutex_lock(&philo->meal_mutex);
	philo->meal_time = philo->main->start_time;
	pthread_mutex_unlock(&philo->meal_mutex);
	while (!checker_death(philo->main))
	{
		take_forks(philo);
		start_to_eat(philo);
		start_to_sleep(philo);
		start_to_think(philo);
	}
	return (0);
}

int create_threads(t_main *main)
{
	int i;

	i = 0;
	main->start_time = get_time();
	while (i < main->cant_phi)
	{
		if (pthread_create(&main->philos[i].philo_thread, NULL, routine, &main->philos[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < main->cant_phi)
	{
		if (pthread_join(main->philos[i].philo_thread, NULL))
			return (0);
		i++;
	}
	return (1);
}