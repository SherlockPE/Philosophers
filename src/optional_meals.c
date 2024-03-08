/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional_meals.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:57:59 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/03/08 01:02:21 by fabriciolop      ###   ########.fr       */
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
        return (1);
    }
    pthread_mutex_unlock(&main->mem_lock);
    return (0);
}