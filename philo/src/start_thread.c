// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   start_thread.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/02/21 15:41:53 by flopez-r          #+#    #+#             */
// /*   Updated: 2024/02/24 15:52:04 by flopez-r         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <philosophers.h>

// pthread_mutex_t	own_fork;

// void	get_actual_position(t_list **lst)
// {
// 	int	i;
// 	int	max = *(*lst)->content->number;

// 	i = 1;
// 	while ((*lst)->next != NULL && i < max)
// 		(*lst) = (*lst)->next;
// }

// //TAKE FORKS
// int	get_forks(t_list **lst)
// {
// 	int		eat_status;

// 	eat_status = 0;
// 	pthread_mutex_lock(&own_fork);
// 	(*lst)->content->frk = 0;
// 	eat_status += 1;
// 	print_log(*lst, TK_FORK);
// 	if ((*lst)->next)
// 	{
// 		(*lst)->next->content->frk = 0;
// 		eat_status += 1;
// 		print_log(*lst, TK_FORK);
// 	}
// 	pthread_mutex_unlock(&own_fork);
// 	return (eat_status);
// }

// //Faltan comprobaciones de fallos
// int	start_to_eat(t_list	*lst)
// {
// 	t_list	*actual;

// 	// Ir hasta el nodo que le corresponde
// 	get_actual_position(&lst);
// 	//Toma su tenedor y el siguiente (si es que exite)
// 	if (get_forks(&lst) == 2)
// 		print_log(lst, EAT);

// 	printf("Filo number:" RED "[%d]\n" RESET, *lst->content->number);
// 	printf("time to die: %d" RED "[%d]\n" RESET, *lst->content->tt_die, *lst->content->number);
// 	printf("time to eat: %d" RED "[%d]\n" RESET, *lst->content->tt_eat, *lst->content->number);
// 	printf("time to sleep: %d" RED "[%d]\n" RESET, *lst->content->tt_sleep, *lst->content->number);
// 	// printf("Must eat: %d" RED "[%d]\n" RESET, *lst->content->must_eat, *lst->content->number);

// 	return (1);
// }

// void	*philos_routine(void	*arg)
// {
// 	(void)arg;
// 	// printf("HOla\n");
// 	t_list	*lst;
	

// 	return (1);
// }

// //TAKE A FORK
// //COME
// //TAKE A FORK
// //PIENSA
// //DUERME
// // printf("Filo number:" RED "[%d]\n" RESET, *lst->content->number);
// // start_to_eat(lst);
// // printf("time to die: %d" RED "[%d]\n" RESET, *lst->content->tt_die, *lst->content->number);
// // printf("time to eat: %d" RED "[%d]\n" RESET, *lst->content->tt_eat, *lst->content->number);
// // printf("time to sleep: %d" RED "[%d]\n" RESET, *lst->content->tt_sleep, *lst->content->number);


// int start_thread(t_list *data, int optional)
// {
// 	(void)optional;
// 	t_list	*temp;

// 	temp = data;
// 	// pthread_mutex_init(&own_fork, NULL);
// 	while (temp)
// 	{
// 		// printf("Number of philosopher %d\n", *data->content->number);
// 		if (pthread_create(&temp->content->pt, NULL,  philos_routine, (void *)temp) != 0)
// 			return (0);
// 		temp = temp->next;
// 	}
// 	while (data)
// 	{
// 		if (pthread_join(data->content->pt, NULL) != 0)
// 			return (0);
// 		data = data->next;
// 	}
// 	// pthread_mutex_destroy(&own_fork);
// 	return (1);
// }
