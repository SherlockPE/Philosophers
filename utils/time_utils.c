#include <philosophers.h>

/* Function gets the actual time of the computer
if there's some error it returns -1 */
long long	get_time(void)
{
	struct timeval	init_time;
	long long		actual_time_ms;

	if (gettimeofday(&init_time, NULL) == -1)
	{
		printf("Gettime failed");
		return (-1);
	}
	actual_time_ms = (init_time.tv_sec * 1000) + (init_time.tv_usec / 1000);
	return (actual_time_ms);
}

/* Functions replicates usleep but with more precision using the
time of the cmputer */
int	ft_usleep(unsigned int time)
{
	long long	ms;
	long long	end;

	ms = get_time();
	if (ms == -1)
		return (ft_exit("Error en ft_usleep", 0));
	end = ms + time;
	usleep(time * 100);
	while (ms < end)
	{
		usleep(time);
		ms = get_time();
		if (ms == -1)
			return (ft_exit("Error en ft_usleep", 0));
	}
	return (0);
}

