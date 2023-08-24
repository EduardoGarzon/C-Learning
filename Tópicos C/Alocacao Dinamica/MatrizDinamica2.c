/**
 *  Exemplo de Aritmetica de Ponteiros para acessar
 *  uma matriz alocada dinamicamente.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    // ponteiro para ponteiro
    int **mat, i, j;

    // aloca um vetor de ponteiros para int
    mat = malloc(5 * sizeof(int *));

    // para cada posicao do vetor aloca um vetor de int
    for (i = 0; i < 5; i++)
        mat[i] = malloc(5 * sizeof(int));

    srand(time(NULL));

    // Artimetica de ponteiros
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            /**
             * 1. Aritmetica para as linhas *(mat + i), obtemos o endereco
             *    inicial da linha que queremos acessar.
             * 2. Aritmetica para acessar posicao especifica dessa linha.
             * 3. Temos assim a linha e coluna que indica a posicao acessada.
             */
            *(*(mat + i) + j) = rand() % 100;
        // mat[i][j] = rand() % 100;
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%2d ", *(*(mat + i) + j));
        // printf("%d ", mat[i][j]);
        printf("\n");
    }

    return 0;
}