/* 2. Crie um algoritmo que leia uma matriz 3x3 e calcule a soma dos valores das colunas da
matriz, a exemplo do ilustrado abaixo. */

#include <stdio.h>

int main()
{
    int matriz[3][3];
    int i, j, numero;
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Informe um valor para %dx%d: ", i, j);
            scanf("%d", &numero);
            matriz[i][j] = numero;
        }
    }
    printf("\nMatriz 3x3: \n");
    for (i = 0; i < 3; i++)
    {

        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);

            if (j == 0)
            {
                c0 += matriz[i][j];
            }
            if (j == 1)
            {
                c1 += matriz[i][j];
            }
            if (j == 2)
            {
                c2 += matriz[i][j];
            }
        }
    }
    printf("\nSoma da coluna 1: %d", c0);
    printf("\nSoma da coluna 2: %d", c1);
    printf("\nSoma da coluna 3: %d", c2);

    return 0;
}