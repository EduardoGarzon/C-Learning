/*
    Funcao recursiva para somar todos os elementos de um vetor.

    Tamanho 5:
        TOPO
            vetor[1] + 0
            vetor[2] + vetor[1]
            vetor[4] + vetor[3]
        BASE
*/

#include <stdio.h>
#include <stdlib.h>

int soma_Recursiva(int vetor[], int tamanho)
{
    if (tamanho == 0)
    {
        return 0;
    }
    else
    {
        printf("vetor: %d\n", vetor[tamanho - 1]);

        return vetor[tamanho - 1] + soma_Recursiva(vetor, tamanho - 1);
    }
}

void preenche_Vetor(int vetor[])
{
    int num = 0;
    int i = 0;

    for (i = 0; i < 5; i++)
    {
        printf("Informe um valor para a posicao [%d]: ", i);
        scanf("%d", &num);
       
        vetor[i] = num;
    }
}

int main()
{
    int vetor[5];

    preenche_Vetor(vetor);

    printf("Soma recursiva dos valores do vetor: %d\n", soma_Recursiva(vetor, 5));

    system("pause");
    return 0;
}