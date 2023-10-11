#include <stdio.h>
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(void) {
   pid_t pid_hijo; //pid_hijo se utilizará para almacenar el PID del proceso hijo creado con fork()
   int estado, x; //estado para almacenar el estado de finalización del proceso hijo, x para almacenar el valor devuelto por wait()
   long i, j;//i y j como variables de tipo long que no se utilizan en el código proporcionado.

   if ( (pid_hijo= fork()) == -1){ /* Código PADRE: Error */
      perror("Fallo al hacer fork()");  // SE crea un nuevo proceso hijo. Si fork() devuelve -1, indica un error
      exit(-1);
   } else if (pid_hijo == 0) { /* Código HIJO */ //Si fork() devuelve 0, significa que este código se está ejecutando en el proceso hijo. 
      fprintf(stdout, "PID hijo: %ld\n", (long) getpid()); fflush(stdout); sleep(2); //El proceso hijo imprime su propio PID utilizando getpid()
   } else { /* Código PADRE */
      //Si fork() devuelve un valor diferente de 0, significa que este código se está ejecutando en el proceso padre. El proceso padre llama a wait(&estado) para esperar a que el proceso hijo termine y recoger su estado de finalización. Luego, verifica si el valor devuelto por wait() es igual al PID del proceso hijo. Si son iguales, significa que el proceso hijo ha terminado correctamente, 
      if ( (x=wait(&estado)) != pid_hijo)
         fprintf(stdout, "PADRE: interrumpido por señal\n"); //Si no son iguales, se imprime un mensaje de interrupción por señal.
      
      else
         
         //Si son iguales,se imprime información sobre el proceso padre, el proceso hijo y su estado de finalización
      
         fprintf(stdout, "PID padre: %ld / PID hijo: %ld / estado hijo: %d\n",(long) getpid(), (long) pid_hijo, estado);
      fflush(stdout);
   }
   exit(0); /* Código PADRE e HIJO */
}