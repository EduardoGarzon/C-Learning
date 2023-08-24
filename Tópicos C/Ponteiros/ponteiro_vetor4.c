/*
Imprimir o endereco e conteudo de cada posicao de um vetor.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // vet + i percorre cada endereco do vetor
    // *(vet + i) percorre cada elemento do vetor por aritmetica de ponteiros
    for (int i = 0; i < 10; i++)
    {
        printf("Endereco da posicao [%d] do vetor: %p\n", i, vet + i);
        printf("Conteudo da posicao [%d] do vetor: %d\n\n", i, *(vet + i));
    }

    system("pause");
    return 0;
}