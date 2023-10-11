#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int j;
    pid_t rf; // Declaración de una variable para almacenar el resultado de fork()

    rf = fork(); // Crear un proceso hijo duplicando el proceso actual

    switch (rf) // Se utiliza una estructura switch para manejar el resultado de fork().    
    {
        case -1: //Si fork() devuelve -1, significa que hubo un error al crear el proceso hijo, y se muestra un mensaje de error.
            
            printf("\nNo he podido crear el proceso hijo");
            break;
        case 0:
            // fork() devuelva 0, significa que el código se está ejecutando en el proceso hijo. Se inicializa la variable i en 0 y se muestra información que identifica al proceso hijo, incluyendo su PID y el valor inicial de i.
            i = 0;
            printf("\nSoy el hijo, mi PID es %d y mi variable i (inicialmente a %d) es par", getpid(), i);
            for (j = 0; j < 5; j++) {  // fork() devuelva 0, significa que el código se está ejecutando en el proceso hijo. Se inicializa la variable i en 0 y se muestra información que identifica al proceso hijo, incluyendo su PID y el valor inicial de i.
                i++;
                i++;
                printf("\nSoy el hijo, mi variable i es %d", i);
            };
            break;
        default:
            // Este código se ejecuta en el proceso padre
            i = 1;
            printf("\nSoy el padre, mi PID es %d y mi variable i (inicialmente a %d) es impar", getpid(), i);
            for (j = 0; j < 5; j++) {
                i++;
                i++;
                printf("\nSoy el padre, mi variable i es %d", i);
            };
    };

    printf("\nFinal de ejecucion de %d \n", getpid());
    exit(0);
}
