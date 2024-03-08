/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:29:47 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/03/08 23:12:05 by fabriciolop      ###   ########.fr       */
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
	
	if (philo->id % 2 == 0)
		ft_usleep(10);
	while (!checker_death(philo->main))
	{
		if (!checker_death(philo->main))
			take_forks(philo);
		if (!checker_death(philo->main))
			start_to_eat(philo);
		if (!checker_death(philo->main))
			start_to_sleep(philo);
		if (!checker_death(philo->main))
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
		if (pthread_create(&main->philos[i].clotho, NULL, routine, &main->philos[i]))
			return (0);
		i++;
	}
	if (pthread_create(&main->monitor, NULL, monitor, main))
		return (0);
	i = 0;
	while (i < main->cant_phi)
	{
		if (pthread_join(main->philos[i].clotho, NULL))
			return (0);
		i++;
	}
	if (pthread_join(main->monitor, NULL))
		return (0);
	return (1);
}
