/* 5. Escreva um algoritmo que leia uma matriz quadrada 5 x 5 de elementos reais,
divida cada elemento de uma linha da matriz pelo elemento da diagonal principal desta linha
e imprima a matriz assim modificada. Evite divisões por zero. */

#include <stdio.h>

int main()
{
    float matriz[5][5]; // Matriz
    int i, j; // Indices da matriz
    float d0, d1, d2, d3, d4; // variaveis dos elementos da diagonal principal

    for (i = 0; i < 5; i++) 
    {
        for (j = 0; j < 5; j++)
        {
            printf("Informe um valor para %dx%d: ", i, j); // Leitura do valor da matriz
            scanf("%f", &matriz[i][j]);

            if (i == j && i == 0) // Testando se o elemento faz parte da DP
            {
                d0 = matriz[i][j];
            }
            else if (i == j && i == 1) // Cada elemento da DP foi armazenado em uma variavel
            {
                d1 = matriz[i][j];
            }
            else if (i == j && i == 2)
            {
                d2 = matriz[i][j];
            }
            else if (i == j && i == 3)
            {
                d3 = matriz[i][j];
            }
            else if (i == j && i == 4)
            {
                d4 = matriz[i][j];
            }
        }
    }

    for (i = 0; i < 5; i++) // Dividindo os elementos de cada linha por seu elemento respectivo da DP
    {
        for (j = 0; j < 5; j++)
        {
            if (i != j && i == 0 && d0 != 0) // Nao pode dividir o elemento da DP por ele mesmo
            {
                matriz[i][j] /= d0;
            }
            else if (i != j && i == 1 && d1 != 0) // Testanto se os elementos da DP sao != 0
            {
                matriz[i][j] /= d1;
            }
            else if (i != j && i == 2 && d2 != 0)
            {
                matriz[i][j] /= d2;
            }
            else if (i != j && i == 3 && d3 != 0)
            {
                matriz[i][j] /= d3;
            }
            else if (i != j && i == 4 && d4 != 0)
            {
                matriz[i][j] /= d4;
            }
        }
    }

    printf("\nMatriz linha / elemento da diagonal principal correspondente: \n");
    printf("Elemento diagonal == 0, nao se faz divisao.\n");
    for (i = 0; i < 5; i++) 
    {
        printf("\n ");
        for (j = 0; j < 5; j++)
        {
            printf("%0.1f ", matriz[i][j]); // Matriz final
        }
    }

    return 0;
}