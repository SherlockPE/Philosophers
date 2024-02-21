/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:22:56 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/21 15:18:17 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

//PRINT THE TIME SINCE THE PROGRAM STARTED
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

int	ft_atoi(const char *str)
{
	int	symbol;
	int	number;

	number = 0;
	symbol = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			symbol = -symbol;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * symbol);
}

void	free_node(t_philo *node, int optional)
{
	free(node->number);
	free(node->tt_die);
	free(node->tt_eat);
	free(node->tt_sleep);
	if (optional)
		free(node->must_eat);
	free(node);
}

void	free_list(t_list **lst, int optional)
{
	t_list	*temp;
	while (*lst)
	{
		temp = ((*lst)->next);
		free_node((*lst)->content, optional);
		free(*lst);
		*lst = temp;
	}
}
