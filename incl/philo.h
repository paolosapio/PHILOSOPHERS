	#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>


typedef enum e_STATE {
	INICIAL,
	eERROR,
	e_PLUS,
	NUMBER,
	NUMBER_OF_STATES
} t_STATE;

typedef struct	s_data_pack	t_data_pack;
typedef struct	s_philo		t_philo;

// lista de filosofos
typedef struct s_philo
{
	int				id_philo; //! NUMERO IIDENTIFICACION DE FILOSOFOS
	long			last_meal; //comienzo de la ultima comida del filosofo
	pthread_mutex_t	fork;
	pthread_t		id_thread; //se inicializa con la funcion pthread_create
	t_data_pack		*data;
	t_philo			*next;
}					t_philo;

// structura con todos los datos
typedef struct s_data_pack
{
	long		n_philos;		//! NUMERO TOTAL DE FILOSOFOS
	long		time_to_die;	//! TIEMPO DE VIDA
	long		time_to_eat;	//! TIEMPO PARA COMER
	long		time_to_sleep;	//! TIEMPO PARA DORMIR
	long		n_must_eat;		//! (OPCIONAL) NUMERO DE PLATOS MINIMO QUE TIENE QUE COMER CADA FILOSOFO
	t_philo 	*list_of_philosophers;
}				t_data_pack;

//parser.c
int		traductor_char_to_token(char c);
int		get_state(t_STATE current_state, int token_char);
int		evaluate_string(char *str);
int		parser(int argc, char **argv);

//utils.c
long	ft_atol(const char *nptr);
void	*ft_calloc(size_t count, size_t size);
int		philo_isdigit(int c);
long	ft_atol(const char *nptr);


//init.c
t_data_pack	*init_data(int argc, char **argv);
t_philo		*init_list_philo(t_data_pack *data);

//list_philo.c
void ft_lstadd_back(t_philo **lst, t_philo *new);
t_philo *ft_lstnew(int id);

#endif