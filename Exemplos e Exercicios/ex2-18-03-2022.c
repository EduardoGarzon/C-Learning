/* 2. Construa um algoritmo que receba em um vetor, 10 números que podem ser positivos,
negativos ou zero, fornecidos pelo usuário, e depois exiba as posições e os números armazenados. */

#include <stdio.h>

int main()
{
    int vetor[9];

    for (int indice = 0; indice <= 9; indice++)
    {
        printf("Informe um numero positivo, negativo ou zero: ");
        scanf("%i", &vetor[indice]);
    }

    for (int indice = 0; indice <= 9; indice++)
    {
        printf("\nPosicao %i do numero %i", indice, vetor[indice]);
    }
    return 0;
}