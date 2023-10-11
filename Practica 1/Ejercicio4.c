#include <stdio.h>
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
   pid_t pid_hijo; //Se declaran las variables utilizadas en el programa. pid_hijo se utilizará para almacenar el PID del proceso hijo creado con fork()
   int estado, x; //estado para almacenar el estado de finalización del proceso hijo, x para almacenar el valor devuelto por wait()
   long i, j;

   if ( (pid_hijo= fork()) == -1){ //El proceso padre llama a fork() para crear un nuevo proceso hijo. Si fork() devuelve -1, indica un error en la creación del proceso hijo, y el programa imprime un mensaje de error 
      perror("Fallo al hacer fork()");
      exit(-1);
   } else if (pid_hijo == 0) { /* Código HIJO */
      //Si fork() devuelve 0, significa que este código se está ejecutando en el proceso hijo. En el proceso hijo, se utiliza execl() para ejecutar el programa externo /bin/ls (el comando ls -l) con argumentos -l
      if ( execl("/bin/ls", "ls", "-l", NULL) < 0) {
         //Si execl() falla, imprime un mensaje de error
         perror("Fallo al ejecutar: ls");
         exit(-1);
      }
   } else  
      //Si fork() devuelve un valor diferente de 0, el código se está ejecutando en el proceso padre. El proceso padre llama a wait(&estado) para esperar a que el proceso hijo termine y recoger su estado de finalización
   
      if ( (x=wait(&estado)) != pid_hijo) {//verifica si el valor devuelto por wait() es igual al PID del proceso hijo.
         
         fprintf(stdout, "PADRE: interrumpido por señal\n"); fflush(stdout);//Si no son iguales, se imprime un mensaje de interrupción por señal.
      }
      //Si son iguales, significa que el proceso hijo ha terminado correctamente
   exit(0); /* Código PADRE e HIJO, aunque el hijo nunca pasará por aquí */
}