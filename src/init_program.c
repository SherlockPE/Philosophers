#include <philosophers.h>

int init_main(int argc, char **argv, t_main *main)
{
	main->cant_phi = ft_atoi(argv[1]);
	main->tt_die = ft_atoi(argv[2]);
	main->tt_eat = ft_atoi(argv[3]);
	main->tt_sleep = ft_atoi(argv[4]);
	main->cant_meals = 0;
	main->must_eat = -1;
	if (argc == 6)
		main->must_eat = ft_atoi(argv[5]);
	if (!check_positive(main))
		return (ft_exit("The arguments must be strictly positive", 0));
	if (!init_main_mutex(main))
		return (ft_exit("Problems starting the mutex", 0));
	return (1);
}

static void	set_forks(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->cant_phi)
	{
		main->philos[i].right_fork = &main->philos[i + 1].own_fork;
		i++;
	}
	main->philos[i].right_fork = &main->philos[0].own_fork;
}

int init_philos(t_main *main)
{
	int	i;

	main->philos = malloc(main->cant_phi * sizeof(t_philo));
	if (!main->philos)
		return (ft_exit("Malloc error in init philos", 0));
	i = 0;
	while (i < main->cant_phi)
	{
		main->philos[i].id = i + 1;
		i++;
		if (!init_philo_mutex(&main->philos[i]))
		{
			free_program(main, i);
			return (ft_exit("Problems starting the mutex", 0));
		}
	}
	set_forks(main);
	return (2);
}
