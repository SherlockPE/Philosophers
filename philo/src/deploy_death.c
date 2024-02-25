/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:06:35 by fabriciolop       #+#    #+#             */
/*   Updated: 2024/02/25 13:28:17 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*time_to_die(void	*arg)
{
	t_grim_reaper	node;

	node = *(t_grim_reaper *)arg;

	printf("[Number %d] Time to die %d\n", *node.n_philo, *node.tt_die);
	sleep(1);
	printf("FIN\n");
	return (0);
}

int deploy_death(t_grim_reaper *d_lst)
{
	t_grim_reaper	*temp;
	temp = d_lst;
	while (temp)
	{
		if (pthread_create(&temp->death_thread, NULL, time_to_die, temp) != 0)
			return (0);
		temp = temp->next;
	}
	while (d_lst)
	{
		if (pthread_join(d_lst->death_thread, NULL) != 0)
			return (0);
		d_lst = d_lst->next;
	}
	return (1);
}
