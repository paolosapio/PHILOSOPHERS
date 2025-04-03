/* 

! Funciones autorizadas en Philosophers (42)

  1.  memset	- 	Rellena un bloque de memoria con un valor específico.
  2.  printf	- Imprime texto en la terminal.
  3.  malloc	- Reserva memoria dinámica en el heap.
  4.  free	- Libera la memoria reservada con malloc.
  5.  write	- Escribe datos en una salida (pantalla, archivos, etc.).
  6.  usleep	- Pausa la ejecución por microsegundos.
! 7.  gettimeofday	- Obtiene la hora actual en microsegundos.
! 8.  pthread_create	- Crea un nuevo hilo.
! 9.  pthread_detach	- Desvincula un hilo (se elimina solo al terminar).
! 10. pthread_join	- Espera a que un hilo termine.
! 11. pthread_mutex_init	- Inicializa un mutex (candado).
! 12. pthread_mutex_destroy	- Destruye un mutex.
! 13. pthread_mutex_lock	- Bloquea un mutex (evita acceso simultáneo).
! 14. pthread_mutex_unlock	- Desbloquea un mutex.

*/
// usleep : 1000000 es un segundo (1/1000000 micro segundo!)

/*
para el proyecto:

en Philosophers necesitas un main que haga varias cosas:

		Parsear los argumentos (número de filósofos, tiempo para morir, comer, dormir, etc.).
		Inicializar las estructuras necesarias (filósofos, mutex para los tenedores, etc.).
		Crear los hilos de los filósofos.
		Supervisar la ejecución y verificar si algún filósofo muere.
		Liberar memoria al final.

*/

/*
#include <sys/time.h>
int gettimeofday(struct timeval *tv, struct timezone *tz);

timezone tz no sirve asi que se le pasa NULL
timeval tv: time value (se inicializa esta variable tipo structura que contine info en segundos o micro segundos)



! Tu(s) programa debe aceptar los siguientes argumentos:
number_of_philosophers
time_to_die time_to_eat
time_to_sleep
[number_of_times_each_philosopher_must_eat]

◦ number_of_philosophers: es el número de filósofos, pero también el número de tenedores.
◦ time_to_die (en milisegundos): si un filósofo no empieza a comer en time_to_die milisegundos desde el comienzo de su ultima comida o desde el principio de la simulación, este morirá.
◦ time_to_eat (en milisegundos): es el tiempo que tiene un filósofo para comer. Durante ese tiempo, tendrá los tenedores ocupados.
◦ time_to_sleep (en milisegundos): es el tiempo que tiene un filósofo para dormir.
◦ number_of_times_each_philosopher_must_eat (argumento opcional): si todos los filósofos comen al menos number_of_times_each_philosopher_must_eat veces, la simulación se detendrá. Si no se especifica, la simulación se detendrá con la muerte de un filósofo.

pthread_create -> CREA HILO:
NECESITO pasarle:

    Un identificador de tipo pthread_t donde se guardará el ID del hilo.
    Atributos del hilo (generalmente NULL si no los necesitas).
    La función que ejecutará el hilo (el código que quieres que corra en ese hilo).
    Los argumentos que le quieras pasar a esa función.
*/