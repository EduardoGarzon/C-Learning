/*
    Desenvolva um algoritmo que leia uma matriz 4x4
    e então leia um valor independente.

    Apresente somente os elementos da matriz
    que são múltiplos do valor independente.

    Se não houver elementos múltiplos, informe.
*/

#include <stdio.h>
#include <stdlib.h>

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

    printf("\n\n");
    printf("Matriz 4x4: \n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
    printf("Informe um valor: ");
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

    printf("\n");
    
    if (x >= 1)
    {
        printf("Valores da Matriz multiplos de %d:\n", numero);

        for (i = 0; i < x; i++)
        {
            printf("%d ", vetor[i]);
        }
    }
    else
    {
        printf("Nenhum valor da matriz e multiplo de %d\n", numero);
    }

    system("pause");
    return 0;
}