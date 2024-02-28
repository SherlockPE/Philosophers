/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:54:17 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/28 15:17:03 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

// FUNCTION PRINTS THE LOG STAT
// 0 -> DIED
// 1 -> EATEN
// 2 -> SLEEPING
// 3 -> THINKING
// 4 -> TAKE A FORK
int	print_log(int	id, unsigned int status)
{
	if (status == DEAD)
		printf(WHITE " %d " RESET "is " RED "dead 💀\n"RESET, id);
	else if (status == EAT)
		printf(WHITE " %d " RESET "is " GREEN "eating 🍝\n"RESET, id);
	else if (status == SLEEP)
		printf(WHITE " %d " RESET "is " BLUE "sleeping 🌃🛏\n"RESET, id);
	else if (status == THINK)
		printf(WHITE " %d " RESET "is " YELLOW "thinking 🧠\n"RESET, id);
	else if (status == TK_FORK)
		printf(WHITE " %d " RESET "has " CYAN "taken a fork 🍴\n"RESET, id);
	return (1);
}
