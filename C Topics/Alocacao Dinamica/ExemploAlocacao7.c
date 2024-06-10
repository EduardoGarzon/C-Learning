/*
    Faça um programa para armazenar em memória um vetor de
    dados contendo 1500 valores do tipo int,
    usando a função de alocação dinâmica de memória:
    (a) Atribua para cada elemento do vetor o valor do seu índice junto a este vetor.
    (b) Exibir na tela os 10 primeiros e os 10 últimos elementos do vetor.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;

    int *vetor = malloc(1500 * sizeof(int)); // vetor de 1500 inteiros alocados

    for (i = 0; i < 1500; i++)
    {
        vetor[i] = i; // atribui para cada espaco seu indice
    }

    printf("10 primeiros elementos:\n"); // imprime os 10 primeiros valores
    for (i = 0; i < 10; i++)
    {
        printf("Vetor indice [%d]\n", vetor[i]);
    }

    printf("\n");
    printf("10 ultimos elementos:\n"); // imprime os 10 ultimos valores
    for (i = 1490; i < 1500; i++)
    {
        printf("Vetor indice [%d]\n", vetor[i]);
    }

    free(vetor); // desalocacao

    system("pause");
    return 0;
}