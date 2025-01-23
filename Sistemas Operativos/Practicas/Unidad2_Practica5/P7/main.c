#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid_hijo = fork();
    char *argv[4];
    if (pid_hijo < 0) {
        perror("Error al crear el proceso hijo");
        exit(EXIT_FAILURE);
    }
    if (pid_hijo == 0) { 
        printf("Soy el Hijo\n");
        for (int i = 0; i < 3; i++) {
            pid_t pid_nieto = fork();
            if (pid_nieto < 0) {
                perror("Error al crear el proceso nieto");
                exit(EXIT_FAILURE);
            }
            printf("Soy el nieto %d\n",i+1);
            if (pid_nieto == 0) { 
                switch (i) {
                    case 0: 
                         printf("\tSoy el primer proceso nieto\n");
                         argv[0] = "./exp";
                         argv[1] = "20+15*3-5";
                         argv[2] = NULL;
                        execv(argv[0], argv); 
                        break;
                    case 1: 
                        printf("\tSoy el segundo proceso nieto\n");
                        argv[0] = "./per";
                        argv[1] = "permisos.txt";
                        argv[2] = "777";
                        argv[3] = NULL;
                        execv(argv[0], argv);
                        break;
                    case 2:
                        printf("\tSoy el tercer proceso nieto\n"); 
                        argv[0] = "./inv";
                        argv[1] = NULL;
                        execv(argv[0], argv);
                        break;
                }
                perror("Error al ejecutar el programa");
                exit(EXIT_FAILURE);
            }
        }
        for (int i = 0; i < 3; i++) {
            wait(NULL);
        }
        exit(EXIT_SUCCESS);
    }
    wait(NULL); 
    printf("\nEl proceso padre ha terminado.\n");
    return 0;
}
