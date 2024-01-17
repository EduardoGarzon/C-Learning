/*
    Descobrindo maior valor de um vetor com recursao.
*/

#include <stdio.h>
#include <stdlib.h>

int maiorvalor_recursao(int vetor[], int tamanho, int maior)
{
    if (tamanho == 0)
    {
        printf("3 - vetor[%d]: %d | vetor[maior:%d]: %d\n", tamanho, vetor[tamanho], maior, vetor[maior]); // retorna o vetor com o indice que representa o maior valor

        return vetor[maior];
    }
    else
    {
        if (vetor[tamanho - 1] > vetor[maior]) // INICIO: vetor[4] > vetor[maior] (maior == 0)
        {
            printf("1 - vetor[%d]: %d | vetor[maior:%d]: %d\n", tamanho - 1, vetor[tamanho - 1], maior, vetor[maior]);

            // se for maior que o maior decrementa o indice e maior recebe o indice do novo maior
            return maiorvalor_recursao(vetor, tamanho - 1, tamanho - 1);
        }
        else
        {
            printf("2 - vetor[%d]: %d | vetor[maior:%d]: %d\n", tamanho - 1, vetor[tamanho - 1], maior, vetor[maior]);

            // senao decrementa indice e maior se mantem
            return maiorvalor_recursao(vetor, tamanho - 1, maior);
        }
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

int main()
{
    int vetor[5];

    preenche_Vetor(vetor);

    printf("Maior valor do vetor por recursao: %d\n", maiorvalor_recursao(vetor, 5, 0));

    system("pause");
    return 0;
}