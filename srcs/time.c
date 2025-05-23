/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:54:09 by psapio            #+#    #+#             */
/*   Updated: 2025/04/10 19:40:53 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_diff(long time_in_ms)
{
	return (time_ms() - time_in_ms);
}

long	time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long)((tv.tv_sec * 1000) + (tv.tv_usec / 1000)));
}

bool	is_philo_live(t_philo *philo)
{
	long	time_difference;
	long	time_to_die;

	pthread_mutex_lock(&philo->data->mutex_time);
	time_difference = time_diff(philo->last_meal_start);
	pthread_mutex_unlock(&philo->data->mutex_time);
	pthread_mutex_lock(&philo->data->mutex_dead);
	time_to_die = philo->data->time_to_die;
	pthread_mutex_unlock(&philo->data->mutex_dead);
	pthread_mutex_lock(&philo->data->mutex_time);
	if (time_difference > time_to_die)
	{
		print_state("💀 is DEAD", philo);
		pthread_mutex_lock(&philo->data->mutex_dead);
		philo->data->is_dead = true;
		pthread_mutex_unlock(&philo->data->mutex_dead);
		pthread_mutex_unlock(&philo->data->mutex_time);
		return (DEAD);
	}
	pthread_mutex_unlock(&philo->data->mutex_time);
	return (LIVE);
}

bool	wait_ms_and_check_life(long time_wait, t_philo *philo)
{
	const long	time_now = time_ms();
	const long	time_end = time_now + time_wait;

	while (1)
	{
		if (is_philo_live(philo) == DEAD)
			return (DEAD);
		if (get_data_is_dead_protect(philo->data) == true)
			return (DEAD);
		if (time_ms() >= time_end)
			break ;
		usleep(100);
	}
	return (LIVE);
}
