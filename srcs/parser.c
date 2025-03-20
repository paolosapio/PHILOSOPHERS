#include "philo.h"


int traductor_char_to_token(char c)
{
	if (c == '+')
		return (1); // +
	if (philo_isdigit(c) == 1)
		return (2); // digit
	return (0); //err
}
// exeple arg: 123+
typedef enum e_STATE {
	INICIAL,
	eERROR,
	e_PLUS,
	NUMBER,
	NUMBER_OF_STATES
} t_STATE;

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

char *read_state(t_STATE s) {
	const char *names [NUMBER_OF_STATES] = {
		"INICIAL",
		"eRROR"
	};
	return (names[s]);
}

// install image_comment extension to see de image belove:
// https://marketplace.visualstudio.com/items?itemName=mgiesen.image-comments
// [../TO_IGNORE_reference_image/grafo_automata.png]
// [../TO_IGNORE_reference_image/nature.jpg]

// exeple arg: 123+
/* int get_state(int current_state, int token_char)
{
	const int matrix[][4] = {
		{1, 2, 3}, // 0 estado inicial
		{1, 1, 1}, // 1 estado err
		{1, 1, 3}, // 2 estado + NO ACEPTACION
		{1, 1, 3}  // 3 estado n OK
	};//err + n
	  // 0  1 2
	return (matrix[current_state][token_char]);
}
 */
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
		printf("Error, invalid input: %s\n", str);
	return (0);
}

int parser(int argc, char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		evaluate_string(argv[i]);
		i++;
	}
	return (0); 
}

/* 
int	get_state(int current_state, int token_char)
{
	const int matrix[][4] = {
		{1, 2, 3}, //- 0 - estado inicial
		{1, 1, 1}, //- 1 - estado error
		{1, 1, 3}, //- 2 - estado +
		{1, 1, 3}, //- 3 - estado n
	};//err +  n
      // 0  1  2
	return (matrix[current_state][token_char]);

} */