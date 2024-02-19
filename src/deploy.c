/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:21:45 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/19 11:33:01 by flopez-r         ###   ########.fr       */
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

void	*routine(void *arg)
{
	//Maybe there's gona be problems with a not mallocated argument
	t_philo	*data;

	data = (t_philo *)arg;
	printf("Valores de data: \n");
	printf("Ttdie: %d\n", data->tt_die);
	printf("Tteat: %d\n", data->tt_die);
	printf("Ttsleep: %d\n", data->tt_sleep);
	printf("MustEat: %d\n", data->must_eat);
	return (0);
}


int	create_philosophers(t_philo *data)
{
	pthread_t	philos[data->cant_f];
	int	i;

	i = 0;
	while (i < data->cant_f)
	{
		if (pthread_create(&philos[i], NULL, routine, data) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < data->cant_f)
	{
		if (pthread_join(philos[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

//START THE PROGRAM AND SET ALL THE THREADS
int	deploy(t_philo *data, char **argv)
{	
	if (!start_clock(data))
		return (EXIT_FAILURE);
	data->cant_f = ft_atoi(argv[1]);
	data->tt_die = ft_atoi(argv[2]);
	data->tt_eat = ft_atoi(argv[3]);
	data->tt_sleep = ft_atoi(argv[4]);

	//CHECK IF THE VALUES ARE NEGATIVE
	if (data->cant_f < 0 ||
		data->tt_die < 0 ||
		data->tt_eat < 0 ||
		data->tt_sleep < 0)
	{
		printf(RED"The arguments can not be negative\n"RESET);
		return (EXIT_FAILURE);
	}

	// PENDIENTES
	// 1.- HILOS DE LLOS PHILOSOPHERS (currently doing)
	// 2.- 

	if (!create_philosophers(data))
		return(0);
	
	return (1);
}
