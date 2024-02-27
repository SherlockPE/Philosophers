/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_philos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:55:21 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/27 16:29:07 by flopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

// t_philo	*lst_new(char **argv, int optional, int i)
// {
// 	t_philo	*new;

// 	// Allocating memory for the node
// 	new = calloc(sizeof(t_philo), 1);
// 	if (!new)
// 		return (NULL);

// 	// Allocating memory for the content of node
// 	new = calloc(sizeof(t_philo), 1);
// 	if (!new)
// 		return (NULL);

		
// 	// Allocating memory for 4 principal arguments
// 	new->number = calloc(sizeof(int), 1);
// 	new->tt_eat = calloc(sizeof(int), 1);
// 	new->tt_sleep = calloc(sizeof(int), 1);
// 	new->frk = calloc(sizeof(int), 1);

// 	// Protection of callo, 1cs
// 	if (!new->number || !new->tt_eat
// 		|| !new->tt_sleep
// 		|| !new->frk)
// 		return (NULL);

// 	// Optional value memory asignation of memory and value
// 	if (optional)
// 	{
// 		new->must_eat = calloc(sizeof(int), 1);
// 		if (!new->must_eat)
// 			return (NULL);
// 		*new->must_eat = ft_atoi(argv[5]);
// 	}

// 	// Assigning values for the program
// 	*new->number = i;
// 	*new->tt_eat = ft_atoi(argv[3]);
// 	*new->tt_sleep = ft_atoi(argv[4]);

// 	new->next = NULL;
// 	return (new);
// }

// void	lst_addback(t_philo	**philos, t_philo	*new)
// {
// 	t_philo *temp;

// 	if (!*philos)
// 	{
// 		*philos = new;
// 		return ;
// 	}
// 	temp = *philos;
// 	while (temp->next)
// 		temp = temp->next;
// 	temp->next = new;
// }


// int	set_philos(t_philo **philos, char **argv, int optional)
// {
// 	t_philo	*new;
// 	int		cant_f;
// 	int		i;
	
// 	cant_f = ft_atoi(argv[1]);
// 	if (cant_f <= 0)
// 	{
// 		printf(RED"The numbers of philos can not be negative or 0\n"RESET);
// 		return (0);
// 	}
// 	i = 1;
// 	while (i <= cant_f)
// 	{
// 		new = lst_new(argv, optional, i);
// 		if (!new) //IF THIS FAILS FREE ALL THE LIST
// 			return (0);
// 		lst_addback(philos, new);
// 		i++;
// 	}
// 	return (1);
// }