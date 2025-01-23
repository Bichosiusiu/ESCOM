#include <stdio.h>

void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        printf("Mover disco 1 de %c a %c\n", origen, destino);
        return;
    }
    hanoi(n - 1, origen, auxiliar, destino);
    printf("Mover disco %d de %c a %c\n", n, origen, destino);
    
    hanoi(n - 1, auxiliar, destino, origen);
}

int main() {
    int n;

    printf("Ingresa el número de discos: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');

    return 0;
}
