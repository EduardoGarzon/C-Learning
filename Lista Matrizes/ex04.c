/* 4. Construa um algoritmo que leia um conjunto de números inteiros para preencher uma matriz 5 x 5
e a partir daí, gere um vetor com os maiores elementos de cada linha
e outro vetor com os menores elementos de cada coluna. Imprima a matriz e os vetores. */

#include <stdio.h>
#include <limits.h>

int main()
{
    int matriz[5][5], Vmaior[25], Vmenor[25]; // Matriz, vetor maior e menor
    int i, j, x = 0, y = 0;                   // Indices
    int maior = 0, menor = INT_MAX;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("Informe um numero para %dx%d: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (matriz[i][j] >= maior)
            {
                maior = matriz[i][j];
            }
        }
        Vmaior[x] = maior;
        x++;
        maior = 0;
    }
    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < 5; i++)
        {
            if (matriz[i][j] <= menor)
            {
                menor = matriz[i][j];
            }
        }
        Vmenor[y] = menor;
        y++;
        menor = INT_MAX;
    }
    for (i = 0; i < 5; i++)
    {
        printf("\n");
        for (j = 0; j < 5; j++)
        {
            printf("%d ", matriz[i][j]);
        }
    }
    printf("\nMaiores valores de cada linha: \n");
    for (i = 0; i < x; i++)
    {
        printf("%d ", Vmaior[i]);
    }
    printf("\nManores valores de cada coluna: \n");
    for (i = 0; i < y; i++)
    {
        printf("%d ", Vmenor[i]);
    }

    return 0;
}