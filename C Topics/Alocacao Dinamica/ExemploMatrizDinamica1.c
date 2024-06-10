/**
 * Alocando uma matriz dinamicamente em C
 *
 *               int
 *      int* ->  10   20  30
 *               int
 *      int* ->  40   50  60
 *               int
 *      int* ->  70   80  90
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char *argv[])
{
    srand(time(NULL));

    int linha = atoi(argv[1]);
    int coluna = atoi(argv[2]);

    // ponteiro para ponteiro
    int **mat;
    // vetor de vetor, vetor de ponteiros do tipo int para vetores do tipo int (linhas da coluna)
    mat = malloc(linha * sizeof(int *));

    // alocando as linhas da matriz
    for (int i = 0; i < linha; i++)
    {
        mat[i] = malloc(coluna * sizeof(int));
    }

    printf("Vetor Alocado:\n");
    for (int i = 0; i < linha; i++)
    {
        printf("[");
        for (int j = 0; j < coluna; j++)
        {
            mat[i][j] = rand() % 10;
            printf(" %d ", mat[i][j]);
        }
        printf("]\n");
    }

    printf("Tecle [ENTER] para desalocar a matriz...\n");
    getchar();

    free(mat);

    system("pause");
    return 0;
}