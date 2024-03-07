#include <philosophers.h>


int main(int argc, char const *argv[])
{
	t_main	main;
	if (!check_arguments(argc, argv));
		return (ft_exit("Invalid Arguments", EXIT_FAILURE));
	if (init_main(argc, argv, &main))
		return (1);
		
	return 0;
}
