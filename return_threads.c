#include "hilos.h"


void    *random_number()
{
	int r;
	int *result;

	r = (rand() % 20) + 1;

	result = calloc(1, 4);
	*result = r;

	// printf("Function value and address:  %p, %d\n", result, *result);
	return (result);
}

void	d_leaks(void)
{
	system("leaks philo");
}

int main(void)
{

	atexit(d_leaks);
	srand(time(NULL));

	int *result;
	pthread_t   hilos[5];

	result = 0;


	for (int i = 0; i < 5; i++)
	{
		if (pthread_create(&hilos[i], NULL, random_number, NULL) != 0)
			return (1);
		printf("Iniciando hilo %d\n", i);
	}
	for (int i = 0; i < 5; i++)
	{
		if (pthread_join(hilos[i], (void **) &result) != 0)
			return (1);
		printf("Number value and address:    %p, %d\n", result, *result);
		free(result);
	}


	return 0;
}
