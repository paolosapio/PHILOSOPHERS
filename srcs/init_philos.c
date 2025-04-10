/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:57:52 by psapio            #+#    #+#             */
/*   Updated: 2025/04/10 20:16:29 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_data_pack *data)
{
	long	i;

	i = 0;
	while (i < data->n_philos)
	{
		pthread_create(&data->philos[i].id_thread, NULL,
			philo_life, &data->philos[i]);
		i++;
	}
	pthread_create(&data->id_thread_monitoring, NULL,
		philo_monitoring_all, data);
	if (data->n_must_eat != -1)
		pthread_create(&data->id_thread_times_eat, NULL, eat_monitoring, data);
	i = 0;
	while (i < data->n_philos)
	{
		pthread_join(data->philos[i].id_thread, NULL);
		i++;
	}
	pthread_join(data->id_thread_monitoring, NULL);
	if (data->n_must_eat != -1)
		pthread_join(data->id_thread_times_eat, NULL);
}
