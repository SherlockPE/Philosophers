/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:11:51 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/02/18 19:35:12 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hilos.h"

int	x;
pthread_mutex_t	mutex;

void	*routine()
{
	printf("Hola\n");

	for (int i = 0; i < 100000000; i++)
	{
		pthread_mutex_lock(&mutex);
		x++;
		pthread_mutex_unlock(&mutex);
	}
	printf("End of program\n");
	return (0);
}


int main(void)
{
	pthread_t	t1;
	pthread_t	t2;
	pthread_mutex_init(&mutex, NULL);

	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (1);

	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return (1);
	
	if (pthread_join(t1, NULL) != 0)
		return (1);

	if (pthread_join(t2, NULL) != 0)
		return (1);

	printf("Value of X: %d\n", x);
	pthread_mutex_destroy(&mutex);
	return 0;
}
