/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:54:17 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/26 12:36:51 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

// FUNCTION PRINTS THE LOG STAT
// 0 -> DIED
// 1 -> EATEN
// 2 -> SLEEPING
// 3 -> THINKING
// 4 -> TAKE A FORK
int	print_log(int	number, unsigned int status)
{
	if (status == DEAD)
		printf("%d is " RED "dead 💀\n"RESET, number);
	else if (status == EAT)
		printf("%d is " GREEN "eating 🍝\n"RESET, number);
	else if (status == SLEEP)
		printf("%d is " BLUE "sleeping 🌃🛏\n"RESET, number);
	else if (status == THINK)
		printf("%d is " YELLOW "thinking 🧠\n"RESET, number);
	else if (status == TK_FORK)
		printf("%d has " CYAN "taken a fork 🍴\n"RESET, number);
	return (1);
}
// int	print_log(int	number, unsigned int status)
// {
// 	if (status == DEAD)
// 		printf(YELLOW "[%d]"RESET" %d ""is " RED "dead 💀\n"RESET, get_time(), number);
// 	else if (status == EAT)
// 		printf(YELLOW "[%d]"RESET" %d ""is " GREEN "eating 🍝\n"RESET, get_time(), number);
// 	else if (status == SLEEP)
// 		printf(YELLOW "[%d]"RESET" %d ""is " BLUE "sleeping 🌃🛏\n"RESET, get_time(), number);
// 	else if (status == THINK)
// 		printf(YELLOW "[%d]"RESET" %d ""is " YELLOW "thinking 🧠\n"RESET, get_time(), number);
// 	else if (status == TK_FORK)
// 		printf(YELLOW "[%d]"RESET" %d ""has " CYAN "taken a fork 🍴\n"RESET, get_time(), number);
// 	return (1);
// }
