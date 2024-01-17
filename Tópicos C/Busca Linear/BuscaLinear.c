/*
    Implementacao de um algortimo de busca linear.

    Trata-se de uma varredura realizada de modo sequencial,
    elemento por elemento, dentro de um determinado conjunto
    com objetivo de encontrar um determinado valor.

    Deve retornar a posição do elemento procurado dentro do conjunto,
    ou -1 caso o mesmo não se encontre no conjunto.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 50

void inicializarVector(int vector[])
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        vector[i] = i;
    }
}

// Algoritmo de busca sequencial
int serSearch(int value, int dados[])
{
    for (int i = 0; i < TAM; i++)
    {
        if (dados[i] == value)
        {
            return i; // Retorna a posição do elemento encontrado
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

void printarVetor(int vector[])
{
    for (int i = 0; i < TAM; i++)
    {
        printf("Posicao: %d == Valor: %d\n", i, vector[i]);
    }
}

int main()
{
    int vector[TAM], value;

    inicializarVector(vector);

    printf("\tInforme o valor que deseja procurar no vetor: ");
    scanf("%d", &value);

    printarVetor(vector);

    int retorno = serSearch(value, vector);
    if (retorno != -1)
    {
        printf("\t\nElemento encontrado na posição %d!\n", retorno);
    }
    else
    {
        printf("\t\nElemento nao encontrado!\n");
    }

    system("pause");
    return 0;
}
