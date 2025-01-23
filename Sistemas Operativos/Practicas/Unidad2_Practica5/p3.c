#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
 pid_t pid;
 char *argv[3];
 argv[0]="hola"; 
 argv[1]="Desde el Hijo";
 argv[2]=NULL;
 if((pid=fork())==0)
 {
 printf("Soy el hijo ejecutando: %s\n", argv[0]);
 execv(argv[0],argv);
 }
 else
 {
 wait(0);
 printf("Soy el Padre\n");
 exit(0);
 }
}

