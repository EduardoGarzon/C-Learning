/*
Invertendo a posicao dos elementos de um vetor com recursao
*/

#include <stdio.h>
#include <stdlib.h>

void inverte_Recursao(int vetor[], int inicio, int fim)
{
    int aux;
    if (fim > inicio)
    {
        aux = vetor[inicio];
        vetor[inicio] = vetor[fim];
        vetor[fim] = aux;
        inverte_Recursao(vetor, inicio + 1, fim - 1);
    }
}

void preenche_Vetor(int vetor[])
{
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        printf("Valor para [%d]: ", i);
        scanf("%d", &vetor[i]);
    }
    printf("\n");
}

void imprime_Vetor(int vetor[], int tamanho)
{
    if (tamanho == 1)
    {
        printf("%d ", vetor[tamanho - 1]);
    }
    else
    {
        imprime_Vetor(vetor, tamanho - 1);
        printf("%d ", vetor[tamanho - 1]);
    }
}

int main()
{
    int vetor[5];
    preenche_Vetor(vetor);
    inverte_Recursao(vetor, 0, 4);
    printf("VETOR INVERTIDO POR RECURSAO: \n");
    imprime_Vetor(vetor, 5);
    system("pause");
    return 0;
}