#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void){
    int id_proc;
    id_proc = fork();
    if(id_proc == 0){
        printf("Soy el proceso main, PID: %d\n", getppid());
        printf("Soy el primer hijo, PID: %d, PID del padre: %d\n", getpid(), getppid());
        id_proc  = fork();
        if(id_proc == 0){
            printf("\tSoy el primer nieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
            for(int a = 0; a < 5; a++){
                id_proc = fork();
                if(id_proc == 0){
                    if(a == 0){
                        printf("\t\tSoy el primer bisnieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                        for(int b = 0; b < 4; b++){
                            id_proc = fork();
                            if(id_proc == 0){
                                if(b == 0){
                                    printf("\t\t\tSoy el primer tataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                }
                                if(b == 1){
                                    printf("\t\t\tSoy el segundo tataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                }
                                if(b == 2){
                                    printf("\t\t\tSoy el tercer tataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                }
                                if(b == 3){
                                    printf("\t\t\tSoy el cuarto tataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                }
                                exit(0);
                            } else {
                                wait(NULL);
                            }
                        }
                        exit(0);
                    }
                    if(a == 1){
                        printf("\t\tSoy el segundo bisnieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                        for(int c = 0; c < 2; c++){
                            id_proc = fork();
                            if(id_proc == 0){
                                if(c == 0){
                                    printf("\t\t\tSoy el quinto tataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                    id_proc = fork();
                                    if(id_proc == 0){
                                        printf("\t\t\t\tSoy el primer tataratataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                        id_proc = fork();
                                        if(id_proc == 0){
                                            printf("\t\t\t\t\tSoy el primer tataratataratataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                            exit(0);
                                        }
                                        wait(NULL);
                                        exit(0);
                                    }
                                    wait(NULL);
                                    exit(0);
                                }
                                if(c == 1){
                                    printf("\t\t\tSoy el sexto tataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                    id_proc = fork();
                                    if(id_proc == 0){
                                        printf("\t\t\t\tSoy el segundo tataratataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                        id_proc = fork();
                                        if(id_proc == 0){
                                            printf("\t\t\t\t\tSoy el segundo tataratataratataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                            id_proc = fork();
                                            if(id_proc == 0){
                                                printf("\t\t\t\t\t\tSoy el primer tataratataratataratataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                                exit(0);
                                            }
                                            wait(NULL);
                                            exit(0);
                                        }
                                        wait(NULL);
                                        exit(0);
                                    }
                                    wait(NULL);
                                    exit(0);
                                }
                            } else {
                                wait(NULL);
                            }
                        }
                        exit(0);
                    }
                    if(a == 2){
                        printf("\t\tSoy el tercer bisnieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                        for(int d = 0; d < 3; d++){
                            id_proc = fork();
                            if(id_proc == 0){
                                if(d == 0){
                                    printf("\t\t\tSoy el septimo tataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                }
                                if(d == 1){
                                    printf("\t\t\tSoy el octavo tataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                }
                                if(d == 2){
                                    printf("\t\t\tSoy el noveno tataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                }
                                exit(0);
                            } else {
                                wait(NULL);
                            }
                        }
                        exit(0);
                    }
                    if(a == 3){
                        printf("\t\tSoy el cuarto bisnieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                        for(int e = 0; e < 2; e++){
                            id_proc = fork();
                            if(id_proc == 0){
                                if(e == 0){
                                    printf("\t\t\tSoy el decimo tataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                    id_proc = fork();
                                    if(id_proc == 0){
                                        printf("\t\t\t\tSoy el tercer tataratataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                        id_proc = fork();
                                        if(id_proc == 0){
                                            printf("\t\t\t\t\tSoy el tercer tataratataratataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                            id_proc = fork();
                                            if(id_proc == 0){
                                                printf("\t\t\t\t\t\tSoy el segundo tataratataratataratataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                                exit(0);
                                            }
                                            wait(NULL);
                                            exit(0);
                                        }
                                        wait(NULL);
                                        exit(0);
                                    }
                                    wait(NULL);
                                    exit(0);
                                }
                                if(e == 1){
                                    printf("\t\t\tSoy el onceavo tataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                    id_proc = fork();
                                    if(id_proc == 0){
                                        printf("\t\t\t\tSoy el cuarto tataratataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                        id_proc = fork();
                                        if(id_proc == 0){
                                            printf("\t\t\t\t\tSoy el cuarto tataratataratataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                            exit(0);
                                        }
                                        wait(NULL);
                                        exit(0);
                                    }
                                    wait(NULL);
                                    exit(0);
                                }
                            } else {
                                wait(NULL);
                            }
                        }
                        exit(0);
                    }
                    if(a == 4){
                        printf("\t\tSoy el quinto bisnieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                        for(int f = 0; f < 4; f++){
                            id_proc = fork();
                            if(id_proc == 0){
                                if(f == 0){
                                    printf("\t\t\tSoy el doceavo tataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                }
                                if(f == 1){
                                    printf("\t\t\tSoy el treceavo tataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                }
                                if(f == 2){
                                    printf("\t\t\tSoy el catorceavo tataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                }
                                if(f == 3){
                                    printf("\t\t\tSoy el quinceavo tataranieto, PID: %d, PID del padre: %d\n", getpid(), getppid());
                                }
                                exit(0);
                            } else {
                                wait(NULL);
                            }
                        }
                        exit(0);
                    }
                    exit(0);
                }
                wait(NULL);
            }
            exit(0);
        }
        wait(NULL);
        exit(0);
    }
    wait(NULL);
    return 0;
}

