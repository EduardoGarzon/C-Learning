/*
    Faça um algoritmo que, a partir de duas matrizes 4x4 de números inteiros,
    imprima somente os números que estão conjuntamente em ambas as matrizes.
*/

#include <stdio.h>
#include <stdlib.h>

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
        }
    }

    int x = 0;
    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 3; i++)
        {
            for (int y = 0; y <= 3; y++)
            {
                for (int z = 0; z <= 3; z++)
                {
                    if (A[i][j] == B[y][z])
                    {
                        int w = 0;
                        while (w <= 15)
                        {
                            if (A[i][j] == C[w])
                            {
                                break;
                            }
                            else
                            {

                                C[x] = A[i][j];
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }

    printf("\n");
    printf("Valores presentes em ambas as matrizes:\n");

    for (i = 0; i < x; i++)
    {
        printf("%d - %d\n", i, C[i]);
    }

    system("pause");
    return 0;
}