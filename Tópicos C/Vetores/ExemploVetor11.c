/*
    Dados dois vetores A e B de tamanho igual a 10,
    crie um vetor C do mesmo tamanho,
    cujos elementos são a soma dos elementos de mesmo índice dos vetores A e B.

    Mostre os três vetores no final.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetorA[10], vetorB[10], vetorC[10];
    int sinal = 0;
    int i = 0, ii = 0, iii = 0;

    for (int i = 0; i < 10; i++)
    {
        vetorA[i] = i;
        vetorB[i] = i;
        vetorC[i] = vetorA[i] + vetorB[i];
    }

    for (sinal = 0; sinal <= 29; sinal++)
    {
        if (sinal < 10)
        {
            printf("Posicao A: %d - Vetor A: %d\n", i, vetorA[i]);
            i++;
        }
        else if (sinal >= 10 && sinal < 20)
        {
            printf("Posicao B: %d - Vetor B: %d\n", ii, vetorB[ii]);
            ii++;
        }
        else
        {
            printf("Posicao C: %d - Vetor C: %d\n", iii, vetorC[iii]);
            iii++;
        }
    }

    system("pause");
    return 0;
}