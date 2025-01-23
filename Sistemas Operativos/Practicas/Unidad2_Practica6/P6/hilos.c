#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void* thread3(void* arg) {
    printf("\t\tPráctica 6 Hilo Terminal\n");
    pthread_exit(NULL);
}
void* thread2(void* arg) {
    pthread_t Threads3[10];
    printf("\tHilo de nivel 2 ID: %ld\n", pthread_self());
    for (int i = 0; i < 10; i++) {
        pthread_create(&Threads3[i], NULL, thread3, NULL);
    }
    for (int i = 0; i < 10; i++) {
        pthread_join(Threads3[i], NULL);
    }

    pthread_exit(NULL);
}
void* thread1(void* arg) {
    pthread_t Threads3[15];
    printf("Hilo de nivel 1 ID: %ld\n", pthread_self());
    for (int i = 0; i < 15; i++) {
        pthread_create(&Threads3[i], NULL, thread2, NULL);
    }
    for (int i = 0; i < 15; i++) {
        pthread_join(Threads3[i], NULL);
    }
    pthread_exit(NULL);  
}
int main() {
    pid_t pid = fork();
    if (pid == 0) {
        pthread_t Threads2[20];
        for (int i = 0; i < 20; i++) {
            pthread_create(&Threads2[i], NULL, thread1, NULL);
        }
        for (int i = 0; i < 20; i++) {
            pthread_join(Threads2[i], NULL);
        }
    } else {
        wait(0); 
    }
    return 0;
}

