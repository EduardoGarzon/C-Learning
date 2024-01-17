/*
    Crie um algoritmo que leia uma matriz 3x3
    e crie uma nova matriz que seja a matriz transposta da primeira
    (troque as linhas por colunas) a exemplo do ilustrado abaixo.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[3][3];
    int i, j, numero;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Informe uma valor para %dx%d: ", i, j);
            scanf("%d", &numero);

            matriz[i][j] = numero;
        }
    }

    printf("\n");
    printf("Matriz 3x3:\n");
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);
        }
    }

    printf("\n");
    printf("Matriz 3x3 Transposta:\n");
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matriz[j][i]);
        }
    }

    system("pause");
    return 0;
}