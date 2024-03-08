/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:56:34 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/03/08 22:56:30 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void    *monitor(void *arg)
{
	t_main	*main;

	main = (t_main *) arg;
	if (main->must_eat > 0)
	{
		if (pthread_create(&main->optional, NULL, optional_meals, main))
			return (0);
	}
	while (1)
	{
		if (reaper(main))
			break;
	}
	if (main->must_eat > 0)
	{
		if (pthread_join(main->optional, NULL))
			return (0);
	}
	return (0);
}
 