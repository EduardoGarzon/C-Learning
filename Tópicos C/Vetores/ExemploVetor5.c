/*
    Elabore um algoritmo que leia um vetor com 15 elementos
    e um número n entre 1 e 15.

    Mostre na tela o índice e os elementos do vetor cuja posição é inferior a n.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[15];
    int numero;

    for (int i = 0; i < 15; i++)
    {
        printf("Informe um valor: ");
        scanf("%d\n", &vetor[i]);
    }

    printf("\n");
    printf("Informe um numero entre 1 e 15: ");
    scanf("%d", &numero);

    printf("\n");
    printf("Valores do vetor menores que %d\n", numero);
    for (int i = 0; i < 15; i++)
    {
        if (vetor[i] < numero)
        {
            printf("Posicao: %d - Valor: %d\n", i, vetor[i]);
        }
    }

    system("pause");
    return 0;
}