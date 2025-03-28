#include "philo.h"
/*

EJECUCION DFEL HILO:
hilo 1-> bloque porta, come un tiempo, apre puerta, duerme un tiempo, piensa (scrive mensaje), bloque porta, come...

pensar tiene que escribir esto:
abortCualquier cambio de estado de un filósofo debe tener el siguiente formato:

◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died

Reemplaza timestamp_in_ms con la marca de tiempo actual en milisegundos
y X con el numero del filósofo.
• El estado impreso no debe estar roto o alterado por el estado de otros filósofos
• No puedes tener más de 10ms entre la muerte de un filósofo y el momento en el que
imprimes su muerte.
• Te recuerdo, los filósofos deben evitar morir.

*/

long	time_diff(long timestamp_in_ms)
{
	return (time_ms() - timestamp_in_ms);
}
void	comer(t_philo	*philo)
{	
	pthread_mutex_lock(philo->fork_left);
	printf("[%5ld] [%3d] has taken a fork L\n", time_diff(philo->data->timestamp_in_ms), philo->id_philo);
	
	if (philo->fork_right == philo->fork_left)
		return ;
	pthread_mutex_lock(philo->fork_right);
	printf("[%5ld] [%3d] has taken a fork R\n", time_diff(philo->data->timestamp_in_ms), philo->id_philo);
	
	philo->last_meal_start =  time_ms();
	printf("[%5ld] [%3d] is eating\n", time_diff(philo->data->timestamp_in_ms), philo->id_philo);
	
	wait_ms(philo->data->time_to_eat);

	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);

}
//! EJEMPLO ARGS:
//! ./philo | 7                      | 1000        | 500         | 52            | 3
//! ./philo | number_of_philosophers | time_to_die | time_to_eat | time_to_sleep | [number_of_times_each_philosopher_must_eat]

void	dormir(t_philo	*philo)
{
	// ◦ timestamp_in_ms X is sleeping
	printf("[%5ld] [%3d] is sleeping\n", time_diff(philo->data->timestamp_in_ms), philo->id_philo);
	wait_ms(philo->data->time_to_sleep);
}

void	pensar(t_philo	*philo)
{
	printf("[%5ld] [%3d] is thinking\n", time_diff(philo->data->timestamp_in_ms), philo->id_philo);
	// ◦ timestamp_in_ms X is thinking
}

// ◦ timestamp_in_ms X died


void *philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;

	comer(philo);
	dormir(philo);
	// pensar(philo);
	return  (NULL);
}
// usleep(10000 * philo->id_philo);
// printf("Philo nº%d sitting\n", philo->id_philo);

void	init_philos(t_data_pack *d_pack)
{
	long	i;

	i = 0;
	while (i < d_pack->n_philos)
	{
		pthread_create(&d_pack->array_of_philosophers[i].id_thread, NULL, philo_life, &d_pack->array_of_philosophers[i]);
		i++;
	}
	i = 0;
	while (i < d_pack->n_philos)
	{
		pthread_join(d_pack->array_of_philosophers[i].id_thread, NULL);
		i++;
	}

}
	