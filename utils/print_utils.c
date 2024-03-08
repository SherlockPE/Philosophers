/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:44:41 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/03/08 14:52:28 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <philosophers.h>

void    print_status(t_main *main, int id, int status)
{
	pthread_mutex_lock(&main->print_lock);
	long long time;

	time = get_time() - main->start_time;

	if (status == DEAD || !checker_death(main))
	{
		if (status == DEAD)
			printf(YELLOW "[%lld] " RS "%d is " RED "dead 💀\n" RS, time, id);
		else if (status == EAT)
			printf(YELLOW "[%lld] " RS "%d is " GREEN "eating 🍝\n" RS, time, id);
		else if (status == SLEEP)
			printf(YELLOW "[%lld] " RS "%d is " BLUE "sleeping 🌃🛏\n" RS, time, id);
		else if (status == THINK)
			printf(YELLOW "[%lld] " RS "%d is " YELLOW "thinking 🧠\n" RS, time, id);
		else if (status == TK_FORK)
			printf(YELLOW "[%lld] " RS "%d has " CYAN "taken a fork 🍴\n" RS, time, id);
	}
	pthread_mutex_unlock(&main->print_lock);
}
	// if (status == TK_FORK)
	// 	printf(YELLOW "[%lld]"RS"%d has taken a fork 🍴\n", time, id);
	// else if (status == EAT)
	// 	printf(YELLOW "[%lld]"RS"%d is " GREEN "eating 🍝\n", time, id);
	// else if (status == SLEEP)
	// 	printf(YELLOW "[%lld]"RS"%d is sleeping 🛌💤\n", time, id);
	// else if (status == THINK)
	// 	printf(YELLOW "[%lld]"RS"%d is thinking 🧠\n", time, id);
	// else if (status == DEAD)
	// 	printf(YELLOW "[%lld]"RS"%d" RED"died\n" RS, time, id);
