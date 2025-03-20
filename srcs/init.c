#include "philo.h"

static void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *head_aux;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	head_aux = *lst;
	while (head_aux->next)
	{
		head_aux = head_aux->next;
	}
	head_aux->next = new;
}

static t_philo *ft_lstnew(void)
{
	t_philo *node;
	node = malloc(sizeof(t_philo));

	node->id_philo = 1;
	
	node->last_meal = 0;
	node->id_thread = NULL;
	node->next = NULL;

	return (node);
}

void	init_list_philo(t_philo *firt_node, t_data_pack *data)
{
	t_philo	*first;
	t_philo *head_list;
	t_philo *node;
	int i;

	i = 1;
	head_list = NULL;
	while (i <= data->n_philos)
	{
			
		node = malloc(sizeof(t_philo));
		node->id_philo = i;
		node->last_meal = 0;
		pthread_mutex_init(&node->fork, NULL);
		node->id_thread = NULL;
		node->data = data;
		node->next = NULL;
		ft_lstadd_back(&head_list, node);
		if (i == 1)
			first = node;
		i++;
	}
	node->next = first;
	return (first);
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
	d_pack->list_of_philosophers = ft_lstnew();
	init_list_philo(d_pack->list_of_philosophers, d_pack);
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