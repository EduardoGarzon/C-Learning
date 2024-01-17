/*
    Crie um programa que:
        (a) Aloque dinamicamente um array de 5 números inteiros;
        (b) Peça para o usuário digitar os 5 números no espaço alocado;
        (c) Mostre na tela os 5 números;
        (d) Libere a memória alocada;
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *x;                             // variavel ponteiro do tipo int
    x = (int *)malloc(5 * sizeof(int)); // alocando 5 espacos de memoria

    int i = 0;
    for (i = 0; i < 5; i++) // lendo os valores para os valores alocados
    {
        printf("Informe um valor inteiro para posicao [%d]: ", i);
        scanf("%d", &x[i]);
    }

    for (i = 0; i < 5; i++) // escrevendo os valores preenchidos
    {
        printf("Posicao [%2d] - Valor [%2d]\n", i, x[i]);
    }

    free(x); // desalocacao

    system("pause");
    return 0;
}