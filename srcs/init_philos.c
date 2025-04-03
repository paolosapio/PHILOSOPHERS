/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:57:52 by psapio            #+#    #+#             */
/*   Updated: 2025/04/03 17:35:59 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define FORK_LEFT	"🔱 has taken a fork L"
#define FORK_RIGHT	"🔱 has taken a fork R"
#define EATING		"🍝 is eating"
#define SLEEPING	"💤 is sleeping"
#define THINKING	"💡 is thinking"

#define PRINT_STATE "[%5ld] [%3d] %s\n"

void	print_state(char *str, t_philo *philo)
{
	if (philo->data->is_dead == true)
		return ;
	printf(PRINT_STATE, time_diff(philo->data->time_in_ms), philo->id, str);
}

void	philo_eat(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->fork_left);
		print_state(FORK_LEFT, philo);
	}
	else
	{
		pthread_mutex_lock(philo->fork_right);
		print_state(FORK_RIGHT, philo);
	}
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->fork_right);
		print_state(FORK_RIGHT, philo);
	}
	else
	{
		pthread_mutex_lock(philo->fork_left);
		print_state(FORK_LEFT, philo);
	}
	philo->last_meal_start = time_ms();
	print_state(EATING, philo);
	pthread_mutex_lock(&philo->data->mutex_eat);
	philo->times_eat++;
	pthread_mutex_unlock(&philo->data->mutex_eat);
//	printf("philo->times_eat %d\n", philo->times_eat);
	wait_ms_and_check_life(philo->data->time_to_eat, philo);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

bool	philo_sleep(t_philo *philo)
{
	print_state(SLEEPING, philo);
	return (wait_ms_and_check_life(philo->data->time_to_sleep, philo));
}

bool	philo_think(t_philo *philo)
{
	print_state(THINKING, philo);
	return (LIVE);
}



void *check_is_dead(t_philo	*philo)
{
	pthread_mutex_lock(&philo->data->mutex_dead);
	if (philo->data->is_dead)
	{
		pthread_mutex_unlock(&philo->data->mutex_dead);
		return ((void *)DEAD);
	}
	pthread_mutex_unlock(&philo->data->mutex_dead);
	return ((void *)LIVE);
}

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal_start = time_ms();
	while (1)
	{
		if (check_is_dead(philo) == (void *)DEAD)
			return ((void *)DEAD);
		philo_eat(philo);
		if (check_is_dead(philo) == (void *)DEAD)
			return ((void *)DEAD);
		philo_sleep(philo);
		if (check_is_dead(philo) == (void *)DEAD)
			return ((void *)DEAD);
		philo_think(philo);
	}
	return ((void *)DEAD);
}

void	*philo_monitoring(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->data->is_dead)
			return (DEAD);
		if (is_philo_live(philo) == DEAD)
			return (DEAD);
		usleep(100);
	}
}

void	*check_eat_count(void *arg)
{
	t_data_pack	*data;
	int			i;
	int			count_n_philo;

	data = (t_data_pack *)arg;
	while (1)
	{
		i = 0;
		count_n_philo = 0;
		while (i < data->n_philos)
		{
			pthread_mutex_lock(&data->mutex_eat);
			if (data->philos[i].times_eat >= data->n_must_eat)
				count_n_philo++;
			pthread_mutex_unlock(&data->mutex_eat);
			i++;
		}
		usleep(10000);
		if (count_n_philo == data->n_philos)
			break ;
	}
	pthread_mutex_lock(&data->mutex_dead);
	data->is_dead = true;
	pthread_mutex_unlock(&data->mutex_dead);
	return (NULL);
}

void	init_philos(t_data_pack *data)
{
	long	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_create(&data->philos[i].id_thread, \
			NULL, philo_life, &data->philos[i]);
		pthread_create(&data->philos[i].id_thread_monitoring, \
			NULL, philo_monitoring, &data->philos[i]);
		i++;
	}
	if (data->n_must_eat != -1)
		pthread_create(&data->id_thread_times_eat, NULL, check_eat_count, data);
	i = 0;
	while (i < data->n_philos)
	{
		pthread_join(data->philos[i].id_thread, NULL);
		pthread_join(data->philos[i].id_thread_monitoring, NULL);
		i++;
	}
	if (data->n_must_eat != -1)
		pthread_join(data->id_thread_times_eat, NULL);
}
