#include <philosophers.h>

int	ft_exit(char *message, int exit_c)
{
	printf(RED "%s\n" RS, message);
	return (exit_c);
}

void	free_program(t_main *main, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		pthread_mutex_destroy(&main->philos[i].own_fork);
		pthread_mutex_destroy(&main->philos[i].meal_mutex);
		i++;
	}
	pthread_mutex_destroy(&main->mem_lock);
	pthread_mutex_destroy(&main->print_lock);
	pthread_mutex_destroy(&main->end_mutex);
	free(main->philos);
}