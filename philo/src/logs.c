/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:54:17 by flopez-r          #+#    #+#             */
/*   Updated: 2024/03/04 19:04:03 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

// FUNCTION PRINTS THE LOG STAT
// 0 -> DIED
// 1 -> EATEN
// 2 -> SLEEPING
// 3 -> THINKING
// 4 -> TAKE A FORK
int	print_log(int	id, unsigned int status, t_main *data)
{
	if (status == DEAD)
		printf(YELLOW"[%lld] "RESET"%d is " RED "dead 💀\n"RESET, get_pt(data),id);
	else if (status == EAT)
		printf(YELLOW"[%lld] "RESET"%d is " GREEN "eating 🍝\n"RESET, get_pt(data),id);
	else if (status == SLEEP)
		printf(YELLOW"[%lld] "RESET"%d is " BLUE "sleeping 🌃🛏\n"RESET, get_pt(data),id);
	else if (status == THINK)
		printf(YELLOW"[%lld] "RESET"%d is " YELLOW "thinking 🧠\n"RESET, get_pt(data),id);
	else if (status == TK_FORK)
		printf(YELLOW"[%lld] "RESET"%d has " CYAN "taken a fork 🍴\n"RESET, get_pt(data),id);
	return (1);
}
