/*
    Alterando o tamanho de um vetor com realloc.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanho = 5, tamanho2;
    int *vet;

    vet = malloc(tamanho * sizeof(int));
    if (vet)
    {
        for (int i = 0; i < tamanho; i++)
        {
            vet[i] = i;
        }

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
    scanf("%d", &tamanho2);

    // vet     - vetor a ser alterado
    // tamanho - novo tamanho do vetor
    // O vetor nao é alterado e sim um novo vetor é criado como o novo tamanho e os
    // elementos do vetor antigo sao copiados para o novo
    vet = realloc(vet, tamanho2);
    if (vet)
    {
        for (int i = tamanho; i < tamanho2; i++)
        {
            vet[i] = i;
        }

        printf("Vetor Realocado:\n");
        for (int i = 0; i < tamanho2; i++)
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