/*
    Crie um algoritmo que leia um vetor com 20 números
    e some apenas os elementos positivos e que
    estão nas posições pares do vetor.

    Apresente o valor da soma no final.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[20];
    int soma = 0;

    for (int i = 0; i < 20; i++)
    {
        printf("Posicao %d - Informe um valor: ", i);
        scanf("%d", &vetor[i]);

        if ((vetor[i] > 0) && (i % 2 == 0))
        {
            soma += vetor[i];
        }
    }

    printf("\n");
    printf("Soma dos valores positivos e nas posicoes pares o vetor: %d\n", soma);

    system("pause");
    return 0;
}