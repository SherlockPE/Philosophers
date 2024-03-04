/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grim_reaper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:59:07 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/04 13:03:11 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*monitor(void	*arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	
	while (1)
	{
		pthread_mutex_lock(&philo->chk_dead);
		if (philo->is_dead == 1 || philo->main->n_dead == 1)
		{
			printf("Estoy muerto?: %d, N de muertos: %d\n", philo->is_dead, philo->main->n_dead);
			printf("Numero de philo: %d\n", philo->number);
			if (philo->is_dead == 1 )
				print_log(philo->number, DEAD, philo->main);
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