/* 3. Usando recursividade, calcule a soma de todos os valores de um vetor
de tamanho definido pelo usuário de reais. */

#include <stdio.h>
#include <stdlib.h>

float somar(float vetor[], int tamanho, float soma)
{
    if (tamanho == 0) // soma os valores ate o indice ficar menor que 0;
    {
        return soma;
    }
    else
    {
        soma += vetor[tamanho - 1];
        return (somar(vetor, tamanho - 1, soma));
    }
}

int main()
{
    float *vetor;    // variavel ponteiro para o vetor dinamico de numeros reais
    int tamanho = 0; // variavel para o tamanho do vetor
    float soma = 0;  // variavel para soma dos valores do vetor

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);                   // lendo o tamanho do vetor
    vetor = malloc(tamanho * sizeof(float)); // alocando vetor de reais

    for (int i = 0; i < tamanho; i++) // lendo valores para o vetor
    {
        printf("Informe um numero real para [%d]: ", i);
        scanf("%f", &vetor[i]);
    }
    printf("%f", somar(vetor, tamanho, soma)); // chamada da funcao recursiva

    free(vetor);
    return 0;
}