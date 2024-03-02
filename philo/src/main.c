/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:47:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/02 20:29:40 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	ft_exit(char *message, int exit_c)
{
	printf(RED "%s" RESET, message);
	return (exit_c);
}

void	d_leaks(void)
{
	system("leaks philo");
}

int	check_digits(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!if_isdigit(argv[i][j]))
				return (ft_exit("The arguments must be strictly positive numbers\n", 0));
			j++;
		}
		if (j > 6)
			return (ft_exit("The arguments can not be too long\n", 0));
		i++;
	}
	return (1);
}

// CHECK IF ONE OF THE VALUES ARE NEGATIVE
int	checker_arguments(t_main *data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	if (!check_digits(argv))
		return (0);
	data->n_dead = 0;
	data->count_ph = ft_atoi(argv[1]);
	data->tt_die = ft_atoi(argv[2]);
	data->tt_eat = ft_atoi(argv[3]);
	data->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	else
		data->must_eat = -1;
	if (data->count_ph == 0 || data->tt_die == 0 || data->tt_eat == 0
		|| data->tt_sleep == 0 || (data->count_ph == 0))
		return (ft_exit("The arguments must be strictly positive\n", 0));
	return (1);
}

int	main(int argc, char **argv)
{
	t_main	data;

	// atexit(d_leaks);
	//CHECKING IF THE ARGUMENTS ARE ENOUGH
	if (!checker_arguments(&data, argc, argv))
		return (ft_exit("Invalid arguments\n", EXIT_FAILURE));

	if (!set_philos(&data))
		return (ft_exit("Error in set_philos", EXIT_FAILURE));

	if (!deploy_philos(&data))
		return (ft_exit("Error in deploy philos", EXIT_FAILURE));

	free_philos(&data, data.count_ph);
}

// 1.- Hacer el parseo primero para evitar los leaks (HECHO)
//		1.1.- FUNCION DE LIBERAR LA LISTA (HECHO) 
// 2.- Ver como hago lo del tenedor (HECHO)
// 3.- implementar ahora sí los hilos (HECHO)
// 4.- Hacer las philo actions (HECHO)
// 5.- hacer que mueran (Currently doing) <------------------

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

// // 	//RESTA
// // 	printf("Evento a las: %ld:%d\n", time2.tv_sec - time.tv_sec, time2.tv_usec
// 			- time.tv_usec);
// // 	return (0);
// // }