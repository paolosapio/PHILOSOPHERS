	#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>

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
// EJEMPLO ARGS
// ./philo 7 1000 500 52 3
typedef struct s_data_pack
{
	long		n_philos; //! NUMERO TOTAL DE FILOSOFOS
	long		time_to_die; //! TIEMPO DE VIDA
	long		time_to_eat; //! TIEMPO PARA COMER
	long		time_to_sleep; //! TIEMPO PARA DORMIR
	long		n_must_eat; //! (OPCIONAL) NUMERO DE PLATOS MINIMO QUE TIENE QUE COMER CADA FILOSOFO
	t_philo 	*list_of_philosophers;
}				t_data_pack;

int		parser(int argc, char **argv);

//utils.c

long	ft_atol(const char *nptr);
void	*ft_calloc(size_t count, size_t size);


//init.c
t_data_pack *init_data(int argc, char **argv);

//list_philo.c
//t_philo *ft_lstnew(void);
void	init_list_philo(t_philo *firt_node, t_data_pack *data)
//ft_lstadd_back();

#endif