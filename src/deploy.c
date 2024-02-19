/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:21:45 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/19 19:25:53 by flopez-r         ###   ########.fr       */
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

void	*routine(void *arg)
{
	t_philo *data;

	data = (t_philo *)arg;
	printf(RED"Philosofo #%d a entrado\n"RESET, *data->number);
	printf("Valores de data: \n");
	printf("Ttdie: %d\n", *data->tt_die);
	printf("Tteat: %d\n", *data->tt_eat);
	printf("Ttsleep: %d\n", *data->tt_sleep);

	//Ciclo de los filosofos
	//COME ->> TENEDOR DERECHA E IZQUIERDA
	//DUERME
	//PIENSA
	// print_log(data, TK_FORK);
	// print_log(data, EAT);
	// print_log(data, SLEEP);
	// print_log(data, THINK);

	return (0);
}

int	deploy_philosofers(int cant_f, t_philo *data, int optional)
{
	pthread_t	hilos[cant_f];

	*data->number = 0;
	(void)optional;
	printf("cantidad de philosophers: %d\n", cant_f);
	printf("Valor de philosofo: %d\n", *data->number);
	while (*data->number < cant_f)
	{
		if (pthread_create(&hilos[*data->number], NULL, routine, data) != 0)
			return (0);
		(*data->number)++;
		// printf(RED"Valor de number: %d\n"RESET, *data->number);
	}
	*data->number = 0;
	while (*data->number < cant_f)
	{
		if (pthread_join(hilos[*data->number], NULL) != 0)
			return (0);
		(*data->number)++;
	}
	printf("Valor de philosofo: %d\n", *data->number);
	return (1);
}

//START THE PROGRAM AND SET ALL THE THREADS
int	deploy(t_philo *data, char **argv, int	optional)
{
	if (!start_clock(data))
		return (0);

	int	cant_f;
	cant_f = ft_atoi(argv[1]);
	
	if (!set_params(data, argv, optional) || !negative_values_not_allowed(data, optional, cant_f))
		return (0);

	if (!deploy_philosofers(cant_f, data, optional))
	{
		free_all(data, optional);
		return (0);
	}

	free_all(data, optional);
	return (1);
}


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


