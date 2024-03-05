/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:21:24 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/05 18:53:18 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

//Function gets the 
long long	get_time(void)
{
	struct timeval init_time;
	long long 	actual_time_ms;
	if (gettimeofday(&init_time, NULL) == -1)
	{
		printf("Gettime failed");
		return (-1);
	}
	actual_time_ms = (init_time.tv_sec * 1000) + (init_time.tv_usec / 1000);
	return (actual_time_ms);
}


int	ft_usleep(unsigned int time)
{
	long long ms;
	long long end;

	ms = get_time();
	if (ms == -1)
		return (ft_exit("Error en ft_usleep", 0));
	end = ms + time;
	usleep(time * 100);
	while (ms < end)
	{
		usleep(time);
		ms = get_time();
		if (ms == -1)
			return (ft_exit("Error en ft_usleep", 0));
	}
	return (0);
}

long long	get_pt(t_main *data)
{
	long long	result;

	result = get_time() - data->time_init;
	return (result);
}

int	ft_exit(char *message, int exit_c)
{
	printf(RED "%s" RESET, message);
	return (exit_c);
}

int	check_is_dead(t_main *main)
{
	pthread_mutex_lock(&main->m_chk_dead);
	if (main->n_dead == 0)
	{
		pthread_mutex_unlock(&main->m_chk_dead);
		return (1);
	}
	pthread_mutex_unlock(&main->m_chk_dead);
	return (0);
}
