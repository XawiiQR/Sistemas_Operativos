#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
    int i;
    int fd1, fd2;
    const char string1[10] = "*********";
    const char string2[10] = "---------";
    pid_t rf;

    fd1 = creat("ficheroA", 0666);
    fd2 = creat("ficheroB", 0666);
    rf = fork();

    switch (rf) {
        case -1:
            printf("\nNo he podido crear el proceso hijo");
            break;
        case 0:
            // Este código se ejecuta en el proceso hijo
            for (i = 0; i < 10; i++) {
                sleep(1); // Pausa de 1 segundo
                write(fd1, string2, sizeof(string2));
                write(fd2, string2, sizeof(string2));
            }
            break;
        default:
            // Este código se ejecuta en el proceso padre
            for (i = 0; i < 10; i++) {
                write(fd1, string1, sizeof(string1));
                write(fd2, string1, sizeof(string1));
            }
    };

    printf("\nFinal de ejecución de %d\n", getpid());
    exit(0);
}
