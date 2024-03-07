#include <philosophers.h>

int	check_digits(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!if_isdigit(argv[i][j]))
				return (ft_exit("Arguments must be numbers", 0));
			j++;
		}
		if (j > 6)
			return (ft_exit("Arguments cannot be too long", 0));
		i++;
	}
	return (1);
}

//Function returns 0 if there's an error and 1 if everything is okay
int check_arguments(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	if (!check_digits(argv))
		return (0);
	return (1);
}

int check_positive(t_main *main)
{
	if (main->cant_phi == 0 
		|| main->tt_die == 0 
		|| main->tt_eat == 0
		|| main->tt_sleep == 0 
		|| main->must_eat == 0)
		return (0);
	return (1);
}