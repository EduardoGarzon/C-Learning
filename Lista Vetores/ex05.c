/* 5. Crie um algoritmo que leia um vetor com 20 números e some apenas os elementos positivos e que
estão nas posições pares do vetor. Apresente o valor da soma no final. */

#include <stdio.h>

int main()
{
    int vetor[20];
    int soma = 0;
    
    for (int i = 0; i < 20; i++)
    {
        printf("Posicao %i - Informe um valor: ", i);
        scanf("%i", &vetor[i]);

        if ((vetor[i] > 0) && (i % 2 == 0))
        {
            soma += vetor[i];
        }
    }
    printf("\nSoma dos valores positivos e nas posicoes pares o vetor: %i", soma);

    return 0;
}