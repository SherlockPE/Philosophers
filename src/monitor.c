/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:56:34 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/03/08 00:57:38 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void    *monitor(void *arg)
{
	t_main	*main;

	main = (t_main *) arg;
	while (1)
	{
		if (reaper(main) || meals_done(main))
			break;
	}
	return (0);
}
