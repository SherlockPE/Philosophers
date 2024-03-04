/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:57:47 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/04 12:59:31 by flopez-r         ###   ########.fr       */
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

void	*philos_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;

	//puede fallar (hacer que se muera)
	if (pthread_create(&philo->grim_reaper, NULL, monitor, philo) != 0)
		return (0);

	if (philo->number % 2 == 0)
		ft_usleep(100);
	pthread_mutex_lock(&philo->chk_dead);
	while (philo->main->n_dead == 0)
	{
		pthread_mutex_unlock(&philo->chk_dead);
		printf(YELLOW"[%d] Estoy por tomar tenedores\n" RESET, philo->number);
		if (!take_forks(philo, philo->number))
			break;
		printf(YELLOW"[%d] Estoy por comer\n" RESET, philo->number);
		if (!start_to_eat(philo, philo->number))
			break;
		printf(YELLOW"[%d] Estoy por dormir\n" RESET, philo->number);
		if (!start_to_sleep(philo, philo->number))
			break;
		printf(YELLOW"[%d] Estoy por pensar\n" RESET, philo->number);
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