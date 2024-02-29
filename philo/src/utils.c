/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:56 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/29 14:40:23 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	ft_usleep(unsigned int time)
{
	unsigned long ms;
	unsigned long end;
	struct timeval time_new;

	if (gettimeofday(&time_new, NULL))
		return (-1);

	ms = (time_new.tv_sec * 1000) + (time_new.tv_usec / 1000);
	end = ms + time;
	usleep(ms * 100);
	while (ms < end)
	{
		usleep(ms);
		if (gettimeofday(&time_new, NULL))
			return (-1);
		ms = (time_new.tv_sec * 1000) + (time_new.tv_usec / 1000);
	}
	return (0);
}

long long	get_pt(t_main *data)
{
	long long	result;

	result = data->time_init - get_time();
	return (result);
}

// SAVE THE START OF THE PROGRAM
long long	get_time(void)
{
	struct timeval init_time;
	long long 	actual_time_ms;
	if (gettimeofday(&init_time, NULL) == -1)
		return (-1);
	actual_time_ms = (init_time.tv_sec * 1000) + (init_time.tv_usec / 1000);
	return (actual_time_ms);
}
