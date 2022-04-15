/* 3 - Construa um algoritmo em que o usuário fornecerá 10 valores inteiros. Imprima os
valores na ordem em que foram digitados e também na ordem inversa. */

#include <stdio.h>

int main()
{
    int vetor[3];

    for (int indice = 0; indice <= 2; indice++)
    {
        printf("Informe um valor: ");
        scanf("%i", &vetor[indice]);
    }

    printf("\nSequencia ordenada: \n");
    for (int indice = 0; indice <= 2; indice++)
    {
        printf("\n %i", vetor[indice]);
    }

    printf("\nSequencia inversa: \n");
    for (int indice = 2; indice >= 0; indice--)
    {
        printf("\n %i", vetor[indice]);
    }
    return 0;
}