#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <pthread.h>

typedef struct	s_data_pack	t_data_pack;
typedef struct	s_philo		t_philo;

// lista de filosofos
typedef struct s_philo
{
	int				id_philo; 		 //! NUMERO IIDENTIFICACION DE FILOSOFOS
	long			last_meal_start; //comienzo de la ultima comida del filosofo o empiezo del programa
	pthread_t		id_thread;		 //se inicializa con la funcion pthread_create
	t_config		*config;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
}					t_philo;

typedef struct s_config
{
	long			time_to_die;	//! TIEMPO DE VIDA
	long			time_to_eat;	//! TIEMPO PARA COMER
	long			time_to_sleep;	//! TIEMPO PARA DORMIR
	long			n_must_eat;		//! (OPCIONAL) NUMERO DE PLATOS MINIMO QUE TIENE QUE COMER CADA FILOSOFO
}				t_config;

// structura con todos los datos
typedef struct s_data_pack
{
	long			timestamp_in_ms;//! TIEMPO DE EMPIEZO DEL PROGRAMA
	long			n_philos;		//! NUMERO TOTAL DE FILOSOFOS
	t_config		*config;
	pthread_mutex_t	*forks;
	t_philo 		*array_of_philosophers;
}				t_data_pack;

//time.c
long    time_ms(void);
void    wait_ms(long time_wait);
#endif


/* 
[porque es el philo 0]
su estructura será inicializada correctamente, se inicializa un puntero al tenedor
izquierdo que en el array de forks será el 0

[porque ya no es el 0]
iniciará su estructura y el tenedor izquierdo, además, copiará ese puntero al philo_actual - 1, que el derecho es ese mismo. 
En el array de forks sera el id de philo.

[porque es el último]
iniciará su estructura y el tenedor izquierdo, además, copiará ese puntero al philo_actual - 1, que el derecho es ese mismo.
y mi derecho es el izquierdo del 0
En el array de forks sera el id de philo.


comienza la función que creará cada hilo y le dará como parámetro la estructura philo.

fin */