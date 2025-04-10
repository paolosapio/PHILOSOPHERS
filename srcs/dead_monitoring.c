/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_monitoring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:57:52 by psapio            #+#    #+#             */
/*   Updated: 2025/04/10 20:22:25 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	get_data_is_dead_protect(t_data_pack *data)
{
	bool	is_dead;

	pthread_mutex_lock(&data->mutex_dead);
	is_dead = data->is_dead;
	pthread_mutex_unlock(&data->mutex_dead);
	return (is_dead);
}

void	print_state(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_print);
	if (get_data_is_dead_protect(philo->data) == true)
	{
		pthread_mutex_unlock(&philo->data->mutex_print);
		return ;
	}
	printf(PRINT_STATE, time_diff(philo->data->time_in_ms), philo->id, str);
	pthread_mutex_unlock(&philo->data->mutex_print);
}

void	*philo_monitoring_all(void *arg)
{
	t_data_pack	*data;
	bool		is_dead;
	int			i;

	data = (t_data_pack *)arg;
	while (1)
	{
		pthread_mutex_lock(&data->mutex_dead);
		is_dead = data->is_dead;
		pthread_mutex_unlock(&data->mutex_dead);
		if (is_dead)
		{
			return (DEAD);
		}
		i = 0;
		while (i < data->n_philos)
		{
			if (is_philo_live(&data->philos[i]) == DEAD)
				return (DEAD);
			i++;
		}
		usleep(100);
	}
}

int	check_eat_count(t_data_pack *data)
{
	int			i;
	int			times_eat;
	long		n_must_eat;
	int			count_n_philo;

	count_n_philo = 0;
	pthread_mutex_lock(&data->mutex_eat);
	n_must_eat = data->n_must_eat;
	pthread_mutex_unlock(&data->mutex_eat);
	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_lock(&data->mutex_eat);
		times_eat = data->philos[i].times_eat;
		pthread_mutex_unlock(&data->mutex_eat);
		if (times_eat >= n_must_eat)
			count_n_philo++;
		i++;
	}
	return (count_n_philo);
}

void	*eat_monitoring(void *arg)
{
	t_data_pack	*data;
	int			count_n_philo;

	data = (t_data_pack *)arg;
	while (1)
	{
		count_n_philo = check_eat_count(data);
		usleep(10000);
		if (count_n_philo == data->n_philos || \
			get_data_is_dead_protect(data) == true)
		{
			break ;
		}
	}
	pthread_mutex_lock(&data->mutex_dead);
	data->is_dead = true;
	pthread_mutex_unlock(&data->mutex_dead);
	return (NULL);
}
