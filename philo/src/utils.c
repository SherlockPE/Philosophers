/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:56 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/04 13:30:38 by flopez-r         ###   ########.fr       */
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
	end = ms + time;
	// printf(" Entre a ft_usleep\n");
	usleep(time * 100);
	while (ms < end)
	{
		usleep(time);
		ms = get_time();
		// printf (" ms: %lld - end: %lld\n",  ms, end);
	}
	// printf(" Sali de ft_usleep\n");
	return (0);
}

long long	get_pt(t_main *data)
{
	long long	result;

	result = get_time() - data->time_init;
	return (result);
}
