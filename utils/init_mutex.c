#include <philosophers.h>

int	init_main_mutex(t_main *main)
{
	if (pthread_mutex_init(&main->mem_lock, NULL) == -1)
		return (0);
	if (pthread_mutex_init(&main->print_lock, NULL) == -1)
		return (0);
	if (pthread_mutex_init(&main->end_mutex, NULL) == -1)
		return (0);
	return (1);
}

int init_philo_mutex(t_philo *philo)
{
	if (pthread_mutex_init(&philo->own_fork, NULL) == -1)
		return (0);
	if (pthread_mutex_init(&philo->meal_mutex, NULL) == -1)
		return (0);
	return (1);
}
