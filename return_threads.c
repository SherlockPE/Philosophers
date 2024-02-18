#include "hilos.h"


void    *random_number()
{
    int r;
    int *result;

    r = (rand() % 6) + 1;

    result = calloc(1, 4);
    *result = r;

    printf("Function direction:  %p, %d\n", result, *result);

    return (result);
}


int main(void)
{
    srand(time(NULL));

    int *result;
    pthread_t   hilo1;

    result = 0;
    if (pthread_create(&hilo1, NULL, random_number, NULL) != 0)
        return (1);

    if (pthread_join(hilo1, (void **) &result) != 0)
        return (1);

    printf("Main direction:      %p, %d\n", result, *result);
    return 0;
}
