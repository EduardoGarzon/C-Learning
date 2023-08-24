/* 16. Dizemos que uma matriz inteira Anxn é uma matriz de permutação se em cada linha e
em cada coluna houver n-1 elementos nulos e um único elemento igual a 1.
No exemplo abaixo, a primeira matriz é de permutação e a segunda não é.
Dada uma matriz inteira A(5x5), verificar se A é de permutação (USP). */

#include <stdio.h>

int main()
{

    int A[5][5];
    int i, j;
    int flag = 0;
    int flagB = 0;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("Informe um valor para %dx%d: ", i, j);
            scanf("%d", &A[i][j]);

            if (A[i][j] == 1 || A[i][j] == 0)
            {
                flag++;
            }
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (A[i][j] == 1 || A[j][i] == 1)
            {
                flagB++;
            }
        }
    }

    printf("Matriz 5x5: \n");
    for (i = 0; i < 5; i++)
    {
        printf("\n");
        for (j = 0; j < 5; j++)
        {
            printf("%d ", A[i][j]);
        }
    }

    if (flag == 25 && flagB == 5)
    {
        printf("\nMatriz Permutacao.");
    }
    else
    {
        printf("\nMatriz nao e de Permutacao.");
    }

    return 0;
}