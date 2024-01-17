/*
    Fazer um programa que crie uma matriz 3 x 3 e armazene nela números inteiros.
    No final, mostre a matriz na tela.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Valor inteiro para o elemento %dx%d: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n");
    printf("Valores da matriz 3x3: ");

    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        for (int j = 0; j < 3; j++)
        {
            printf("%d  ", matriz[i][j]);
        }
    }

    system("pause");
    return 0;
}