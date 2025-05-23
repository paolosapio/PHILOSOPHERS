/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:15:51 by psapio            #+#    #+#             */
/*   Updated: 2025/04/11 16:21:32 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	traductor_char_to_token(char c)
{
	if (c == '+')
		return (CT___PLUS);
	if (ft_isdigit(c) == 1)
		return (CT_NUMBER);
	return (CT__ERROR);
}

// [../TO_IGNORE_reference_image/grafo_automata.png]
t_state	get_state(t_state current_state, int token_char)
{
	const t_state	matrix[][4] = {
	{ST___ERROR, ST____PLUS, ST__NUMBER}, // 0 estado inicial
	{ST___ERROR, ST___ERROR, ST___ERROR}, // 1 estado ST___ERROR
	{ST___ERROR, ST___ERROR, ST__NUMBER}, // 2 estado ST____PLUS NO ACEPTACION
	{ST___ERROR, ST___ERROR, ST__NUMBER}, // 3 estado ST__NUMBER OK
	{0}, //0		+			nbr
	};

	return (matrix[current_state][token_char]);
}

t_state	evaluate_string(char *str)
{
	int		token_char;
	t_state	state;
	int		i;

	state = ST_INICIAL;
	i = 0;
	while (str[i])
	{
		token_char = traductor_char_to_token(str[i]);
		state = get_state(state, token_char);
		i++;
	}
	if (state != ST__NUMBER)
	{
		printf("Error, invalid input: %s\n", str);
		return (ST___ERROR);
	}
	return (state);
}

int	parser(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (evaluate_string(argv[i]) == ST___ERROR)
			return (ST___ERROR);
		i++;
	}
	return (0);
}
