/*
    Construa um algoritmo que receba em um vetor,
    10 números que podem ser positivos, negativos ou zero,
    fornecidos pelo usuário, e depois exiba as posições
    e os números armazenados.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[9];

    for (int indice = 0; indice <= 9; indice++)
    {
        printf("Informe um numero positivo, negativo ou zero: ");
        scanf("%d", &vetor[indice]);
    }

    printf("\n");

    for (int indice = 0; indice <= 9; indice++)
    {
        printf("Posicao %d do numero %d\n", indice, vetor[indice]);
    }

    system("pause");
    return 0;
}