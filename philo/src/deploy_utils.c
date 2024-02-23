/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:54:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/23 14:13:39 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_list	*lst_new(char **argv, int optional, int i)
{
	t_list	*new;

	// Allocating memory for the node
	new = calloc(sizeof(t_list), 1);
	if (!new)
		return (NULL);

	// Allocating memory for the content of node
	new->content = calloc(sizeof(t_philo), 1);
	if (!new->content)
		return (NULL);

		
	// Allocating memory for 4 principal arguments
	new->content->number = calloc(sizeof(int), 1);
	new->content->tt_die = calloc(sizeof(int), 1);
	new->content->tt_eat = calloc(sizeof(int), 1);
	new->content->tt_sleep = calloc(sizeof(int), 1);
	new->content->frk = calloc(sizeof(int), 1);

	// Protection of callo, 1cs
	if (!new->content->number || !new->content->tt_die || !new->content->tt_eat
		|| !new->content->tt_sleep
		|| !new->content->frk)
		return (NULL);

	// Optional value memory asignation of memory and value
	if (optional)
	{
		new->content->must_eat = calloc(sizeof(int), 1);
		if (!new->content->must_eat)
			return (NULL);
		*new->content->must_eat = ft_atoi(argv[5]);
	}

	// Assigning values for the program
	*new->content->number = i;
	*new->content->tt_die = 1;
	*new->content->tt_die = ft_atoi(argv[2]);
	*new->content->tt_eat = ft_atoi(argv[3]);
	*new->content->tt_sleep = ft_atoi(argv[4]);

	new->next = NULL;
	return (new);
}

void	lst_addback(t_list	**philos, t_list	*new)
{
	t_list *temp;

	if (!*philos)
	{
		*philos = new;
		return ;
	}
	temp = *philos;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}


int	set_philos(t_list **philos, char **argv, int optional)
{
	t_list	*new;
	int		cant_f;
	int		i;
	
	cant_f = ft_atoi(argv[1]);
	if (cant_f <= 0)
	{
		printf(RED"The numbers of philos can not be negative or 0\n"RESET);
		return (0);
	}
	i = 1;
	while (i <= cant_f)
	{
		new = lst_new(argv, optional, i);
		if (!new) //IF THIS FAILS FREE ALL THE LIST
			return (0);
		lst_addback(philos, new);
		i++;
	}
	return (1);
}

