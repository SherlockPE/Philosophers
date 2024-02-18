/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:11:51 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/02/18 20:12:23 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hilos.h"

int	x;
pthread_mutex_t	mutex;

void	*routine()
{
	for (int i = 0; i < 1000; i++)
	{
		pthread_mutex_lock(&mutex);
		x++;
		pthread_mutex_unlock(&mutex);
	}
	sleep(3);
	return (0);
}


int main(void)
{
	int	i;	
	pthread_t	philos[4];

	pthread_mutex_init(&mutex, NULL);
	i = 0;
	while (i < 5)
	{
		if (pthread_create(&philos[i], NULL, &routine, NULL) != 0)
			return (1);
		printf("Hilo %d ha comenzado\n", i);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		if (pthread_join(philos[i], NULL) != 0)
			return (1);
		printf("Hilo %d ha terminado\n", i);
		i++;
	}

	printf("Value of X: %d\n", x);
	pthread_mutex_destroy(&mutex);
	return 0;
}

// int main(void)
// {
// 	pthread_t	t1;
// 	pthread_t	t2;
// 	pthread_t	t3;
// 	pthread_t	t4;
// 	pthread_t	t5;

// 	pthread_mutex_init(&mutex, NULL);

// 	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
// 		return (1);

// 	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
// 		return (1);
	
// 	if (pthread_create(&t3, NULL, &routine, NULL) != 0)
// 		return (1);

// 	if (pthread_create(&t4, NULL, &routine, NULL) != 0)
// 		return (1);

// 	if (pthread_create(&t5, NULL, &routine, NULL) != 0)
// 		return (1);
		
// 	if (pthread_join(t1, NULL) != 0)
// 		return (1);

// 	if (pthread_join(t2, NULL) != 0)
// 		return (1);

// 	if (pthread_join(t3, NULL) != 0)
// 		return (1);

// 	if (pthread_join(t4, NULL) != 0)
// 		return (1);
	
// 	if (pthread_join(t5, NULL) != 0)
// 		return (1);

// 	printf("Value of X: %d\n", x);
// 	pthread_mutex_destroy(&mutex);
// 	return 0;
// }
