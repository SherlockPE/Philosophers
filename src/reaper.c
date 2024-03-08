/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:08:09 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/03/08 22:55:40 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <philosophers.h>

/* Atropos is one of the three Moirai in Greek mythology. */
/*Her main function is to cut the thread of human life at the moment of death. */
void	atropos_cut(t_main *main)
{
	pthread_mutex_lock(&main->end_mutex);
	main->end = 1;
	pthread_mutex_unlock(&main->end_mutex);
}

int atropos_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	if (philo->meal_time + philo->main->tt_die <= get_time())
	{
		pthread_mutex_unlock(&philo->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	return (0);
}


int	reaper(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->cant_phi)
	{
		if (checker_death(main))
			return (1);
		if (atropos_check(&main->philos[i]))
		{
			print_status(main, i + 1, DEAD);
			atropos_cut(main);
			return (1);
		}
		i++;
	}
	return (0);
}
