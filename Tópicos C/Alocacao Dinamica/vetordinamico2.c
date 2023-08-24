/*
    Alocacao de um vetor dinamico em C
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, tam, *vet;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tam);

    // tamanho do vetor * quantidade de memoria de um determinado tipo de dado
    vet = malloc(tam * sizeof(int)); // o ponteiro recebe o endereco da posicao inicial alocada

    if (vet)
    {
        srand(time(NULL));

        // preenchendo vetor de 0 a 10
        for (i = 0; i < tam; i++)
        {
            vet[i] = rand() % 10;
        }

        // imprimindo vetor
        for (i = 0; i < tam; i++)
        {
            printf("[%d] ", vet[i]);
        }
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
        return -1;
    }

    return 0;
}