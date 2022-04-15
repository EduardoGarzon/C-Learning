/* 10. Faça um algoritmo que preencha automaticamente uma matriz A 8x8
e informe o menor valor dos elementos abaixo da diagonal secundária. */

#include <stdio.h>
#include <stdlib.h> // Para usar a funcao rand na matriz 8x8
#include <limits.h> // Para usar INT_MAX

int main()
{
    int matriz[8][8];
    int i, j;
    int aux, menor = INT_MAX;

    for (i = 0; i < 8; i++) // Gerando valores aleatorios ate 20 na matriz 8x8
    {
        for (j = 0; j < 8; j++)
        {
            matriz[i][j] = rand() % 20;
        }
    }

    printf("Matriz 8x8: \n"); // Escrevendo a matriz 8x8
    for (i = 0; i < 8; i++)
    {
        printf("\n");
        for (j = 0; j < 8; j++)
        {
            printf("%2d ", matriz[i][j]);
        }
    }

    for (i = 7; i > 0; i--) // Comparando os elementos abaixo da diagonal secundaria
    {
        for (j = 1; j < 8; j++) // i decrescente e j crescente
        {
            if (i + j > 7) // Valores abaixo da DS sao os maiores que 7 pois DS == 7 == i+j
            {
                aux = matriz[i][j]; // Variavel auxiliar recebe o valor
                if (aux <= menor)   // Comparando se o valor em aux é menor que o em menor
                {
                    menor = aux; // menor recebe aux, caso positivo
                }
            }
        }
    }

    printf("\n\nMenor valor dos elementos abaixo da diagonal secundaria: %d", menor);

    return 0;
}