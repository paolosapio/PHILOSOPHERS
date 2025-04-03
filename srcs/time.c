/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:54:09 by psapio            #+#    #+#             */
/*   Updated: 2025/04/03 15:27:30 by psapio           ###   ########.fr       */
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
	if (time_diff(philo->last_meal_start) > philo->data->time_to_die)
	{
		print_state("💀 is DEAD", philo);
		philo->data->is_dead = true;
		return (DEAD);
	}
	return (LIVE);
}

bool	wait_ms_and_check_life(long time_wait, t_philo *philo)
{
	const long	time_now = time_ms();
	const long	time_end = time_now + time_wait;

	while (1)
	{
		if (is_philo_live(philo) == DEAD || philo->data->is_dead)
			return (DEAD);
		if (time_ms() >= time_end)
			break ;
		usleep(100);
	}
	return (LIVE);
}
