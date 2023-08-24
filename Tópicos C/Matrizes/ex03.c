/* 3. Faça um algoritmo que, a partir de duas matrizes 4x4 de números inteiros,
imprima somente os números que estão conjuntamente em ambas as matrizes. */

#include <stdio.h>

int main()
{
    int A[4][4], B[4][4], C[16];
    int i, j, numero;
    int x = 0;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Informe um numero para %dx%d: ", i, j);
            scanf("%d", &numero);
            A[i][j] = numero;
        }
    }

    printf("\n");

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Informe um numero para %dx%d: ", i, j);
            scanf("%d", &numero);
            B[i][j] = numero;
            for (int z = 0; z < 4; z++)
            {
                for (int y = 0; y < 4; y++)
                {
                    if (numero == A[z][y])
                    {
                        C[x] = numero;
                        x++;
                    }
                }
            }
        }
    }

    printf("\nValores presentes em ambas as matrizes:");

    for (i = 0; i < x; i++)
    {
        printf("\n%d - %d", i, C[i]);
    }

    return 0;
}