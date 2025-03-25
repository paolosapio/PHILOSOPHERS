#include "philo.h"

void	destroy_data(t_data_pack *data)
{
	long i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_destroy(&(data->forks)[i]);
		i++;
	}
	if (data->array_of_philosophers)
	{
		free(data->array_of_philosophers);
		data->array_of_philosophers = NULL;
	}
	if (data->forks)
	{
		free(data->forks);
		data->forks = NULL;
	}
}
