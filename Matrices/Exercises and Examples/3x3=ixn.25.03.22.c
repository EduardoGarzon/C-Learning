/* Com o programa anterior (matriz 3 x 3) faça um programa que após ter sido digitado seu conteúdo
(números inteiros) multiplique-o por um valor digitado pelo usuário e a mostre na tela. */

#include <stdio.h>

int main()
{
    int matriz[3][3];
    int i, j, numero;

    printf("Informe um valor inteiro: ");
    scanf("%d", &numero);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            matriz[i][j] = numero;
        }
    }

    printf("Informe um numero inteiro para multiplicar: ");
    scanf("%d", &numero);

    printf("\nElementos da matriz 3x3 multiplicados por %d: ", numero);
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%d ", matriz[i][j] *= numero);
        }
    }

    return 0;
}