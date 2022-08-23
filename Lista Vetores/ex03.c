/* 3. Elabore um algoritmo que leia um vetor com 15 elementos e um número n entre 1 e 15.
Mostre na tela o índice e os elementos do vetor cuja posição é inferior a n. */

#include <stdio.h>

int main()
{
    int vetor[15];
    int numero;
    for (int i = 0; i < 15; i++)
    {
        printf("Informe um valor: ");
        scanf("%i", &vetor[i]);
    }
    printf("\nInforme um numero entre 1 e 15: ");
    scanf("%i", &numero);

    printf("\nValores do vetor menores que %i\n", numero);
    for (int i = 0; i < 15; i++)
    {
        if (vetor[i] < numero)
        {
            printf("Posicao: %i - Valor: %i\n", i, vetor[i]);
        }
    }
}