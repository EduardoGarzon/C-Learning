/* 7 - Altere o algoritmo ao lado, considerando vetores de 80 posições, armazenando nas posições
ímpares do vetor i+10, e nas posições pares do vetor i+15. Ao final, mostre ambos os vetores. */

#include <stdio.h>

int main()
{
    int vetor[10];
    int i;

    for (i = 0; i <= 9; i++)
    {
        int x = i;
        if (i % 2 == 0)
        {
            vetor[i] = x + 10;
        }
        else
        {
            vetor[i] = x + 15;
        }
        printf("Posicao %d - Valor %d\n", i, vetor[i]);
    }
    return 0;
}