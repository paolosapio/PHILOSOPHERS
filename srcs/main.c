/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:10:22 by psapio            #+#    #+#             */
/*   Updated: 2025/04/03 15:11:25 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data_pack	d_pack;

	if (argc == 5 || argc == 6)
	{
		if (parser(argc, argv) == ST___ERROR)
			return (ST___ERROR);
		memset(&d_pack, 0, sizeof(t_data_pack));
		init_data(&d_pack, argv);
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
