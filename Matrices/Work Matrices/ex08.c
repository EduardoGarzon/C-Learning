/* 8. Faça um algoritmo que preencha automaticamente uma matriz A 10x10 e realize as seguintes
trocas armazenando o resultado em uma matriz B:
a) a linha 2 com a linha 8;
b) a coluna 4 com a coluna 10;
c) a diagonal principal com a secundária;
d) a linha 5 com a coluna 10;
Mostrar ambas as matrizes no final. */

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int matriz[10][10], B[10][10];
    int i, j, aux;
    int DP[10], DS[10];
    int x = 0, y = 0;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            matriz[i][j] = rand() % 10; // Gerando valores aleatorios para a matriz 10x10 com rand semente 1
            B[i][j] = matriz[i][j];
        }
    }

    printf("Matriz 10x10\n"); // Escrevendo a matriz 10x10
    for (i = 0; i < 10; i++)
    {
        printf("\n");
        for (j = 0; j < 10; j++)
        {
            printf("%2d ", matriz[i][j]);
        }
    }

    for (int x = 0; x < 4; x++) // Linha 2 troca com a linha 8 e coluna 4 com coluna 8
    {
        if (x == 0) // Trocando linha 2 com linha 8
        {
            for (j = 0; j < 10; j++)
            {
                B[1][j] = matriz[7][j];
                B[7][j] = matriz[1][j];
            }
        }
        else if (x == 1) // Apos, trocando coluna 4 com coluna 8
        {
            for (i = 0; i < 10; i++)
            {
                aux = B[i][7];
                B[i][7] = B[i][3];
                B[i][3] = aux;
            }
        }
        else if (x == 2)
        {
            for (i = 0; i < 10; i++)
            {
                for (j = 0; j < 10; j++)
                {
                    if (i == j)
                    {
                        DP[i] = B[i][j]; // Armazenando os valores da diagonal principal
                    }
                    else if (i + j == 9)
                    {
                        DS[i] = B[i][j]; // Armazenando os valores da diagonal secundaria
                    }
                }
            }
            for (i = 0; i < 10; i++)
            {
                for (j = 0; j < 10; j++)
                {
                    if (i == j)
                    {
                        B[i][j] = DS[i]; // Armazenando os valores de DS em DP
                    }
                    else if (i + j == 9)
                    {
                        B[i][j] = DP[i]; // Armazenando os valores de DP em DS
                    }
                }
            }
        }
        else if (x == 3) // Trocando linha 5 com coluna 10
        {
            for (i = 0; i < 10; i++)
            {
                DP[i] = B[i][9]; // Armazenando Coluna 10
                for (j = 0; j < 10; j++)
                {
                    DS[j] = B[4][j]; // Armazenando linha 5
                }
            }
            for (i = 0; i < 10; i++)
            {
                B[i][9] = DS[i]; // Armazenando na coluna 10 a linha 5
                for (j = 0; j < 10; j++)
                {
                    B[4][j] = DP[j]; // Armazenando na linha 5 a coluna 10
                }
            }
        }
    }

    printf("\n\nMatriz B 10x10\n"); // Escrevendo a nova matriz 10x10
    for (i = 0; i < 10; i++)
    {
        printf("\n");
        for (j = 0; j < 10; j++)
        {
            printf("%2d ", B[i][j]);
        }
    }

    return 0;
}