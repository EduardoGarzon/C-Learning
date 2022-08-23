/* 1. Crie um algoritmo que leia uma matriz 4x4. Em seguida, conte quantos números pares
existem na matriz. */

#include <stdio.h>

int main()
{
    int matriz[4][4];
    int i, j, numero;
    int par = 0;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Type a number for %dx%d: ", i, j);
            scanf("%d", &numero);
            matriz[i][j] = numero;

            if (numero % 2 == 0)
            {
                par++;
            }
        }
    }
    printf("\nMatrix 4x4: \n");
    for (i = 0; i < 4; i++)
    {
        printf("\n");
        for (j = 0; j < 4; j++)
        {
            printf("%d ", matriz[i][j]);
        }
    }
    printf("\nNumeros pares encontrados na matriz: %d", par);

    return 0;
}