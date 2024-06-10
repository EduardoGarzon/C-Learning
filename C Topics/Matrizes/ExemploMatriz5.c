/*
    Faça um programa que após ter sido digitado seu conteúdo
    (números inteiros) multiplique-o por um valor digitado pelo usuário
    e a mostre na tela.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[3][3];
    int i, j, numero;

    printf("Informe um valor inteiro: ");
    scanf("%d", &numero);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            matriz[i][j] = numero;
        }
    }

    printf("Informe um numero inteiro para multiplicar: ");
    scanf("%d", &numero);

    printf("\n");
    printf("Elementos da matriz 3x3 multiplicados por %d:\n", numero);
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j] *= numero);
        }
    }

    system("pause");
    return 0;
}