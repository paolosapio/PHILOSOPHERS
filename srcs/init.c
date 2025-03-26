#include "philo.h"

int	init_array_forks(t_data_pack *data)
{
	long i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if(!data->forks)
		return (-1);
	i = 0;
	while(i < data->n_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (0);
}

int	init_array_philo(t_data_pack *data)
{
	int id;

	data->array_of_philosophers = ft_calloc(sizeof(t_philo), data->n_philos);
	if (!data->array_of_philosophers)
		return (-1);
	id = 1;
	while (id <= data->n_philos)
	{
		data->array_of_philosophers[id - 1].id_philo = id;
		data->array_of_philosophers[id - 1].last_meal = 0;
		(void)data->array_of_philosophers[id - 1].id_thread;
		data->array_of_philosophers[id - 1].data = data;
		data->array_of_philosophers[id - 1].fork_left = &data->forks[id - 1];
		if (id != data->n_philos)
			data->array_of_philosophers[id - 1].fork_right = &data->forks[id];
		else
			data->array_of_philosophers[id - 1].fork_right = &data->forks[0];
		id++;
	}
	return (0);
}

t_data_pack init_data(char **argv)
{
	t_data_pack d_pack;
	
	memset(&d_pack, 0, sizeof(t_data_pack));
	d_pack.n_philos = ft_atol(argv[INFO_PH_N_FILOS]);
	d_pack.time_to_die = ft_atol(argv[INFO_PH_TIME_LIFE]);
	d_pack.time_to_eat = ft_atol(argv[INFO_PH_TIME_EAT]);
	d_pack.time_to_sleep = ft_atol(argv[INFO_PH_TIME_SLEEP]);
	if (argv[INFO_PH_N_PLATES])
		d_pack.n_must_eat = ft_atol(argv[INFO_PH_N_PLATES]);
	if (init_array_forks(&d_pack) == -1)
		destroy_data(&d_pack);
	if (init_array_philo(&d_pack) == -1)
		destroy_data(&d_pack);
	return (d_pack);
}

/* 
t_env	*new_env(char *name, char *value)
{
	t_env	*new_env;

	new_env = ft_calloc(sizeof(t_env), 1);
	if (!new_env)
		return (NULL);
	new_env->name = name;
	new_env->value = value;
	new_env->next = NULL;
	return (new_env);
} */

/* {

	int sub1[] = {0, 1};
	int sub2[] = {3, 4};

	int *a[2] = {sub1, sub2};

	int *c = &a;

} */