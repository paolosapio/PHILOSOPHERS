#include "philo.h"

int traductor_char_to_token(char c)
{
	if (c == '+')
		return (1);
	if (philo_isdigit(c) == 1)
		return (2);
	return (0);
}



// exeple arg: 123+
// install image_comment extension to see de image belove:
// https://marketplace.visualstudio.com/items?itemName=mgiesen.image-comments
// [../TO_IGNORE_reference_image/grafo_automata.png]
int get_state(t_STATE current_state, int token_char)
{
	const t_STATE matrix[][4] = {
		{eERROR, e_PLUS, NUMBER}, // 0 estado inicial
		{eERROR, eERROR, eERROR}, // 1 estado eERROR
		{eERROR, eERROR, NUMBER}, // 2 estado e_PLUS NO ACEPTACION
		{eERROR, eERROR, NUMBER}  // 3 estado NUMBER OK
	};//   err		+ 		n
	  //    0		1 		2
	return (matrix[current_state][token_char]);
}

int evaluate_string(char *str)
{
	int token_char;
	int state;
	int i;

	state = 0;
	i = 0;
	while (str[i])
	{
		token_char = traductor_char_to_token(str[i]);
		state = get_state(state, token_char);
		i++;
	}
	if (state != 3)
	{
		printf("Error, invalid input: %s\n", str);
		return (-1);
	}
	return (0);
}

int parser(int argc, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (evaluate_string(argv[i]) != 0)
			return (-1);
		i++;
	}
	return (0); 
}
