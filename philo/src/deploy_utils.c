/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:54:15 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/20 16:48:13 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	negative_values_not_allowed(t_philo *data, int optional)
{
	// CHECK IF THE VALUES ARE NEGATIVE
	if (*data->number < 0 || *data->tt_die < 0 || *data->tt_eat < 0
		|| *data->tt_sleep < 0 || (optional && *data->must_eat < 0))
	{
		free_all(data, optional);
		printf("The arguments can not be negative\n");
		return (0);
	}
	return (1);
}

t_list	*lst_new(char **argv, int optional, int i)
{
	t_list	*new;

	// Allocating memory for the node
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);

	// Allocating memory for the content of node
	new->content = malloc(sizeof(t_philo));
	if (!new->content)
		return (NULL);

		
	// Allocating memory for 4 principal arguments
	new->content->number = malloc(sizeof(int));
	new->content->tt_die = malloc(sizeof(int));
	new->content->tt_eat = malloc(sizeof(int));
	new->content->tt_sleep = malloc(sizeof(int));

	// Protection of mallocs
	if (!new->content->number || !new->content->tt_die || !new->content->tt_eat
		|| !new->content->tt_sleep)
		return (NULL);

	// Optional value memory asignation of memory and value
	if (optional)
	{
		new->content->must_eat = malloc(sizeof(int));
		if (!new->content->must_eat)
			return (NULL);
		*new->content->must_eat = ft_atoi(argv[5]);
	}

	// Assigning values for the program
	*new->content->number = i;
	*new->content->tt_die = ft_atoi(argv[2]);
	*new->content->tt_eat = ft_atoi(argv[3]);
	*new->content->tt_sleep = ft_atoi(argv[4]);
	
	negative_values_not_allowed(new->content, optional);
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
		if (!new)
			return (0);
		lst_addback(philos, new);
		i++;
	}
	return (1);
}

void	print_node(t_philo	*philo, int optional)
{
	printf(GREEN"Number of filosofer: %d\n"RESET, *philo->number);
	printf("Time to die: %d\n", *philo->tt_die);
	printf("Time to eat: %d\n", *philo->tt_eat);
	printf("Time to sleep: %d\n", *philo->tt_sleep);
	if (optional)
		printf("Time a philo must eat: %d\n", *philo->must_eat);
}


void	print_list(t_list *header, int optional)
{
	while (header)
	{
		print_node(header->content, optional);
		header = header->next;
	}
}
