/* 6 - Altere o algoritmo ao lado, considerando vetores de 10 posições do tipo real
e armazenando no segundo vetor, o número digitado no primeiro vetor, menos 15%.
Ao final, mostre ambos os vetores. */

#include <stdio.h>

int main()
{
    float vetor1[10], vetor2[10];
    float numero;

    for (int i = 0; i <= 9; i++)
    {
        printf("Informe um valor real: ");
        scanf("%f", &numero);
        vetor1[i] = numero;

        vetor2[i] = vetor1[i] * 0.15;
    }

    printf("\n\nVetor 1: \n");

    for (int i = 0; i <= 9; i++)
    {
        printf("\nPosicao %i - Valor %0.1f", i, vetor1[i]);
    }
    printf("\n\nVetor 1 com valores -15%%\n");
    for (int i = 0; i <= 9; i++)
    {
        printf("\nPosicao %i - Valor %0.1f", i, vetor2[i]);
    }
    return 0;
}