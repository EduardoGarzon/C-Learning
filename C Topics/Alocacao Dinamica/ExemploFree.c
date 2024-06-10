/*
    Liberando Memoria Alocada em C.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int *vet, tamanho = 5;

    vet = (int *)malloc(tamanho * sizeof(int));

    if (vet)
    {
        printf("Vetor Alocado:");
        for (int i = 0; i < tamanho; i++)
        {
            vet[i] = rand() % 10;
            printf("[%d] ", vet[i]);
        }
        printf("\n");

        printf("Tecle [ENTER] para liberar a memoria do vetor alocado...");
        getchar();

        free(vet); // libera memoria alocada
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
        return -1;
    }

    system("pause");
    return 0;
}