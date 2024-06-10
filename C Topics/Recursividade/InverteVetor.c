/*
    Dado um vetor de inteiros e o seu número de elementos,
    inverta a posição dos seus elementos.
*/

#include <stdio.h>
#include <stdlib.h>

int inverter(int vetor[], int tamanho, int i, int aux)
{
    if (tamanho <= i)
    {
        return vetor;
    }
    else
    {
        aux = vetor[tamanho]; // troca os valores do vetor com uma variavel auxiliar e 2 indices
        vetor[tamanho] = vetor[i];
        vetor[i] = aux;

        inverter(vetor, tamanho - 1, i + 1, aux);
    }
}

int main()
{
    int *vetor; // poteiro para alocar o vetor de inteiros
    int i = 0, j = 0, aux = 0;
    int tamanho = 0; // tamanho do vetor

    printf("Informe o tamanho do vetor de inteiros: ");
    scanf("%d", &tamanho); // leitura do tamanho do vetor

    vetor = malloc(tamanho * sizeof(int)); // alocando o vetor para os inteiros

    for (i = 0; i < tamanho; i++)
    {
        printf("Informe um valor inteiro para [%d]: ", i);
        scanf("%d", &vetor[i]); // leitura dos valores inteiros
    }

    j = tamanho;  // j recebe o tamanho do vetor para usar posteriormente
    tamanho -= 1; // tamanho decrementa 1 pois o vetor inicia em 0
    i = 0;        // zera i novamente para a funcao inverter

    inverter(vetor, tamanho, i, aux); // chamada da funcao recursiva para inverter

    printf("\n");

    for (i = 0; i < j; i++)
    {
        printf("[%d] ", vetor[i]); // imprimindo os valores do vetor
    }

    free(vetor);

    system("pause");
    return 0;
}