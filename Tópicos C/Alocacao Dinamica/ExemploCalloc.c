/*
    Exemplo de alocacao dinamica com calloc em C.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *c; // ponteiro para char

    // a funcao faz a multiplicacao da quantidade de memoria vezes a quantidade de elementos
    // total de elementos, tamanho de cada espaco
    c = calloc(1, sizeof(char));

    if (c)
    {
        printf("Char alocado: %c\n", *c); // inicializa espaco zerado
        *c = 'A';
        printf("Char atribuido: %c\n", *c);
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
        return -1;
    }

    system("pause");
    return 0;
}