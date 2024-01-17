/*
    Utiliza o método de divisão e conquista para acelerar o tempo médio de busca.
    Somente pode ser aplicado a conjuntos ordenados.

    O primeiro elemento a ser testado é o elemento central do conjunto.
    Se o elemento procurado for igual, retorna-se o valor da posição do elemento central,
    caso contrário, verifica-se duas outras situações:
        1. O elemento procurado é menor que o elemento central:
           a busca deverá prosseguir na metade inferior ao elemento central.
        2. O elemento procurado é maior que o elemento central:
           a busca deverá prosseguir na metade superior ao elemento central.
        3. O procedimento deve ser chamado recursivamente para a metade apropriada.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 20

void inicializarVetor(int vector[])
{
    for (int i = 0; i < TAM; i++)
    {
        vector[i] = i;
    }
}

void imprimirVetor(int vector[])
{
    for (int i = 0; i < TAM; i++)
    {
        printf("Posicao: %d | Conteudo: %d\n", i, vector[i]);
    }
}

int binSearch(int vector[], int dado)
{
    int lower = 0;
    int higher = TAM - 1; // Inicializar higher com o índice correto do último elemento
    int i = 0;

    while (lower <= higher)
    {
        i = (lower + higher) / 2; // Calculo da posicao central

        if (vector[i] == dado) // valor central igual valor procurado?
        {
            return i; // Encontrou a posição do elemento
        }
        if (dado < vector[i]) // Dado menor que o valor central?
        {
            higher = i - 1; // Pesquisa na metade esquerda
        }
        else
        {
            lower = i + 1; // Pesquisa na metade direita
        }
    }

    return -1; // Nao encontrou o elemento
}

int main()
{
    int vector[TAM], dado, retorno;

    inicializarVetor(vector);

    printf("\tInforme o valor que deseja procurar no vetor: ");
    scanf("%d", &dado);

    imprimirVetor(vector);

    retorno = binSearch(vector, dado);

    if (retorno != -1)
    {
        printf("\t\nElemento encontrado na posicao: %d\n", retorno);
    }
    else
    {
        printf("\t\nElemento nao encontrado!\n");
    }

    system("pause");
    return 0;
}
