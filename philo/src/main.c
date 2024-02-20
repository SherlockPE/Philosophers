/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:47:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/20 16:34:01 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	ft_exit(char *message, int exit_c)
{
	printf(RED"%s"RESET, message);
	return (exit_c);
}

void	d_leaks(void)
{
	system("leaks philo");
}


int main(int argc, char **argv)
{
	t_philo	data;
	int	optional;

	// atexit(d_leaks);
	optional = 0;
	//CHECKING IF THE ARGUMENTS ARE ENOUGH
	if (argc < 5 || argc > 6)
		return (ft_exit("Not enough arguments\n", EXIT_FAILURE));

	if (argc == 6)
		optional = 1;
	//DEPLOY PROGRAM
	if (!deploy(&data, argv, optional))
		return (ft_exit("Problems deploying the program\n", EXIT_FAILURE));

	//TESTING PRINT_LOG
	// print_log(&data, THINK, 1);
	// print_log(&data, TK_FORK, 1);
	// print_log(&data, TK_FORK, 1);
	// print_log(&data, EAT, 1);
	// print_log(&data, SLEEP, 1);
	// print_log(&data, THINK, 1);
	// print_log(&data, DEAD, 1);
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