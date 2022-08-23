/* 4 - Faça um algoritmo que leia 10 números inteiros armazenando os 5 primeiros em um vetor
e os outros 5 em outro vetor. Mostre ambos os vetores no final. */

#include <stdio.h>

int main()
{
    int vetor1[5], vetor2[5];
    int numero = 0;

    for (int i = 0; i <= 9; i++)
    {
        printf("Informe um numero: ");
        scanf("%d", &numero);

        if (i <= 4)
        {
            vetor1[i] = numero;
        }
        else if (i > 4)
        {
            vetor2[i - 5] = numero;
        }
    }

    for (int i = 0; i <= 4; i++)
    {
        printf("\nVetor 1: %d", vetor1[i]);
        printf("\n           | Vetor 2: %d", vetor2[i]);
    }
    return 0;
}