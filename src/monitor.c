/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 21:56:34 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/03/08 14:12:41 by flopez-r         ###   ########.fr       */
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
 