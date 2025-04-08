/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:45:39 by psapio            #+#    #+#             */
/*   Updated: 2025/04/03 16:24:45 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <string.h>

# define LIVE true
# define DEAD false

//! ////////////////////////ENUM////////////////////////

typedef enum e_char_token
{
	CT__ERROR,
	CT___PLUS,
	CT_NUMBER
}	t_char_token;

typedef enum e_philo_info
{
	INFO_PH_N_FILOS = 1,
	INFO_PH_TIME_LIFE,
	INFO_PH_TIME_EAT,
	INFO_PH_TIME_SLEEP,
	INFO_PH_N_PLATES
}	t_philo_info;

typedef enum e_state
{
	ST_INICIAL,
	ST___ERROR,
	ST____PLUS,
	ST__NUMBER,
	ST_NUMBER_OF_STATES
}	t_state;

//! ////////////////////////STRUCTURES//////////////////////////

typedef struct s_data_pack	t_data_pack;
typedef struct s_philo		t_philo;

// lista de filosofos
typedef struct s_philo
{
	int				id;
	long			last_meal_start;
	pthread_t		id_thread;
	t_data_pack		*data;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	int				times_eat;
}	t_philo;

// structura con todos los datos
typedef struct s_data_pack
{
	bool			is_dead;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			n_must_eat;
	long			time_in_ms;
	long			n_philos;
	pthread_t		id_thread_times_eat;
	pthread_t		id_thread_monitoring;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_dead;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	mutex_time;
	pthread_mutex_t	mutex_print;
	t_philo			*philos;
}	t_data_pack;

//! ////////////////////////FUNCIONES////////////////////////

//parser.c
int			traductor_char_to_token(char c);
int			get_state(t_state current_state, int token_char);
int			evaluate_string(char *str);
int			parser(int argc, char **argv);

//utils.c
long		ft_atol(const char *nptr);
void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);
long		ft_atol(const char *nptr);

//init.c
bool		init_data(t_data_pack *d_pack, char **argv);
int			init_array_forks(t_data_pack *d_pack);
int			init_array_philo(t_data_pack *d_pack);

//list_philo.c
void		ft_lstadd_back(t_philo **lst, t_philo *new);
t_philo		*ft_lstnew(int id);

//destroy_data.c
void		destroy_data(t_data_pack *d_pack);

//init_philos.c
void		*print_philo_n(void	*arg);
void		init_philos(t_data_pack *d_pack);
void		print_state(char *str, t_philo *philo);

//time.c
long		time_ms(void);
bool		wait_ms_and_check_life(long time_wait, t_philo	*philo);
bool		is_philo_live(t_philo	*philo);
long		time_diff(long time_in_ms);

#endif
