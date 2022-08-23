/* Com o programa anterior (matriz 3 x 3) faça um programa que insira nela um único
número inteiro digitado pelo usuário e a mostre na tela. */

#include <stdio.h>

int main()
{
    int matriz[3][3];
    int i, j, numero;

    printf("Informe um numero inteiro: ");
    scanf("%d", &numero);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            matriz[i][j] = numero;
        }
    }
    printf("Matriz 3x3 com o valor %d: ", numero);
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j]);
        }
    }

    return 0;
}