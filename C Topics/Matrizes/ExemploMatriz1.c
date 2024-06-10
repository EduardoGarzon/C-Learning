/*
    Uma matriz é uma coleção de variáveis de mesmo tipo,
    acessíveis com um único nome e armazenados contiguamente na memória.

    A individualização de cada variável de um vetor é feita
    através do uso de índices.

    Os Vetores são matrizes de uma só dimensão.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[5][3]; // matriz de 5 linhas e 3 colunas, 5x2;

    for (int i = 0; i <= 4; i++)
    {
        for (int x = 0; x <= 2; x++)
        {
            matriz[i][x] = 10;
        }
    }

    for (int i = 0; i <= 4; i++)
    {
        printf("\n");
        for (int x = 0; x <= 2; x++)
        {
            printf("%d ", matriz[i][x]);
        }
    }

    system("pause");
    return 0;
}