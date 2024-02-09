/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:47:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/09 18:29:55 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(void)
{
	// DISCOVERING FUNCTIONS
	//1.- gettimeofday

	struct timeval	time;
	int	error_case;
	int	error_case;
	int	error_case;

	error_case = gettimeofday(&time, NULL);
	printf("Seconds		: %ld\n", time.tv_sec);
	printf("miliseconds	: %d\n", time.tv_usec);

	return 0;
}
