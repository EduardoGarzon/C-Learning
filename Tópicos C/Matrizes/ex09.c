/*  9. Desenvolva um algoritmo que leia uma matriz 4x4 e então leia um valor independente.
Apresente somente os elementos da matriz que são múltiplos do valor independente.
Se não houver elementos múltiplos, informe. */

#include <stdio.h>

int main()
{
    int matriz[4][4], vetor[16];
    int i, j;
    int numero;
    int x = 0;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Informe um valor para %dx%d: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n\nMatriz 4x4: \n");
    for (i = 0; i < 4; i++)
    {
        printf("\n");
        for (j = 0; j < 4; j++)
        {
            printf("%2d ", matriz[i][j]);
        }
    }

    printf("\n\nInforme um valor: ");
    scanf("%d", &numero);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (matriz[i][j] % numero == 0)
            {
                vetor[x] = matriz[i][j];
                x++;
            }
        }
    }

    if (x >= 1)
    {
        printf("\nValores da Matriz multiplos de %d:\n", numero);
        for (i = 0; i < x; i++)
        {
            printf("%d ", vetor[i]);
        }
    }
    else
    {
        printf("\nNenhum valor da matriz e multiplo de %d", numero);
    }

    return 0;
}