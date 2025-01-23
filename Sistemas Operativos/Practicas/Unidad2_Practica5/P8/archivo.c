#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    execlp("cat", "cat", "suma.txt", "resta.txt", "multiplicacion.txt", "transpuesta_A.txt", 
    "transpuesta_B.txt", "inversa_A.txt", "inversa_B.txt", NULL);
}

