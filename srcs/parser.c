#include "philo.h"

int traductor_char_to_token(char c)
{
	if (c == '+')
		return (CT___PLUS);
	if (ft_isdigit(c) == 1)
		return (CT_NUMBER);
	return (CT__ERROR);
}



//! exeple arg: 123+ | -200 | 374  caca | ++36 | 35 |
// install image_comment extension to see de image belove:
// https://marketplace.visualstudio.com/items?itemName=mgiesen.image-comments
// [../TO_IGNORE_reference_image/grafo_automata.png]
// [../TO_IGNORE_reference_image/nature.jpg]
int get_state(t_state current_state, int token_char)
{
	const t_state matrix[][4] = {
		{ST___ERROR, ST____PLUS, ST__NUMBER}, // 0 estado inicial
		{ST___ERROR, ST___ERROR, ST___ERROR}, // 1 estado ST___ERROR
		{ST___ERROR, ST___ERROR, ST__NUMBER}, // 2 estado ST____PLUS NO ACEPTACION
		{ST___ERROR, ST___ERROR, ST__NUMBER}  // 3 estado ST__NUMBER OK
	};// |   err	|	  + 	|	 n     |
	  // |    0		|	  1 	|	 2     |
	return (matrix[current_state][token_char]);
}


int evaluate_string(char *str)
{
	int token_char;
	int state;
	int i;

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
	return (0);
}

int parser(int argc, char **argv)
{
	(void)argc;
	int i;

	i = 1;
	while (argv[i])
	{
		if (evaluate_string(argv[i]) == ST___ERROR)
			return (ST___ERROR);
		i++;
	}
	return (0); 
}
