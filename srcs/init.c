#include "philo.h"



t_philo	*init_list_philo(t_data_pack *data)
{
	t_philo *head_list;
	t_philo *node;
	int id;

	id = 1;
	head_list = NULL;
	while (id <= data->n_philos)
	{
		node = ft_lstnew(id);
		if (!node)
			return (NULL);
		pthread_mutex_init(&node->fork, NULL);
		// node->id_thread = NULL;
		node->data = data;
		node->next = NULL;
		ft_lstadd_back(&head_list, node);
		id++;
	}
	return (head_list);
}

t_data_pack *init_data(int argc, char **argv)
{
	t_data_pack *d_pack;

	d_pack = ft_calloc(1, sizeof(t_data_pack));
	d_pack->n_philos = ft_atol(argv[1]);
	d_pack->time_to_die = ft_atol(argv[2]);
	d_pack->time_to_eat = ft_atol(argv[3]);
	d_pack->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		d_pack->n_must_eat = ft_atol(argv[5]);
	init_list_philo(d_pack);
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