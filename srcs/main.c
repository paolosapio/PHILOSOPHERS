#include "philo.h"

// EJEMPLO ARGS
// ./philo 7 1000 500 52 3
int main(int argc, char **argv)
{
	t_data_pack d_pack;

	if (argc == 5 || argc == 6)
	{
		if (parser(argc, argv) == ST___ERROR)
			return (ST___ERROR);
		memset(&d_pack, 0, sizeof(t_data_pack));
		init_data(&d_pack, argv);
		init_philos(&d_pack); //pthread_create 
		destroy_data(&d_pack);
	}
	else
	{
		printf("Error: invalid number of arguments\n");
		return (1);
	}
	return (0);
}

//todo Los filósofos solo pueden comer, pensar, o dormir.
//todo Mientras están comiendo, no pueden pensar ni dormir; init_philo
//todo Mientras están pensando, no pueden dormir ni comer;
//todo Y, por supuesto, mientras están durmiendo, no pueden comer ni pensar.

/* int main(int argc, char** argv)
{
	t_philo	*current_philo;

	current_philo = data->list_of_philosophers;

	while (current->id_philo )

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
}  */






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