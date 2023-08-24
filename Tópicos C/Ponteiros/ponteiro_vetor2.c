/*
Aritmetica de ponteiros com vetor.
Um vetor é um conjunto de posicoes na memoria de forma sequencial.
Nome do vetor acessa a primeira posicao, nome + 1 == segunda posicao, ...
endereco + 1 resulta no endereco seguinte, avancando na posicao do vetor.
Isso tudo pq um vetor é um ponteiro.
*/

#include <stdio.h>
#include <stdlib.h>

void imprimir_Vetor(int vet[], int tam)
{
    printf("[");
    for (int i = 0; i < tam; i++)
    {
        printf(" %d ", *(vet + i));
    }
    printf("]\n");
}

int main()
{
    int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Imprimindo vetor por meio da Aritmetica de Ponteiros: \n");
    imprimir_Vetor(vet, 10);

    system("pause");
    return 0;
}