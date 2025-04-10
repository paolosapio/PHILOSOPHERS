/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutines.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:46:45 by psapio            #+#    #+#             */
/*   Updated: 2025/04/10 20:57:16 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_is_dead(t_philo	*philo)
{
	bool	is_dead;

	pthread_mutex_lock(&philo->data->mutex_dead);
	is_dead = philo->data->is_dead;
	pthread_mutex_unlock(&philo->data->mutex_dead);
	if (is_dead)
		return ((void *)DEAD);
	return ((void *)LIVE);
}

void	philo_eat(t_philo *philo)
{
	if (philo->id != philo->data->n_philos)
	{
		pthread_mutex_lock(philo->fork_right);
		print_state(FORK_RIGHT, philo);
		pthread_mutex_lock(philo->fork_left);
		print_state(FORK_LEFT, philo);
	}
	else
	{
		pthread_mutex_lock(philo->fork_left);
		print_state(FORK_LEFT, philo);
		pthread_mutex_lock(philo->fork_right);
		print_state(FORK_RIGHT, philo);
	}
	
	pthread_mutex_lock(&philo->data->mutex_time);
	philo->last_meal_start = time_ms();
	pthread_mutex_unlock(&philo->data->mutex_time);
	
	print_state(EATING, philo);
	pthread_mutex_lock(&philo->data->mutex_eat);
	philo->times_eat++;
	pthread_mutex_unlock(&philo->data->mutex_eat);
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

void	*philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	pthread_mutex_lock(&philo->data->mutex_time);
	philo->last_meal_start = time_ms();
	pthread_mutex_unlock(&philo->data->mutex_time);
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
