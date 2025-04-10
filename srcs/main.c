/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:10:22 by psapio            #+#    #+#             */
/*   Updated: 2025/04/10 21:00:28 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data_pack	d_pack;

	if (argc == 5 || argc == 6)
	{
		if (parser(argv) == ST___ERROR)
			return (ST___ERROR);
		memset(&d_pack, 0, sizeof(t_data_pack));
		if (init_data(&d_pack, argv) == DEAD)
			return (1);
		init_philos(&d_pack);
		destroy_data(&d_pack);
	}
	else
	{
		printf("Error: invalid number of arguments\n");
		return (1);
	}
	return (0);
}

// ./philo 3 400 103 103 esto es el tiempo limite tiene que funcionar!!
// ./philo 3 300 99 99

// ./philo 3 300 99 99 muere y no debe