/* Fazer um programa que some os elementos de uma matriz 3x3 e mostre na tela a matriz e sua soma.
Fazer um programa que obtenha a soma e a média dos elementos de uma matriz 3x3 e mostre na tela
a matriz, sua soma e sua média. */

#include <stdio.h>

int main()
{
    int matriz[3][3];
    int i, j;
    int soma = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            matriz[i][j] = i * 2;
            soma += matriz[i][j];
        }
    }
    int media = soma / (i * j);

    printf("Matriz: ");
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);
        }
    }
    printf("\nSoma dos elementos da matriz: %d", soma);
    printf("\nMedia dos elementos da matriz: %d", media);
    return 0;
}