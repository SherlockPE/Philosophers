/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:56:41 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/03/07 17:29:31 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int main(int argc, char *argv[])
{
	t_main	main;
	if (!check_arguments(argc, argv))
		return (ft_exit("Invalid Arguments", EXIT_FAILURE));
	if (!init_main(argc, argv, &main))
		return (ft_exit("Problems starting the program", EXIT_FAILURE));
	if (!init_philos(&main))
		return (ft_exit("Problems starting the philos", EXIT_FAILURE));
	if (!create_threads(&main))
		return (ft_exit("Problems creating the threads", EXIT_FAILURE));
		
	free_program(&main, main.cant_phi);
	return (EXIT_SUCCESS);
}
