/*
    Faça um algoritmo que preencha automaticamente uma matriz A 8x8
    e informe o maior valor dos elementos acima da diagonal secundária.
*/

#include <stdio.h>
#include <stdlib.h> // Para usar a funcao rand na matriz 8x8

int main()
{
    int matriz[8][8];
    int i, j;
    int aux, maior = 0;

    for (i = 0; i < 8; i++) // Gerando valores aleatorios ate 20 na matriz 8x8
    {
        for (j = 0; j < 8; j++)
        {
            matriz[i][j] = rand() % 20;
        }
    }

    printf("Matriz 8x8:\n"); // Escrevendo a matriz 8x8
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 7; i++) // Comparando os elementos acima da diagonal secundaria
    {
        for (j = 1; j < 8; j++)
        {
            if (i + j < 7) // Valores acima da DS sao os menores que 7 pois DS == 7 == i+j
            {
                aux = matriz[i][j]; // Variavel auxiliar recebe o valor

                if (aux >= maior) // Comparando se o valor em aux é maior que o em maior
                {
                    maior = aux; // maior recebe aux, caso positivo
                }
            }
        }
    }

    printf("\n\n");
    printf("Maior valor dos elementos acima da diagonal secundaria: %d\n", maior);

    system("pause");
    return 0;
}