/* 12. Escrever um algoritmo que leia uma matriz M 6x6 e calcule as somas das partes rasuradas,
tal como mostrado na ilustração abaixo. Escrever a matriz M e as somas calculadas. */

#include <stdio.h>

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

    for (i = 0; i < 6; i++)
    {
        printf("\n");
        for (j = 0; j < 6; j++)
        {
            printf("%d ", matriz[i][j]);
        }
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
    printf("\nSoma esquerda: %d", soma);
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
    printf("\nSoma direita: %d", soma);

    return 0;
}