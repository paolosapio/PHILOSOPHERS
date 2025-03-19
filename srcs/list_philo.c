
#include "philo.h"


t_philo	*new_philo(t_token_value type, char *str, int length)
{
	t_philo *new_philo;

	new_philo = (t_philo *) ft_calloc(sizeof(t_philo), 1);
	if (!new_philo)
		return (NULL);
	new_philo->next = NULL;
	return (new_philo);
}

/**
 * add_token_back receives the head of the list and the new token
 * to add at the end of said list. If there is no head, new becomes it.
 */
void	add_token_back(t_token **lst, t_token *new)
{
	t_token	*temp;

	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
	}
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}