/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:47:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/23 18:14:40 by flopez-r         ###   ########.fr       */
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

// CHECK IF ONE OF THE VALUES ARE NEGATIVE
int	checker_arguments(int argc, char **argv, int optional)
{
	if (argc < 5 || argc > 6)
		return (0);

	if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0
		|| ft_atoi(argv[4]) < 0 || (optional && ft_atoi(argv[5]) < 0))
	{
		printf(RED"The arguments can not be negative\n"RESET);
		return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_list	*data;
	int	optional;

	// atexit(d_leaks);
	data = NULL;
	optional = 0;
	//CHECKING IF THE ARGUMENTS ARE ENOUGH
	if (!checker_arguments(argc, argv, optional))
		return (ft_exit("Invalid arguments\n", EXIT_FAILURE));

	if (argc == 6)
		optional = 1;

	//DEPLOY PROGRAM
	if (!deploy(&data, argv, optional))
		return (ft_exit("Problems deploying the list\n", EXIT_FAILURE));

	if (!start_thread(data, optional))
		return (ft_exit("Problems with the threads\n", EXIT_FAILURE));

	// print_list(data, optional);

	free_list(&data, optional);
}




















// 1.- Hacer el parseo primero para evitar los leaks (HECHO) <------------------
//		1.1.- FUNCION DE LIBERAR LA LISTA (HECHO)  <------------------
// 2.- Ver como hago lo del tenedor (Currently doing) <------------------
// 3.- implementar ahora sí los hilos?

//TESTING PRINT_LOG
// print_log(&data, THINK, 1);
// print_log(&data, TK_FORK, 1);
// print_log(&data, TK_FORK, 1);
// print_log(&data, EAT, 1);
// print_log(&data, SLEEP, 1);
// print_log(&data, THINK, 1);
// print_log(&data, DEAD, 1);

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