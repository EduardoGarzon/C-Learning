/*
A funcao malloc aloca determinado espaco de memoria e retorna um ponteiro do tipo void
para o inicio do espaco alocado;
A funcao free libera o espaco de memoria alocado;
NULL referencia objeto nulo, 0 é utilizado como NULL pois acessar um endereco neste valor é um erro.
NULL indica que o ponterio nao esta apontando para um valor/endereco de memoria, ponteiro nulo;
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int *x; // variavel ponteiro do tipo inteiro

    x = (int *)malloc(5 * sizeof(int)); // alocar 5 espacos do tipo inteiro

    if (x == NULL) // testar alocacao
    {
        printf("Erro na alocacao!");
        exit(1); // encerra o programa
    }

    for (i = 0; i < 5; i++) // lendo valores para o vetor alocado
    {
        printf("Informe um valor para espaco [%d]: ", i);
        scanf("%d", &x[i]);
    }

    for (i = 0; i < 5; i++) // escrevendo os valores do vetor alocado
    {
        printf("\nPosicao [%d] - %2d", i, x[i]);
    }
    free(x); // libera espaco de memoria alocado

    return 0;
}