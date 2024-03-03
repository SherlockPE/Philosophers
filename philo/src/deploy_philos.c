/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:57:47 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/03 21:50:51 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

// int		is_die(t_philo *actual_philo)
// {
// 	if (get_pt(actual_philo->main) > actual_philo->main->tt_die)
// 	{
// 		actual_philo->main->n_dead += 1;
// 		print_log(actual_philo->number, DEAD, actual_philo->main);
// 		return (1);
// 	}
// 	return (0);
// }

void	*check_dead(void	*arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	
	while (1)
	{
		pthread_mutex_lock(&philo->chk_dead);
		if (philo->is_dead == 1 || philo->main->n_dead == 1)
		{
			if (philo->is_dead == 1 )
			{
				printf("Estoy muerto?: %d, N de muertos: %d\n", philo->is_dead, philo->main->n_dead);
				printf("Numero de philo: %d\n", philo->number);
				print_log(philo->number, DEAD, philo->main);
				// pthread_mutex_unlock(&philo->chk_dead);
			}
			philo->main->n_dead = 1;
			break;
		}
		pthread_mutex_unlock(&philo->chk_dead);
	}
	// pthread_mutex_unlock(&philo->chk_dead);

	// pthread_mutex_lock(&philo->chk_dead);
	// // if (philo->main->n_dead !=1)
	// philo->main->n_dead = 1;
	// pthread_mutex_unlock(&philo->chk_dead);

	return (0);
}

void	*philos_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	//puede fallar (hacer que se muera)
	if (pthread_create(&philo->grim_reaper, NULL, check_dead, philo) != 0)
		return (0);

	if (philo->number % 2 == 0)
		ft_usleep(100);
	pthread_mutex_lock(&philo->chk_dead);
	while (philo->main->n_dead == 0)
	{
		pthread_mutex_unlock(&philo->chk_dead);
		if (!take_forks(philo, philo->number))
			break;
		if (!start_to_eat(philo, philo->number))
			break;
		if (!start_to_sleep(philo, philo->number))
			break;
		if (!start_to_think(philo))
			break;
		pthread_mutex_lock(&philo->chk_dead);
	}
	pthread_mutex_unlock(&philo->chk_dead);

	if (pthread_join(philo->grim_reaper, NULL) != 0)
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
		printf("hola\n");
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