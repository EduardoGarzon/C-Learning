/*
    Armazenar em uma matriz as 10 primeiras linhas do triângulo de Pascal.

    Pense em alternativas para armazenar e
    imprimir os valores constantes na matriz.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int pascal[10][10];
    int i, j, x, y;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < i + 1; j++)
        {

            if (j == i || j == 0) // atribui 1 na coluna 0 e na diagonal principal
            {
                pascal[i][j] = 1;
            }
            else
            {
                pascal[i][j] = 0; // atribui 0 no restante
            }
        }
    }

    printf("Matriz Triangulo de Pascal: \n");
    for (x = 0; x < 10; x++)
    {
        for (y = 0; y < x + 1; y++)
        {
            if (pascal[x][y] == 0) // elementos iguais a zero, onde serao operados
            {
                // soma  a linha x anterior na coluna y corresnpondente
                // com o elemento anterior a esse y e assim sucessivamente
                pascal[x][y] = pascal[x - 1][y] + pascal[x - 1][y - 1];
            }

            printf("%2d ", pascal[x][y]); // escrevendo o triangulo
        }
        printf("\n");
    }

    system("pause");
    return 0;
}