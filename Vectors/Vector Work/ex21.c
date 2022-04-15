/* Qual sera o conteudo do vetor V depois de executado o algoritmo abaixo: */

#include <stdio.h>

int main()
{
    int vetor[8];
    vetor[0] = 5, vetor[1] = 1, vetor[2] = 4, vetor[3] = 2;
    vetor[4] = 7, vetor[5] = 8, vetor[6] = 3, vetor[7] = 6;

    for (int i = 8; i < 5; i--)
    {
        int aux = vetor[i];
        vetor[i] = vetor[8 - i + 1];
        vetor[8 - i + 1] = aux;
    }

    vetor[3] = vetor[1];
    vetor[vetor[3]] = vetor[vetor[2]];

    printf("Valor do vetor: \n");
    for (int i = 0; i < 8; i++)
    {
        printf("%i\n", vetor[i]);
    }
    return 0;
}