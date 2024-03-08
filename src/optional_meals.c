/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional_meals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:57:59 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/03/08 14:40:38 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int meals_done(t_main *main)
{
    if (main->must_eat == -1)
        return (0);
    pthread_mutex_lock(&main->mem_lock);
    if (main->cant_meals == main->cant_phi)
    {
        atropos_cut(main);
        pthread_mutex_unlock(&main->mem_lock);
        return (1);
    }
    pthread_mutex_unlock(&main->mem_lock);
    return (0);
}

void    *optional_meals(void *arg)
{
    t_main	*main;

	main = (t_main *) arg;
    while (1)
    {
        if (meals_done(main))
            break;
    }
    return (0);
}