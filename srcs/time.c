#include "philo.h"

void    wait_ms(long time_wait)
{
    const long  time_now = time_ms();
	const long  time_end = time_now + time_wait;
	while (1)
	{
		if (time_ms() >= time_end)
			break;
	}
}

long    time_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((long)((tv.tv_sec * 1000) + (tv.tv_usec / 1000)));
}
//  printf("%lu,%lu\n", tv.tv_sec, tv.tv_usec);   IMPRIME TIEMPO DESDE 1970 (EPOC)

//        1.000 milisegundos  son 1 segundo
//    1.000.000 microsegundos son 1 segundo
//1.000.000.000 nanosegundos  son 1 segundo  

//! ejecutando:
//! time ./philo 1 2 2 2 > /dev/null 
//  time       : cuenta el tiempo de ejecuncion del programa
//  > /dev/null: redireciona a una salida nula
