#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
   
   
   pid_t pid;//Se declara una variable pid de tipo pid_t, que se utilizará para almacenar el resultado de la función fork().
   int i, n= 4;//i para usarla como contador en el bucle for, y n se establece en 4, lo que significa que se crearán 4 procesos hijo en el bucle.

   for (i=0; i<n; i++) //jecutará 4 veces (n está configurado en 4) y en cada iteración,
      if ( (pid = fork()) < 0 ) break;  //se intentará crear un nuevo proceso hijo utilizando fork()

   printf ("Proceso: %d / Padre: %d\n", (int) getpid(), (int) getppid()); //todos los procesos  imprimirán su propio PID (getpid()) y el PID de su proceso padre (getppid()). 
}