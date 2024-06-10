/*
    Faça um programa que insira um único número inteiro
    digitado pelo usuário e a mostre na tela.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[3][3];
    int i, j, numero;

    printf("Informe um numero inteiro: ");
    scanf("%d", &numero);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            matriz[i][j] = numero;
        }
    }

    printf("\n");
    printf("Matriz 3x3 com o valor %d: ", numero);

    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);
        }
    }

    system("pause");
    return 0;
}