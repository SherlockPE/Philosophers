/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:21:45 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/20 16:49:23 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
pthread_mutex_t	mutex;

// SAVE THE START OF THE PROGRAM
int	start_clock(t_philo *data)
{
	int	error_case;

	error_case = gettimeofday(&data->time_init, NULL);
	if (error_case == -1)
		return (0);
	return (1);
}

//INICIALIZE A LIST OF ALL OF THE PHILOSOPHERS
int	deploy(t_philo *data, char **argv, int	optional)
{
	if (!start_clock(data))
		return (0);

	t_list	*philos;

	philos = NULL;
	if (!set_philos(&philos, argv, optional))
		return (0);

	print_list(philos, optional);

	free_all(data, optional);
	return (1);
}

//Hacer una lista para recorrer los philosofos


// printf("Valores de data: \n");
// printf("cant: %d\n", cant_f);
// printf("Ttdie: %d\n", *data->tt_die);
// printf("Tteat: %d\n", *data->tt_eat);
// printf("Ttsleep: %d\n", *data->tt_sleep);
// if (optional)
// 	printf("MustEat: %d\n", *data->must_eat);



// PENDIENTES
// 1.- HILOS DE LLOS PHILOSOPHERS (currently doing)
// 2.- 


