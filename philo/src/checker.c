/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:24:23 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/04 20:36:02 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

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
	if (pthread_mutex_init(&data->m_chk_dead, NULL) == -1)
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
