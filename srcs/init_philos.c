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

#define FORK_LEFT	"𐂐 has taken a fork L"
#define FORK_RIGHT	"𐂐 has taken a fork R"
#define EATING		"🍝 is eating"
#define SLEEPING	"💤 is sleeping"
#define THINKING	"💡 is thinking"

void print_state(char *str, t_philo *philo)
{
	// if (philo->data->is_dead == true)
	// 	return ;	
	printf("[%5ld] [%3d]  %s\n", time_diff(philo->data->timestamp_in_ms), philo->id_philo, str);
}

bool	philo_eat(t_philo	*philo)
{
	if (philo->id_philo % 2 != 0) // si queda resta es IMPARES
		pthread_mutex_lock(philo->fork_left);
	else
		pthread_mutex_lock(philo->fork_right);
	if (philo->id_philo % 2 != 0) // si queda resta es IMPARES
		print_state(FORK_LEFT, philo);
	else
		print_state(FORK_RIGHT, philo);
	if (philo->id_philo % 2 != 0)
		pthread_mutex_lock(philo->fork_right);
	else
		pthread_mutex_lock(philo->fork_left);
	if (philo->id_philo % 2 != 0) // si queda resta es IMPARES
		print_state(FORK_RIGHT, philo);
	else
		print_state(FORK_LEFT, philo);
	printf("\nTIEMPO DESDE LA ULTIMA COMIDA:%lu\n\n", time_ms()- philo->last_meal_start);

	philo->last_meal_start =  time_ms();
	print_state(EATING, philo);
	
	if(wait_ms_and_check_life(philo->data->time_to_eat, philo) == DEAD)
	{
		print_state("💀 is DEAD EATING", philo);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		return (DEAD);
	}
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	return (LIVE);
}

//! EJEMPLO ARGS:
//! ./philo | 4                      | 100         | 200         | 100           | 0
//! ./philo | number_of_philosophers | time_to_die | time_to_eat | time_to_sleep | [number_of_times_each_philosopher_must_eat]
//!								     ( time_de_vida)
bool	philo_sleep(t_philo	*philo)
{	
	 // ◦ timestamp_in_ms X is sleeping
	print_state(SLEEPING, philo);
	if (wait_ms_and_check_life(philo->data->time_to_sleep, philo) == DEAD)
	{
		print_state("💀 is DEAD SLEEPING", philo);
		return (DEAD);
	}
	return (LIVE);
}

bool	philo_think(t_philo	*philo)
{
	print_state(THINKING, philo);
	// ◦ timestamp_in_ms X is thinking
	return (LIVE);
}

// ◦ timestamp_in_ms X died


void *philo_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;
	philo->last_meal_start = time_ms();
	while(1)
	{
		if (philo->data->is_dead == true)
			return (NULL);
		if (philo_eat(philo) == DEAD)
		{
			return ((void *)DEAD);
		}
		if (philo->data->is_dead == true)
			return (NULL);
		if (philo_sleep(philo) == DEAD)
		{
			return ((void *)DEAD);
		}
		if (philo->data->is_dead == true)
			return (NULL);
		if (philo_think(philo) == DEAD)
		{
			return ((void *)DEAD);
		}
	}
	return (NULL);
}
// usleep(10000 * philo->id_philo);
// printf("Philo nº%d sitting\n", philo->id_philo);

void *philo_monitoring(void *arg)
{
	t_philo	*philo;

	philo = (t_philo*)arg;
	while (1)
	{
		if (is_philo_live(philo) == DEAD)
		{
			if (philo->data->is_dead == true)
				printf("[%5ld] [%3d] 💀💻 is DEAD IN MONITORING\n", time_diff(philo->data->timestamp_in_ms), philo->id_philo);
			return (DEAD);
		}

		usleep(1000);
	}
}

void	init_philos(t_data_pack *d_pack)
{
	long	i;

	i = 0;
	while (i < d_pack->n_philos)
	{
		pthread_create(&d_pack->array_of_philosophers[i].id_thread, NULL, philo_life, &d_pack->array_of_philosophers[i]);
		pthread_create(&d_pack->array_of_philosophers[i].id_thread_monitoring, NULL, philo_monitoring, &d_pack->array_of_philosophers[i]);
		i++;
	}
	i = 0;
	while (i < d_pack->n_philos)
	{
		pthread_join(d_pack->array_of_philosophers[i].id_thread, NULL);
		pthread_join(d_pack->array_of_philosophers[i].id_thread_monitoring, NULL);
		i++;
	}

}
	