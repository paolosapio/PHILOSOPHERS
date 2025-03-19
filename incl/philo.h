#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>

// lista de filosofos
typedef struct s_philo
{
	int			philo_nr_id;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
	t_thread	thread;
	t_philo		next;
}				t_philo;

// structura con todos los datos
typedef struct s_thread
{
	t_philo *list_of_philosophers;
}				t_thread;

int		parser(int argc, char **argv);
#endif