/*
    Faça um algoritmo para ler uma matriz 5x5.

    Em seguida crie uma matriz multiplicando os
    elementos positivos da matriz inicial por k,
    e os negativos por q, sendo k e q informados pelo usuário.

    Imprimir a matriz e os valores k e q.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[5][5], matrizB[5][5];
    int i, j, numero, valor, valor2;

    printf("Informe um valor para multiplicar os valores positivos da matriz: ");
    scanf("%d", &valor);

    printf("Informe um valor para multiplicar os valores negativos da matriz: ");
    scanf("%d", &valor2);

    printf("\n");

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("Informe o valor para %dx%d: ", i, j);
            scanf("%d", &numero);

            matriz[i][j] = numero;

            if (matriz[i][j] >= 0)
            {
                matrizB[i][j] = numero * valor;
            }
            else if (matriz[i][j] < 0)
            {
                matrizB[i][j] = numero * valor2;
            }
        }
    }

    printf("\n");
    printf("Matriz Normal:\n");
    for (i = 0; i < 5; i++)
    {
        printf("\n");
        for (j = 0; j < 5; j++)
        {
            printf("%2d ", matriz[i][j]);
        }
    }

    printf("\n");
    printf("Matriz Multiplicada | Positivos por %d e Negativos por %d\n", valor, valor2);
    for (i = 0; i < 5; i++)
    {
        printf("\n");
        for (j = 0; j < 5; j++)
        {
            printf("%2d ", matrizB[i][j]);
        }
    }

    system("pause");
    return 0;
}