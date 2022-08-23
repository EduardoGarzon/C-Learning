/* 4. Crie um algoritmo que leia duas matrizes 2x5 e crie uma terceira matriz também 2x5
com o valor da soma dos elementos de mesmo índice, a exemplo do ilustrado abaixo.  */

#include <stdio.h>

int main()
{
    int A[2][5], B[2][5], C[2][5];
    int i, j, numero;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("Informe o valor para A %dx%d: ", i, j);
            scanf("%d", &numero);
            A[i][j] = numero;
        }
    }
    printf("\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("Informe o valor para B %dx%d: ", i, j);
            scanf("%d", &numero);
            B[i][j] = numero;
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nMatriz A 2x5: \n");
    for (i = 0; i < 2; i++)
    {
        printf("\n");
        for (j = 0; j < 5; j++)
        {
            printf("%d ", A[i][j]);
        }
    }

    printf("\nMatriz B 2x5: \n");
    for (i = 0; i < 2; i++)
    {
        printf("\n");
        for (j = 0; j < 5; j++)
        {
            printf("%d ", B[i][j]);
        }
    }

    printf("\nMatriz soma: \n");
    for (i = 0; i < 2; i++)
    {
        printf("\n");
        for (j = 0; j < 5; j++)
        {
            printf("%d ", C[i][j]);
        }
    }

    return 0;
}