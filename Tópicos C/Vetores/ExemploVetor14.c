/*
    Escreva um algoritmo que leia um vetor A com 20 números inteiros.
    Gere 2 vetores a partir de A,
    um contendo os elementos de posições ímpares do vetor A
    e o outro com os elementos de posições pares de A.

    Imprimir os três vetores no final.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetorA[20];

    int x = 0;
    int vetorB[10];

    int y = 0;
    int vetorC[10];

    for (int i = 0; i < 20; i++)
    {
        printf("Posicao %d, Informe um numero: ", i);
        scanf("%d", &vetorA[i]);

        if (i % 2 == 0)
        {
            vetorB[x] = vetorA[i];
            x++;
        }
        else
        {
            vetorC[y] = vetorA[i];
            y++;
        }
    }

    printf("\n");

    for (int i = 0; i < x; i++)
    {
        printf("Vetor B: %d\n", vetorB[i]);
    }

    for (int i = 0; i < y; i++)
    {
        printf("Vetor C : %d\n", vetorC[i]);
    }

    system("pause");
    return 0;
}