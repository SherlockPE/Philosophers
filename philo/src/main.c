/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:47:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/04 13:24:44 by flopez-r         ###   ########.fr       */
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
