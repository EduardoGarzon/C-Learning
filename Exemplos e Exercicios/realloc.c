/* A funcao Realloc aumenta ou diminui uma alocacao realizada previamente */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int *x = (int *)malloc(5 * sizeof(int)); // alocando 5 espacos do tipo inteiro
    int *x1;

    if (x == NULL) // testando alocacao
    {
        printf("Erro na alocacao!");
        exit(1);
    }

    for (i = 0; i < 5; i++) // preenchendo vetor alocado
    {
        printf("Informe um valor para a posicao [%d]: ", i);
        scanf("%d", &x[i]);
    }

    for (i = 0; i < 5; i++) // escrevendo vetor preenchido
    {
        printf("\nPosicao [%d] - %2d", i, x[i]);
    }
    printf("\n\n");

    x1 = (int *)realloc(x, 10 * sizeof(int)); // realocando em mais espacos o vetor

    for (i = 5; i < 10; i++) // preenchendo novos espacos alocados
    {
        printf("Informe um valor para a posicao [%d]: ", i);
        scanf("%d", &x[i]);
    }

    for (i = 0; i < 10; i++) // escrevendo o novo vetor alocado
    {
        printf("\nPosicao [%d] - %2d", i, x[i]);
    }
    free(x);

    return 0;
}