/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:54:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/19 19:02:43 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	set_params(t_philo *data, char **argv, int optional)
{
	//Allocating memory for 4 principal arguments
	data->number = malloc(sizeof(int));
	data->tt_die = malloc(sizeof(int));
	data->tt_eat = malloc(sizeof(int));
	data->tt_sleep = malloc(sizeof(int));
	
	//Protection of mallocs
	if (!data->tt_die ||
		!data->tt_eat ||
		!data->tt_sleep)
		return (0);

	//Optional value memory asignation
	if (optional)
	{
		data->must_eat = malloc(sizeof(int));
		if(!data->must_eat)
			return (0);
		*data->must_eat = ft_atoi(argv[5]);
	}
	//Assigning values for the program
	*data->tt_die = ft_atoi(argv[2]);
	*data->tt_eat = ft_atoi(argv[3]);
	*data->tt_sleep = ft_atoi(argv[4]);
	return (1);
}

int	negative_values_not_allowed(t_philo *data, int optional, int cant_f)
{
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
	return (1);
}
