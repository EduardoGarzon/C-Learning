/* 2. Faça um programa que solicite ao usuário o tamanho de um vetor a ser lido e faça a
alocação dinâmica de memória. Em seguida, leia do usuário seus valores e imprima o vetor na
tela. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *x;      // variavel ponteiro do tipo int
    int tamanho; // variavel para o tamanho da alocacao

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);
    x = (int *)malloc(tamanho * sizeof(int)); // alocando espacos de acordo com o tamanho informado

    int i = 0;
    for (i = 0; i < tamanho; i++) // lendo valores para os espacos alocados
    {
        printf("Informe um valor inteiro para a posicao [%d]: ", i);
        scanf("%d", &x[i]);
    }

    for (i = 0; i < tamanho; i++) // escrevendo os valores
    {
        printf("\nPosicao [%2d] - Valor [%2d]", i, x[i]);
    }
    free(x);
    return 0;
}