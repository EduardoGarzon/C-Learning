/*
    Escrever um algoritmo que leia uma matriz M 6x6
    e calcule as somas das partes rasuradas.

    Escrever a matriz M e as somas calculadas.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[6][6];
    int i, j;
    int soma = 0;

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("Informe um valor para %dx%d: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n");
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (i = 1; i < 5; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if ((i + j < 5) && (i != j))
            {
                soma += matriz[i][j];
            }
        }
    }

    printf("\n");
    printf("Soma esquerda: %d\n", soma);

    soma = 0;

    for (i = 1; i < 5; i++)
    {
        for (j = 4; j <= 5; j++)
        {
            if ((i + j > 5) && (i != j))
            {
                soma += matriz[i][j];
            }
        }
    }

    printf("\n");
    printf("Soma direita: %d\n", soma);

    system("pause");
    return 0;
}