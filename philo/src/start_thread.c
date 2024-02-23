/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:41:53 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/23 18:29:18 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

pthread_mutex_t	own_fork;

void	start_to_eat(t_list	*lst)
{
	// int	i;
	
	// i = 1;
	
	//Ir hasta el node que le corresponde
	// while (i < *lst->content->number)
	// 	lst = lst->next;
	
	//Toma su tenedor
	//Toma el siguiente tenedor
	// pthread_mutex_lock(&own_fork);
	// *lst->content->frk = 0;
	// if (lst->next)
	// 	*lst->next->content->frk = 0;
	// pthread_mutex_unlock(&own_fork);

	printf("Filo number:" RED "[%d]\n" RESET, *lst->content->number);
	printf("time to die: %d" RED "[%d]\n" RESET, *lst->content->tt_die, *lst->content->number);
	printf("time to eat: %d" RED "[%d]\n" RESET, *lst->content->tt_eat, *lst->content->number);
	printf("time to sleep: %d" RED "[%d]\n" RESET, *lst->content->tt_sleep, *lst->content->number);
}


void	*philos_routine(void	*arg)
{
	(void)arg;
	// printf("HOla\n");
	t_list	*lst;

	lst = (t_list *)arg;
	//TAKE A FORK
	//TAKE A FORK
	//COME
	//DUERME
	//PIENSA

	start_to_eat(lst);
	// printf("Filo number:" RED "[%d]\n" RESET, *lst->content->number);
	// printf("time to die: %d" RED "[%d]\n" RESET, *lst->content->tt_die, *lst->content->number);
	// printf("time to eat: %d" RED "[%d]\n" RESET, *lst->content->tt_eat, *lst->content->number);
	// printf("time to sleep: %d" RED "[%d]\n" RESET, *lst->content->tt_sleep, *lst->content->number);
	return (0);
}

int start_thread(t_list *data, int optional)
{
	(void)optional;
	t_list	*temp;

	temp = data;
	// pthread_mutex_init(&own_fork, NULL);
	while (temp)
	{
		// printf("Number of philosopher %d\n", *data->content->number);
		if (pthread_create(&temp->content->pt, NULL,  philos_routine, (void *)temp) != 0)
			return (0);
		temp = temp->next;
	}
	while (data)
	{
		if (pthread_join(data->content->pt, NULL) != 0)
			return (0);
		data = data->next;
	}
	// pthread_mutex_destroy(&own_fork);
	return (1);
}
