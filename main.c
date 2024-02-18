/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:11:51 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/02/18 18:49:51 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hilos.h"

int	x;

void	*routine()
{
	printf("Hola\n");

	for (int i = 0; i < 100000; i++)
		x++;
	printf("End of program\n");
	return (0);
}


int main(void)
{
	pthread_t	t1;
	pthread_t	t2;

	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (1);

	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return (1);
	
	if (pthread_join(t1, NULL) != 0)
		return (1);

	if (pthread_join(t2, NULL) != 0)
		return (1);

	printf("Value of X: %d\n", x);
	return 0;
}
