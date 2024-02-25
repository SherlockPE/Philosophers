/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:56 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/25 13:20:23 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	print_time(t_list *data)
{
	int		error_case;
	long	seconds;
	long	ms;

	error_case = gettimeofday(&data->time_now, NULL);
	if (error_case == -1)
		return (0);
	seconds = (data->time_now.tv_sec - data->time_init.tv_sec) * 1000;
	ms = (data->time_now.tv_usec - data->time_init.tv_usec) / 1000;
	printf(WHITE"[%ld]" RESET, seconds + ms);
	return (1);
}

int	ft_usleep(unsigned int time)
{
	unsigned long ms;
	unsigned long end;
	struct timeval time_new;

	if (gettimeofday(&time_new, NULL))
		return (-1);

	ms = (time_new.tv_sec * 1000000) + time_new.tv_usec;
	end = ms + time;

	while (ms < end)
	{
		if (gettimeofday(&time_new, NULL))
			return (-1);
		ms = (time_new.tv_sec * 1000000) + time_new.tv_usec;
	}
	return (0);
}

// unsigned long	get_time(void)
// {
// 	struct timeval	new_time;
// 	unsigned long ms;

// 	if (gettimeofday(&new_time, NULL))
// 		return (-1);
// 	ms = 
// }

// void	free_node(t_philo *node, int optional)
// {
// 	free(node->number);
// 	free(node->tt_die);
// 	free(node->tt_eat);
// 	free(node->tt_sleep);
// 	free(node->frk);
// 	if (optional)
// 		free(node->must_eat);
// 	free(node);
// }

// void	free_list(t_list **lst, int optional)
// {
// 	t_list	*temp;
// 	while (*lst)
// 	{
// 		temp = ((*lst)->next);
// 		free_node((*lst)->content, optional);
// 		free(*lst);
// 		*lst = temp;
// 	}
// }

//PRINT THE LIST 
// void	print_node(t_grim_reaper	*lst)
// {
// 	printf("[Number %d] ", *lst->tt_die);
// 	printf("Time to die %d\n", *lst->n_philo);
// }


// void	print_list(t_grim_reaper *lst)
// {
// 	while (lst)
// 	{
// 		printf("[Number %d] ", *lst->tt_die);
// 		printf("Time to die %d\n", *lst->n_philo);
// 		lst = lst->next;
// 	}
// }


//LIBFT UTILS

