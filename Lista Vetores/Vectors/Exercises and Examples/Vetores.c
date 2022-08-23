// Utilizando vetores em C.

#include <stdio.h>

int main()
{
    int vector[5]; // Vetor de 5 espacos 

    for (int indice = 0; indice < 5; indice++)
    {
        printf("Informe um numero: ");
        scanf("%i", &vector[indice]); // O espaco do vetor sera armazenado de acordo com o indice de endereco
    }

    for (int indice = 0; indice < 5; indice++)
    {
        printf("\nPosicao %i - %i\n", indice, vector[indice]); // Lendo o vetor indice a indice com seus valores 
    }
}