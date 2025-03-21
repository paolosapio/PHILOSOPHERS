#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>

/* 
Explicación de los parámetros:

    pthread_t *thread → Puntero donde se almacenará el identificador del nuevo hilo.
    const pthread_attr_t *attr → Atributos del hilo (puede ser NULL si usas los valores por defecto).
    void *(*start_routine) (void *) → Función que ejecutará el hilo. Debe aceptar un void* como argumento y devolver un void*.
    void *arg → Argumento que se pasa a la función start_routine cuando el hilo comienza a ejecutarse.
 */
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);


int pthread_join(pthread_t thread, void **retval);

void	*start_routine(void *pointer)
{
	printf("caca\n");
	printf("%p\n", (int*)pointer);
	// for (int i = 0; i < 4; i++)
	// {
	// 	sleep(1);
	// }
	while (1)
	{
		/* code */
	}
	return ("HOLA");
}

int main(void)
{
	char *hola = "hola";
	int a = 10;
	pthread_t thread[5];	//se inicializa con ID del hilo


	char *frase;

	int i = 0;

	while (i < 55)
	{
		int ret_create = pthread_create(&thread[i], NULL, start_routine, &a);
		printf("RET_CREATE: %d\n", ret_create);
		i++;
	}

	// while (1); // essperamos que eel hilo enttre en la fncion
	// int ret_join = pthread_join(thread, (void **)&frase);

	// printf("frase: %s\n", frase);
	// printf("RET_JOIN: %d\n", ret_join);
	printf("maiiin\n");
	while (1)
	{
		/* code */
	}
	
	return (0);
}