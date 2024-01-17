/*
    Crie um algoritmo que leia uma matriz 3x3
    e calcule a soma dos valores das colunas da matriz.
*/

#include <stdio.h>
#include <stdlib.h>

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

    printf("\n");
    printf("Matriz 3x3:\n");
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

    printf("\n");
    printf("Soma da coluna 1: %d\n", c0);
    printf("Soma da coluna 2: %d\n", c1);
    printf("Soma da coluna 3: %d\n", c2);

    system("pause");
    return 0;
}