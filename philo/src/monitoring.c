/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:59:07 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/05 18:45:24 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	more_de_fome(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->count_ph && check_is_dead(main))
	{
		pthread_mutex_lock(&main->philos[i].last_meal);
		if (main->philos[i].last_food + main->tt_die <= get_time())
		{
			pthread_mutex_unlock(&main->philos[i].last_meal);
			pthread_mutex_lock(&main->m_chk_dead);
			print_log(main->philos[i].number, DEAD, main);
			main->n_dead = 1;
			pthread_mutex_unlock(&main->m_chk_dead);
			return (1);
		}
		pthread_mutex_unlock(&main->philos[i].last_meal);
		i++;
	}
	return (0);
}

void	*must_eat_opt(void *arg)
{

	t_main *main;

	main = (t_main *)arg;
	while (check_is_dead(main))
	{
		pthread_mutex_lock(&main->mem_lock);
		if (main->main_cant_eat == main->count_ph)
		{
			pthread_mutex_lock(&main->m_chk_dead);
			main->n_dead = 1;
			pthread_mutex_unlock(&main->m_chk_dead);
			return (0);
		}
		pthread_mutex_unlock(&main->mem_lock);
	}
	return (0);
}

void	*monitoring(void	*arg)
{
	t_main	*main;
	pthread_t	opt_must_eat;
	
	main = (t_main *)arg;
	if (main->must_eat > 0)
	{
		if (pthread_create(&opt_must_eat, NULL, must_eat_opt, main))
		{
			pthread_mutex_lock(&main->m_chk_dead);
			main->n_dead = 1;
			pthread_mutex_unlock(&main->m_chk_dead);
			return (0);
		}
	}
	while (1)
	{
		if (more_de_fome(main))
			break;
	}
	if (main->must_eat > 0)
		pthread_join(opt_must_eat, NULL);
	return (0);
}
