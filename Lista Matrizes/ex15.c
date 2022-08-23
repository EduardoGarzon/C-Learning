/* 15. Dada uma matriz de inteiros A com 2 linhas e 3 colunas e um vetor de inteiros V com 3 elementos,
determinar o produto de A por V. Observe o exemplo mostrado a seguir. */

#include <stdio.h>

int main()
{
    int A[2][3] = {2, 1, 3, 4, (-3), 5}; // matriz
    int V[3] = {2, 3, 5};                // vetor
    int result[2][1] = {0};              // matriz resultado
    int i, j;                            // indices

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == 0) // multiplica cada elemento de V com o correspondente
            {           // de cada coluna da linha 0 da matriz
                result[0][0] += V[j] * A[i][j];
            }
            else if (i == 1) // mesma operacao, agora na linha 1
            {
                result[1][0] += V[j] * A[i][j];
            }
        }
    }

    printf("Matriz 2x3: \n"); // escreve a matriz
    for (i = 0; i < 2; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%2d ", A[i][j]);
        }
    }

    printf("\n\nVetor: \n\n"); // escreve o vetor
    for (i = 0; i < 3; i++)
    {
        printf("%d\n", V[i]);
    }

    printf("\nResultado: \n\n"); // escreve a matriz resultante
    for (i = 0; i < 2; i++)
    {
        printf("%d\n", result[i][0]);
    }

    return 0;
}