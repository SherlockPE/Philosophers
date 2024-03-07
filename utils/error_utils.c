#include <philosophers.h>

int	ft_exit(char *message, int exit_c)
{
	printf(RED "%s" RESET, message);
	return (exit_c);
}
