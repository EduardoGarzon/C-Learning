/*
    Escreva um algoritmo que gere os 10 primeiros elementos da série de Fibonacci
    e os armazene em uma matriz 2x5.

    Mostre a matriz no final.

    Fn = Fn - 1 + Fn - 2
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A = 0, B = 1, F;
    int matriz[2][5];
    int i = 0, j;

    printf("Sequencia Fibonacci: ");

    while (i <= 9)
    {
        F = A + B;

        printf("%d ", F);

        A = B;
        B = F;

        if (i < 4)
        {
            matriz[0][i] = F;
        }
        else
        {
            matriz[1][i - 5] = F;
        }

        i++;
    }

    printf("\n\n");
    printf("Matriz Fibonacci:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}