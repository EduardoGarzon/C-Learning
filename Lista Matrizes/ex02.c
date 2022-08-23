/* 2. Faça um algoritmo para ler os elementos de uma matriz 4X4.
Em seguida imprimir uma mensagem dizendo se a matriz é diagonal ou não.
Uma matriz é diagonal se todos os elementos que não forem da diagonal principal forem zero. */

#include <stdio.h>

int main()
{
    int matriz[4][4];
    int i, j, numero;
    int zero = 0;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Informe um valor para %dx%d: ", i, j);
            scanf("%d", &numero);
            matriz[i][j] = numero;

            if ((numero == 0) && (i != j))
            {
                zero++;
            }
        }
    }

    printf("\nMatriz 4x4: \n");
    for (i = 0; i < 4; i++)
    {
        printf("\n");
        for (j = 0; j < 4; j++)
        {
            printf("%d ", matriz[i][j]);
        }
    }
    if (zero == 12)
    {
        printf("\nMatriz Diagonal.");
    }
    else
    {
        printf("\nMatriz nao diagonal.");
    }

    return 0;
}