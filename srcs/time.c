#include "philo.h"

long	time_diff(long timestamp_in_ms)
{
	return (time_ms() - timestamp_in_ms);
}

long    time_ms(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((long)((tv.tv_sec * 1000) + (tv.tv_usec / 1000)));
}
//! EJEMPLO ARGS:
//! ./philo | 7                      | 100         | 500         | 52            | 3
//! ./philo | number_of_philosophers | time_to_die | time_to_eat | time_to_sleep | [number_of_times_each_philosopher_must_eat]
//!		

// philo->last_meal_start difftime(), philo->data->time_to_die
//  true muerto - false vivo
bool	is_philo_live(t_philo	*philo)
{
	if (time_diff(philo->last_meal_start) > philo->data->time_to_die)
		return (DEAD);
	return (LIVE);
}

bool    wait_ms_and_check_life(long time_wait, t_philo	*philo)
{
    const long  time_now = time_ms();
	const long  time_end = time_now + time_wait;
	while (1)
	{
		if (is_philo_live(philo) == DEAD)
			return (DEAD);
		if (time_ms() >= time_end)
			break ;
	}
	return (LIVE);
}

//  printf("%lu,%lu\n", tv.tv_sec, tv.tv_usec);   IMPRIME TIEMPO DESDE 1970 (EPOC)

//        1.000 milisegundos  son 1 segundo
//    1.000.000 microsegundos son 1 segundo
//1.000.000.000 nanosegundos  son 1 segundo

//! ejecutando:
//! time ./philo 1 2 2 2 > /dev/null 
//  time       : cuenta el tiempo de ejecuncion del programa
//  > /dev/null: redireciona a una salida nula
