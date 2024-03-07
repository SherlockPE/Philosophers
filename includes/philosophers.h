#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_main t_main;

typedef struct s_philo
{
    t_main  *main;
}			s_philo;

struct s_main
{
	s_philo	*philos;

	int		end;

	int		cant_phi;
	int		tt_die;
	int		tt_eat;
	int		tt_sleep;
	int		must_eat;

	int		cant_meals;
}

//===== Colors section =====

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;97m"
# define OR_WH "\033[0;203m"
# define RESET "\033[0m"


//===== Utils Section =====
/* Libft utils */
int	if_isdigit(int c);
int	ft_strlen(char *string);
int	ft_atoi(const char *str);

/* Error utils */
int	ft_exit(char *message, int exit_c);

/* Time utils */
long long	get_time(void);
int	ft_usleep(unsigned int time);



#endif