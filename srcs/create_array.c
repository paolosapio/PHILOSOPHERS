#include "philo.h"

t_philo *ft_lstnew(int id)
{
	t_philo *array_philo;

	node = malloc(sizeof(t_philo));
	node->id_philo = id;
	node->last_meal = 0;
	// node->id_thread = NULL;
	node->next = NULL;

	return (node);
}
