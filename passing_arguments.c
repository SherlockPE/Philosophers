#include "hilos.h"

int prime_numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void	d_leaks(void)
{
	system("leaks philo");
}


void    *print_nbr(void *arg)
{
    int i;

    i = *(int *)arg;
    // printf("i function value: %d\n", i);
    printf("Array value: %d\n", prime_numbers[i]);
    free(arg);
    return (0);
}

int main(void)
{
    atexit(d_leaks);
    pthread_t hilos[10];

    for (int i = 0; i < 10; i++)
    {
        int *aux;

        aux = malloc(sizeof(int));
        *aux = i;
        // printf("i main value: %d\n", *aux);
        if (pthread_create(&hilos[i], NULL, print_nbr, aux) != 0)
            return (1);
    }
    for (int i = 0; i < 10; i++)
    {
        if (pthread_join(hilos[i], NULL))
            return (1);
    }
}