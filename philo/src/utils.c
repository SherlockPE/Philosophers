/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:56 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/28 15:14:17 by flopez-r         ###   ########.fr       */
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
