/* 17. Dizemos que uma matriz quadrada inteira é um quadrado mágico
se a soma dos elementos de cada linha, a soma dos elementos de cada coluna e
a soma dos elementos das diagonais principal e secundária são todas iguais.
O exemplo abaixo apresenta uma matriz que é quadrado mágico.
Dada uma matriz quadrada A(5x5), verificar se A é um quadrado mágico (USP). */

#include <stdio.h>

int main()
{
    int A[5][5] = {11, 4, 17, 10, 23, 24, 12, 5, 18, 6, 7, 25, 13,
                   1, 19, 20, 8, 21, 14, 2, 3, 16, 9, 22, 15};
    int i, j;
    int aux = 0, aux2 = 0, aux3 = 0, aux4 = 0;
    int flag = 0;

    printf("Matriz 5x5\n");
    for (i = 0; i < 5; i++)
    {
        printf("\n");
        for (j = 0; j < 5; j++)
        {
            if (i == j)
            {
                aux += A[i][j]; // somando diagonal principal
            }
            if (i + j == 4)
            {
                aux2 += A[i][j]; // somando diagonal secundaria
            }
            printf("%2d ", A[i][j]); // escrevendo a matriz
        }
    }
    printf("\n\nConstante Magica: %d", aux);

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (aux == aux2) // comparando se DP e DS sao iguais
            {
                aux3 += A[i][j]; // somando linhas
                aux4 += A[j][i]; // somando colunas

                if (aux3 == aux && aux4 == aux) // se linhha e coluna igual DP flag++
                {
                    flag++; // se DP == DS e aux3 e aux 4 == DP, logo sao todos iguais
                }
            }
        }
        aux3 = 0; // zera a variavel para a proxima soma e teste
        aux4 = 0;
    }

    if (flag == 5)
    {
        printf("\n\nMatriz Quadrado Magico.");
    }
    else
    {
        printf("\n\nMatriz nao e um quadrado magico.");
    }

    return 0;
}
