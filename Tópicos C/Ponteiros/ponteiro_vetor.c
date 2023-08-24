/*
Um vetor é sempre um ponteiro. Quando passamos um vetor para funcao ou procedimento
estamos passando na verdade um apontador assim qualquer alteracao no vetor altera o vetor na main.
Sabemos que o nome do vetor aponta para sua primeira posicao ate a ultima de forma sequencial na mem.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void modifica_Vetor(int vet[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        vet[i] = vet[i] * 2;
    }
}

void imprime_Vetor(int vet[], int tam)
{
    printf("[");
    for (int i = 0; i < tam; i++)
        printf(" %d ", vet[i]);

    printf("]\n");
}

int main()
{
    srand(time(NULL));
    int vet[10];
    for (int i = 0; i < 10; i++)
    {
        vet[i] = rand() % 10;
    }

    // vetor original
    printf("Vetor original: \n");
    imprime_Vetor(vet, 10);

    modifica_Vetor(vet, 10);

    printf("Vetor modificado apod funcao: \n");
    // vetor modificado
    imprime_Vetor(vet, 10);

    system("pause");
    return 0;
}