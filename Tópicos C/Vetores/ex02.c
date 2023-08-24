/* 2. Faça um algoritmo que leia 10 números do teclado e os armazene em um vetor.
Crie um segundo vetor de 10 posições que armazene o dobro de cada um dos números do primeiro vetor.
Crie um terceiro vetor de 10 posições que armazene o triplo de cada um dos números do primeiro vetor.
Faça isso da maneira mais otimizada possível. Apresente os três vetores na tela. */

#include <stdio.h>

int main()
{
    int vetor1[10], vetor2[10], vetor3[10];

    for (int i = 0; i < 10; i++)
    {
        printf("Informe um numero: ");
        scanf("%i", &vetor1[i]);

        vetor2[i] = 2 * vetor1[i];
        vetor3[i] = 3 * vetor1[i];
    }

    for (int i = 0; i < 10; i++)
    {
        printf("\nPosicao: %i\n", i);
        printf("Vetor: %i\n", vetor1[i]);
        printf("Vetor dobro: %i\n", vetor2[i]);
        printf("Vetor triplo: %i", vetor3[i]);
        printf("\n");
    }

    return 0;
}