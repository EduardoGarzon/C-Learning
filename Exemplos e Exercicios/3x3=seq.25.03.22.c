/* Fazer um programa que atribua os valores 0, 1 e 2 respectivamente, às linhas de uma
matriz 3 x 3 e a mostre na tela.
Fazer um programa que atribua os valores 0, 1 e 2 respectivamente, às colunas de uma
matriz 3 x 3 e a mostre na tela. */

#include <stdio.h>

int main()
{
    int matriz[3][3];
    int i, j;
    int n = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            matriz[i][j] = n;
        }
        n++;
    }

    printf("Matriz valores na linha: \n");
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            matriz[i][j] = j;
        }
    }

    printf("\n\nMatriz valores na coluna: \n");
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);
        }
    }

    return 0;
}