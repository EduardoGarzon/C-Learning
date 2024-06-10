// Utilizando vetores em C.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[5]; // Vetor de 5 espacos

    for (int indice = 0; indice <= 4; indice++)
    {
        printf("Informe um numero: ");
        // O espaco do vetor sera armazenado de acordo com o indice de endereco
        scanf("%d", &vector[indice]);
    }

    printf("\n");

    for (int indice = 0; indice < 5; indice++)
    {
        // Lendo o vetor indice a indice com seus valores
        printf("Posicao %d - %d\n", indice, vector[indice]);
    }

    system("pause");
    return 0;
}