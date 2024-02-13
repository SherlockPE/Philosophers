/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:47:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/13 15:15:30 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>


void	start_clock(t_philo *data)
{
	

	
}


int main(void)
{
	// DISCOVERING FUNCTIONS
	//1.- gettimeofday

	struct timeval	time;
	struct timeval	time2;
	int	error_case;

	error_case = gettimeofday(&time, NULL);
	printf("Seconds		: %ld\n", time.tv_sec);
	printf("miliseconds	: %d\n", time.tv_usec);
	
	usleep(10000);
	
	error_case = gettimeofday(&time2, NULL);
	printf("Seconds		: %ld\n", time2.tv_sec);
	printf("miliseconds	: %d\n", time2.tv_usec);

	//RESTA
	printf("Evento a las: %ld:%d\n", time2.tv_sec - time.tv_sec, time2.tv_usec - time.tv_usec);
	return 0;
}
