#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY_STRING ""

// crea el nodo del arbol
struct Node
{
    char ch;
    int freq;
    struct Node *left, *right;
};


struct Node* getNode(char ch, int freq, struct Node* left, struct Node* right)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));//asigna memoria a un arbol

    node->ch = ch;
    node->freq = freq;//asigna los valores al arbol
    node->left = left;
    node->right = right;

    return node;//retorna el nodo
}

int unnodo(struct Node* root) {
    return root->left == NULL && root->right == NULL;//verifica si el arbol de huffman tiene un solo noso
}

// Atraviesa el árbol de Huffman y almacena los códigos de Huffman en un mapa.
void codificar(struct Node* root, char* str, char** huffman)
{
    if (root == NULL) {
        return;//si no hay raiz, no devuelve nada
    }

    if (unnodo(root)) { //si hay un nodo
        if (strcmp(str, EMPTY_STRING) != 0) {
            strcpy(huffman[root->ch], str);//copia los valores en hoffman
        } else {
            strcpy(huffman[root->ch], "1");// agrega un uno
        }
    }

    char left[256];
    char right[256];
    strcpy(left, str);//copia los valores obtenidos en un arreglo left
    strcpy(right, str);//copia los valores obtenidos en un arreglo right

    strcat(left, "0");//agrega un 0
    strcat(right, "1");//agrega un 1

    codificar(root->left, left, huffman);//recursividad donde los valores se envian de nuevo
    codificar(root->right, right, huffman);//recursividad donde los valores se envian de nuevo pra la otra parte del arbol
}

// Atraviesa el árbol de Huffman y decodifica la string codificada
void decodificar(struct Node* root, int* i, char* str)
{
    if (root == NULL) {// si no hya raiz no devuelve nada
        return;
    }

    if (unnodo(root)) // si hya un nodo
    {
        printf("%c", root->ch);//imprime el valor de la letra
        return;
    }

    (*i)++; //incrementa el apuntador para el siguiente nodo

    if (str[*i] == '0') {// si el contenido del nodo es 0
        decodificar(root->left, i, str);//manda a llamar a decodificar recursivamente por la izquierda
    }
    else {
        decodificar(root->right, i, str);//manda a llamar a decodificar recursivamente por la derecha
    }
}

// Construye Huffman y decodifica el texto de entrada dado
void huffman(char* a)
{
    if (strcmp(a, EMPTY_STRING) == 0) {//si no hay cadena, no devuelve nada
        return;
    }

    int freq[256] = {0};
    int i = 0;
    while (a[i] != '\0') {//recorre el texto hasta el final
        freq[(int)a[i]]++;//cada vez que hay una letra diferente, aumenta el valor de la posicion del arreglo en la frecuencia
        i++;
    }

    char* h[256];
    for (int j = 0; j < 256; j++) {
        h[j] = (char*)malloc(256 * sizeof(char));// crea el arreglo y alamacena los codigos
    }

    struct Node* pq[256];// crea cola de prioridad
    int pqSize = 0;

    for (int k = 0; k < 256; k++) {
        if (freq[k] > 0) {
            pq[pqSize++] = getNode((char)k, freq[k], NULL, NULL);// crea nodos de la cola y almacena las partes del arbol
        }
    }
    while (pqSize > 1)
    {
        int m1 = 0, m2 = 1;
        if (pq[0]->freq > pq[1]->freq) {//si la frecuencia es mayor la de,l primero que la del segundo
            m1 = 1;//asugna un 1
            m2 = 0;//asigna un 0
        }

        for (int l = 2; l < pqSize; l++) {//recorre la cola
            if (pq[l]->freq < pq[m1]->freq) {
                m2 = m1;//asigna los valores dependiendo al frecuencia del nodo
                m1 = l;
            } else if (pq[l]->freq < pq[m2]->freq) {
                m2 = l;//hace intercambios para encontrar los mas pequeños 
            }
        }

        struct Node* left = pq[m1];//asigna al arbol el nodo menor a la izquierda
        struct Node* right = pq[m2];//asigna al arbol el nodo 2do menor a la derecha
        pq[m1] = getNode('\0', left->freq + right->freq, left, right);//crea el nodo con los hijos ya asignados que son los menores

        // Elimina el nodo de menor frecuencia de la queue
        pq[m2] = pq[--pqSize];
    }

    //  almacena el puntero a la raíz de Huffman 
    struct Node* root = pq[0];

    codificar(root, EMPTY_STRING, h);//codificamos la cadena

    printf("Los codigos son :\n\n");
    for (int m = 0; m < 256; m++) {
        if (freq[m] > 0) { //el arreglo de frecuencias se imprime como cadena
            printf("%c %s\n", (char)m, h[m]);
        }
    }

    printf("\nLa cadena original es :\n%s\n", a);
    char str[256] = {0};
    i = 0;
    while (a[i] != '\0') {
        strcat(str, h[(int)a[i]]);//imprimimos la cadena codificada
        i++;
    }

    printf("\nLa cadena codificada es :\n%s\n", str);
    printf("\nLa cadena decodificada es:\n");

    if (unnodo(root))
    {
        // caso en el cual se repite la letra
        while (root->freq--) {
            printf("%c", root->ch);//imprimimos la misma letra 
        }
    }
    else {
        int i = -1;
        while (i < (int)strlen(str) - 1) {//mandamos la cadena codificada hasta su fin 
            decodificar(root, &i, str);//decodificamos letra por letra 
        }
    }

    // libera la memoria
    for (int n = 0; n < 256; n++) {
        free(h[n]);
    }
}

int main()
{
    char a[] = "abracadabra";
    printf("Introduce una cadena: ");
    scanf("%s",a);
    huffman(a);

    return 0;
}