/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:54:09 by psapio            #+#    #+#             */
/*   Updated: 2025/04/03 16:37:57 by psapio           ###   ########.fr       */
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
	pthread_mutex_lock(&philo->data->mutex_dead);
	if (time_diff(philo->last_meal_start) > philo->data->time_to_die)
	{
		print_state("💀 is DEAD", philo);
		philo->data->is_dead = true;
		pthread_mutex_unlock(&philo->data->mutex_dead);
		return (DEAD);
	}
	pthread_mutex_unlock(&philo->data->mutex_dead);
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
		pthread_mutex_lock(&philo->data->mutex_dead);
		if (philo->data->is_dead)
		{
			pthread_mutex_unlock(&philo->data->mutex_dead);
			return (DEAD);
		}
		pthread_mutex_unlock(&philo->data->mutex_dead);

		if (time_ms() >= time_end)
			break ;
		usleep(100);
	}
	return (LIVE);
}
