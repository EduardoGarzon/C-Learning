/* 1. Construa um algoritmo que leia um vetor de 20 elementos e calcule a média destes valores.
Na sequência, apresente na tela os valores que são iguais ou superiores à média e as posições
em que se encontram no vetor. */

#include <stdio.h>

int main()
{
    int vetor[20];
    int soma = 0;

    for (int i = 0; i < 20; i++)
    {
        printf("Informe um numero: ");
        scanf("%i", &vetor[i]);
        soma += vetor[i];
    }

    soma = soma / 20;
    printf("\nMedia dos valores informados: %i\n", soma);
    printf("Valores do vetor que sao maiores ou iguais a media: \n");
    for (int i = 0; i < 20; i++)
    {
        if (vetor[i] >= soma)
        {
            printf("\nPosicao: %i - Numero: %i\n", i, vetor[i]);
        }
    }
}