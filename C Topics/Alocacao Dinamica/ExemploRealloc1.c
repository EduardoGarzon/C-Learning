/*
    Alterando o tamanho de um vetor com realloc.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randVet(int *vet, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        *(vet + i) = rand() % 10;
    }
}

int main()
{
    srand(time(NULL));

    int tamanho, *vet;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vet = malloc(tamanho * sizeof(int));
    if (vet)
    {
        randVet(vet, tamanho);

        printf("Vetor Alocado:\n");
        for (int i = 0; i < tamanho; i++)
        {
            printf("[%d] ", vet[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
    }

    printf("Informe o novo tamanho do vetor: ");
    scanf("%d", &tamanho);

    // vet     - vetor a ser alterado
    // tamanho - novo tamanho do vetor
    // O vetor nao é alterado e sim um novo vetor é criado como o novo tamanho e os
    // elementos do vetor antigo sao copiados para o novo
    vet = realloc(vet, tamanho);
    if (vet)
    {
        printf("Vetor Realocado:\n");
        for (int i = 0; i < tamanho; i++)
        {
            printf("[%d] ", vet[i]);
        }
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
    }

    system("pause");
    return 0;
}