#include "philo.h"

void	init_philo(int id, t_data_pack *data)
{
	t_philo philo;
	int i;

	i = 0;
	philo.id_philo = id;
	philo.last_meal = 0;
	pthread_mutex_init(&philo.fork, NULL);
	(void)philo.id_thread;
	philo.data = data;
	data->array_of_philosophers[i] = philo;
}

void	*init_array_philo(t_data_pack *data)
{
	int id;

	id = 1;
	data->array_of_philosophers = ft_calloc(sizeof(t_philo), data->n_philos);
	if (!data->array_of_philosophers)
		return (NULL);
	while (id <= data->n_philos)
	{
		init_philo(id, data);
	
		id++;
	}
	return (data);
}

t_data_pack init_data(int argc, char **argv)
{
	(void)argc;
	t_data_pack d_pack;

	d_pack.n_philos = ft_atol(argv[INFO_PH_N_FILOS]);
	d_pack.time_to_die = ft_atol(argv[INFO_PH_TIME_LIFE]);
	d_pack.time_to_eat = ft_atol(argv[INFO_PH_TIME_EAT]);
	d_pack.time_to_sleep = ft_atol(argv[INFO_PH_TIME_SLEEP]);
	if (argv[INFO_PH_N_PLATES])
		d_pack.n_must_eat = ft_atol(argv[INFO_PH_N_PLATES]);
	init_array_philo(&d_pack);
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