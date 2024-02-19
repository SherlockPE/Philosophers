/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:47:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/19 11:17:40 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	ft_exit(char *message, int exit_c)
{
	printf(RED"%s"RESET, message);
	return (exit_c);
}

int main(int argc, char **argv)
{
	t_philo	data;

	//CHECKING IF THE ARGUMENTS ARE ENOUGH
	if (argc < 5 || argc > 6)
		return (ft_exit("Not enough arguments\n", EXIT_FAILURE));

	//DEPLOY PROGRAM
	if (!deploy(&data, argv))
		return (ft_exit("Problems deploying the program\n", EXIT_FAILURE));

	//TESTING PRINT_LOG
	print_log(&data, THINK, 1);
	print_log(&data, TK_FORK, 1);
	print_log(&data, TK_FORK, 1);
	print_log(&data, EAT, 1);
	print_log(&data, SLEEP, 1);
	print_log(&data, THINK, 1);
	print_log(&data, DEAD, 1);
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