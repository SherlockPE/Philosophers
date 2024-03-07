/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:44:41 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/03/07 19:27:14 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <philosophers.h>

void    print_status(t_main *main, int id, int status)
{
	pthread_mutex_lock(&main->print_lock);
	long long time;

	time = get_time() - main->start_time;
	if (status == TK_FORK)
		printf("[%lld] %d has taken a fork 🍴\n", time, id);
	else if (status == EAT)
		printf("[%lld] %d is eating 🍝\n", time, id);
	else if (status == SLEEP)
		printf("[%lld] %d is sleeping 🛌💤\n", time, id);
	else if (status == THINK)
		printf("[%lld] %d is thinking 🧠\n", time, id);
	else if (status == DEAD)
		printf("[%lld] %d died\n", time, id);
	pthread_mutex_unlock(&main->print_lock);
}
