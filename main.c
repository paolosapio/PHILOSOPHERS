/* 

! Funciones autorizadas en Philosophers (42)

  1. memset - Rellena un bloque de memoria con un valor específico.
  2. printf - Imprime texto en la terminal.
  3. malloc - Reserva memoria dinámica en el heap.
  4. free - Libera la memoria reservada con malloc.
  5. write - Escribe datos en una salida (pantalla, archivos, etc.).
! 6. usleep - Pausa la ejecución por microsegundos.
! 7. gettimeofday - Obtiene la hora actual en microsegundos.
! 8. pthread_create - Crea un nuevo hilo.
! 9. pthread_detach - Desvincula un hilo (se elimina solo al terminar).
! 10. pthread_join - Espera a que un hilo termine.
! 11. pthread_mutex_init - Inicializa un mutex (candado).
! 12. pthread_mutex_destroy - Destruye un mutex.
! 13. pthread_mutex_lock - Bloquea un mutex (evita acceso simultáneo).
! 14. pthread_mutex_unlock - Desbloquea un mutex.

*/
// usleep : 1000000 es un segundo (1/1000000 micro segundo!)

#include <unistd.h>
#include <stdio.h>

int main(void)
{
	printf("value de usleep: %d", usleep(100000000));
  return (0);
}