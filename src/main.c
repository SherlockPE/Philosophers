/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:47:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/13 17:38:10 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	ft_exit(char *message, int exit_c)
{
	printf(RED"%s"RESET, message);
	return (exit_c);
}

int main(void)
{
	t_philo	data;

	if (!deploy(&data))
		return (ft_exit("Problems deploying the program", 1));
	print_log(&data, 0, 1);
	ft_usleep(2000);
	print_log(&data, 1, 2);
	ft_usleep(2000);
	print_log(&data, 2, 3);
	ft_usleep(2000);
	print_log(&data, 3, 4);
	ft_usleep(2000);
	print_log(&data, 4, 5);

}

// int main(void)
// {
// 	// DISCOVERING FUNCTIONS
// 	//1.- gettimeofday

// 	struct timeval	time;
// 	struct timeval	time2;
// 	int	error_case;

// 	error_case = gettimeofday(&time, NULL);
// 	printf("Seconds		: %ld\n", time.tv_sec);
// 	printf("miliseconds	: %d\n", time.tv_usec);

// 	sleep(3);

// 	error_case = gettimeofday(&time2, NULL);
// 	printf("Seconds		: %ld\n", time2.tv_sec);
// 	printf("miliseconds	: %d\n", time2.tv_usec);

// 	//RESTA
// 	printf("Evento a las: %ld:%d\n", time2.tv_sec - time.tv_sec, time2.tv_usec - time.tv_usec);
// 	return 0;
// }