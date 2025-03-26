#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <pthread.h>

typedef struct	s_data_pack	t_data_pack;
typedef struct	s_philo		t_philo;

// lista de filosofos
typedef struct s_philo
{
	int				id_philo; //! NUMERO IIDENTIFICACION DE FILOSOFOS
	long			last_meal; //comienzo de la ultima comida del filosofo
	pthread_t		id_thread; //se inicializa con la funcion pthread_create
	t_data_pack		*data;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
}					t_philo;

// structura con todos los datos
typedef struct s_data_pack
{
	long			n_philos;		//! NUMERO TOTAL DE FILOSOFOS
	long			time_to_die;	//! TIEMPO DE VIDA
	long			time_to_eat;	//! TIEMPO PARA COMER
	long			time_to_sleep;	//! TIEMPO PARA DORMIR
	long			n_must_eat;		//! (OPCIONAL) NUMERO DE PLATOS MINIMO QUE TIENE QUE COMER CADA FILOSOFO
	pthread_mutex_t	*forks;
	t_philo 		*array_of_philosophers;
}				t_data_pack;

#endif