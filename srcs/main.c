#include "philo.h"


// EJEMPLO ARGS
// ./philosophers 7 1000 500 

//! CONTROLAR NUMERO DE FILOSOFOS
//! TIEMPO DE VIDA
//! TIEMPO PARA COMER
//! TIEMPO PARA DORMIR
//! (OPCIONAL) NUMERO DE PLATOS MINIMO QUE TIENE QUE COMER CADA FILOSOFO

int main(int argc, char** argv)
{
	if (argc == 5 || argc == 6)
	{
		if (parser(argc, argv) != 0)
			return (1);
	}
	else
		printf("Error: invalid number of arguments\n");
	return (0);
}




























/* void *funcion_espera_hilo1(void *hilo)
{
	int segundos;

	segundos = 10;
	printf("desde hilo 1\n");
	usleep(segundos * 1000000);
	printf("espero 10 segundos\n");
	return (NULL);
}

void *funcion_espera_hilo2(void *hilo)
{
	int segundos;
	
	segundos = 1;
	printf("desde hilo 2\n");
	usleep(segundos * 1000000);
	printf("espero 1 segundo\n");
	return (NULL);
}

int main(int argc, char** argv)
{
	pthread_t hilo1;
	pthread_t hilo2;

	pthread_create(&hilo1, NULL, funcion_espera_hilo1, NULL);
	pthread_create(&hilo2, NULL, funcion_espera_hilo2, NULL);

	pthread_join(hilo1, NULL);
	pthread_join(hilo2, NULL);

	return (0);
 	struct timeval tv;
 	int	n_fork_n_philo;

	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday failed");
		return 1;
	}

	printf("Segundos: %ld\n", tv.tv_sec);
	printf("Microsegundos: %ld\n", tv.tv_usec);
} */