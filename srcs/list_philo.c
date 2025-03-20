
#include "philo.h"

void ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo *head_aux;

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

t_philo *ft_lstnew(int id)
{
	t_philo *node;

	node = malloc(sizeof(t_philo));
	node->id_philo = id;
	node->last_meal = 0;
	// node->id_thread = NULL;
	node->next = NULL;

	return (node);
}
