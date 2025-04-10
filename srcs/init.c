/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:03:22 by psapio            #+#    #+#             */
/*   Updated: 2025/04/10 19:40:16 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_array_forks(t_data_pack *data)
{
	long	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philos);
	if (!data->forks)
		return (-1);
	i = 0;
	while (i < data->n_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (0);
}

int	init_array_philo(t_data_pack *data)
{
	int	id;

	data->philos = ft_calloc(sizeof(t_philo), data->n_philos);
	if (!data->philos)
		return (-1);
	id = 1;
	while (id <= data->n_philos)
	{
		data->philos[id - 1].id = id;
		data->philos[id - 1].last_meal_start = data->time_in_ms;
		(void)data->philos[id - 1].id_thread;
		data->philos[id - 1].data = data;
		data->philos[id - 1].fork_left = &data->forks[id - 1];
		data->philos[id - 1].fork_right = &data->forks[id];
		if (id == data->n_philos)
			data->philos[id - 1].fork_right = &data->forks[0];
		data->philos[id - 1].times_eat = 0;
		id++;
	}
	return (0);
}

bool	is_one_philo_dead(t_data_pack *d_pack)
{
	printf("[    1] [  1] 🔱 has taken a fork L\n");
	usleep(d_pack->time_to_die * 1000);
	printf("[%5ld] [  1] 💀 is DEAD\n", d_pack->time_to_die);
	return (DEAD);
}

bool	init_data(t_data_pack *d_pack, char **argv)
{
	d_pack->is_dead = false;
	d_pack->time_in_ms = time_ms();
	d_pack->n_philos = ft_atol(argv[INFO_PH_N_FILOS]);
	d_pack->time_to_die = ft_atol(argv[INFO_PH_TIME_LIFE]);
	d_pack->time_to_eat = ft_atol(argv[INFO_PH_TIME_EAT]);
	d_pack->time_to_sleep = ft_atol(argv[INFO_PH_TIME_SLEEP]);
	d_pack->n_must_eat = -1;
	if (argv[INFO_PH_N_PLATES])
		d_pack->n_must_eat = ft_atol(argv[INFO_PH_N_PLATES]);
	if (d_pack->n_philos == 1)
		return (is_one_philo_dead(d_pack));
	if (init_array_forks(d_pack) == -1)
		destroy_data(d_pack);
	if (init_array_philo(d_pack) == -1)
		destroy_data(d_pack);
	pthread_mutex_init(&d_pack->mutex_eat, NULL);
	pthread_mutex_init(&d_pack->mutex_dead, NULL);
	pthread_mutex_init(&d_pack->mutex_time, NULL);
	pthread_mutex_init(&d_pack->mutex_print, NULL);
	return (LIVE);
}
