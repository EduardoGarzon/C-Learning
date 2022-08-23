/* 13. Escrever um algoritmo que leia uma matriz M 6x6 e armazene em um vetor as partes não hachuradas.
Escrever a matriz M e o respectivo vetor. */

#include <stdio.h>

int main()
{

    int matriz[6][6], vetor[24];
    int i, j;
    int x = 0;

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("Informe um valor para %dx%d: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (i = 0; i < 6; i++) // comparador
    {
        for (j = 0; j < 6; j++)
        {
            if (i == j || i + j == 5) // salvando a diagonal principal e secundaria
            {
                vetor[x] = matriz[i][j];
                x++;
            }
            else if ((i == 0 && 0 < j < 5) || (i == 1 && j > 1 && j < 4))
            {
                vetor[x] = matriz[i][j]; // salvando linha 0 e linha 1
                x++;
            }
            else if ((i == 4 && j > 1 && j < 4) || (i == 5 && 0 < j < 5))
            {
                vetor[x] = matriz[i][j]; // salvando linha 4 e linha 5
                x++;
            }
        }
    }

    printf("\nMatriz 6x6: \n"); // escrevendo a matriz
    for (i = 0; i < 6; i++)
    {
        printf("\n");
        for (j = 0; j < 6; j++)
        {
            printf("%2d ", matriz[i][j]);
        }
    }

    printf("\n\nVetor: \n"); // escrevendo o vetor
    for (i = 0; i < x; i++)
    {
        printf("%d ", vetor[i]);
    }

    return 0;
}