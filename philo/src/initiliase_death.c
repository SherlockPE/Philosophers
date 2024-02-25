/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:17:49 by flopez-r          #+#    #+#             */
/*   Updated: 2024/02/24 22:30:06 by fabriciolop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	free_all_dlst(t_grim_reaper **lst)
{
	t_grim_reaper *temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free((*lst)->n_philo);
		free((*lst)->tt_die);
		free((*lst));
		*lst = temp;
	}
	return (0);
}

t_grim_reaper	*dlst_new(int time_die, int number)
{
	t_grim_reaper *new;

	new = ft_calloc(1, sizeof(t_grim_reaper));
	new->tt_die = ft_calloc(1, sizeof(int));
	new->n_philo = ft_calloc(1, sizeof(int));

	if (!new || !new->tt_die || !new->n_philo)
		return (NULL);

	*new->tt_die = time_die;
	*new->n_philo = number;
	new->next = NULL;
	return (new);
}

void	dlst_addback(t_grim_reaper **nick, t_grim_reaper *new)
{
	t_grim_reaper *temp;
	if (!(*nick))
	{
		*nick = new;
		return ;
	}
	temp = (*nick);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;	
}

int set_death_list(t_grim_reaper **nick, char **argv)
{
	int	cant_f;
	int	i;
	int	time_die;
	t_grim_reaper *new;
	
	i = 1;
	cant_f = ft_atoi(argv[1]);
	time_die = ft_atoi(argv[2]);
	while (i <= cant_f)
	{
		new = dlst_new(time_die, i);
		if (!new)
			return(free_all_dlst(nick));
		dlst_addback(nick, new);
		i++;
	}
	return (1);
}
