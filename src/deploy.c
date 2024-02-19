/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:21:45 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/19 12:42:24 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

// SAVE THE START OF THE PROGRAM
int	start_clock(t_philo *data)
{
	int	error_case;

	error_case = gettimeofday(&data->time_init, NULL);
	if (error_case == -1)
		return (0);
	return (1);
}



//START THE PROGRAM AND SET ALL THE THREADS
int	deploy(t_philo *data, char **argv, int	optional)
{	
	if (!start_clock(data))
		return (0);

	int	cant_f;

	//Allocating memory for 4 principal arguments
	data->tt_die = malloc(sizeof(int));
	data->tt_eat = malloc(sizeof(int));
	data->tt_sleep = malloc(sizeof(int));
	
	//Optional value memory asignation
	if (optional)
	{
		data->must_eat = malloc(sizeof(int));
		*data->must_eat = ft_atoi(argv[5]);
	}

	//Assigning values for the program
	cant_f = ft_atoi(argv[1]);
	*data->tt_die = ft_atoi(argv[2]);
	*data->tt_eat = ft_atoi(argv[3]);
	*data->tt_sleep = ft_atoi(argv[4]);

	printf("Valores de data: \n");
	printf("cant: %d\n", cant_f);
	printf("Ttdie: %d\n", *data->tt_die);
	printf("Tteat: %d\n", *data->tt_eat);
	printf("Ttsleep: %d\n", *data->tt_sleep);
	if (optional)
		printf("MustEat: %d\n", *data->must_eat);

	//CHECK IF THE VALUES ARE NEGATIVE
	if (cant_f < 0 ||
		*data->tt_die < 0 ||
		*data->tt_eat < 0 ||
		*data->tt_sleep < 0 ||
		(optional && *data->must_eat < 0))
	{
		free_all(data, optional);
		printf("The arguments can not be negative\n");
		return (0);
	}

	// // PENDIENTES
	// // 1.- HILOS DE LLOS PHILOSOPHERS (currently doing)
	// // 2.- 
	
	free_all(data, optional);

	return (1);
}
