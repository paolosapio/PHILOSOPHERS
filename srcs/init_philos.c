#include "philo.h"

void *print_philo_n(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;
	// usleep(10000 * philo->id_philo);
	printf("Philo nº%d sitting\n", philo->id_philo);
	return  (NULL);
}

void	init_philos(t_data_pack *d_pack)
{
	long	i;

	i = 0;
	while (i < d_pack->n_philos)
	{
		pthread_create(&d_pack->array_of_philosophers[i].id_thread, NULL, print_philo_n, &d_pack->array_of_philosophers[i]);
		i++;
	}
	i = 0;
	while (i < d_pack->n_philos)
	{
		pthread_join(d_pack->array_of_philosophers[i].id_thread, NULL);
		i++;
	}

}
	