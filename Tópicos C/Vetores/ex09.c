/* 9. Dado dois vetores, A (10 elementos) e B (15 elementos),
escreva um programa que imprima todos os elementos comuns aos dois vetores A e B. */

#include <stdio.h>

int main()
{
    int vetorA[10], vetorB[15], vetorC[10];
    int i = 0;
    int sinal = 0;
    int y = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Informe um valor para o vetor A: ");
        scanf("%d", &vetorA[i]);
    }

    printf("\n");

    for (i = 0; i < 15; i++)
    {
        printf("Informe um valor para o vetor B: ");
        scanf("%d", &vetorB[i]);

        for (int x = 0; x < 10; x++)
        {
            if (vetorB[i] == vetorA[x])
            {
                sinal = 1;
            }
        }

        if (sinal == 1)
        {
            vetorC[y] = vetorB[i];
            y++;
        }

        sinal = 0;
    }

    printf("\nValores em comum entre os vetores: \n");
    for (i = 0; i < y; i++)
    {
        printf("%i\n", vetorC[i]);
    }
}