#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(void) {
   pid_t pid; //pid de tipo pid_t, que se utilizará para almacenar el resultado de la función fork().
   int var= 0;
   printf("PID antes de fork(): %d\n", (int) getpid()); //imprime el PID del proceso padre antes de que se llame a fork(). 
   if ( (pid = fork()) > 0 ) { //se llama a fork(). Esta función crea un nuevo proceso hijo y devuelve el PID del proceso hijo en el proceso padre y 0 en el proceso hijo.
      printf ("PID del padre: %d\n", (int) getpid()); //Si el valor devuelto por fork() es mayor que 0, esto significa que el código se ejecuta en el proceso padre, imprime el PID del proceso padre.
      var++; //aumenta el valor de la variable var en 1.
   } else {
      //Si el valor devuelto por fork() es igual a 0, esto significa que el código se ejecuta en el proceso hijo. En este caso, imprime el PID del proceso hijo. Si el valor devuelto por fork() es negativo, indica un error en la llamada a fork(), y se imprime un mensaje de error.
      if (pid == 0) 
         printf ("PID del hijo: %d\n", (int) getpid());
      else
         printf ("Error al hacer fork()\n");
   }
   //en ambos procesos (padre e hijo), se imprime el valor de la variable var.
   printf("Proceso [%d] -> var = %d\n", (int) getpid(), var);
}
