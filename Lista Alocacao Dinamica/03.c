/* 3. Faça um programa que leia do usuário o tamanho de um vetor a ser utilizado e faça a
alocação dinâmica de memória. Em seguida, leia do usuário seus valores e mostre quantos dos
números são pares e quantos são ímpares. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *x; // variavel ponteiro do tipo int
    int tamanho = 0, pares = 0, impares = 0, i = 0;

    printf("Informe o tamanho da alocacao: "); // lendo o tamanhoa a ser alocado
    scanf("%d", &tamanho);
    x = (int *)malloc(tamanho * sizeof(int)); // alocando espacos dado o tamanho informado

    for (i = 0; i < tamanho; i++) // leitura dos valores para os espacos alocados
    {
        printf("Informe um valor para a posicao [%d]: ", i);
        scanf("%d", &x[i]);
        if (x[i] % 2 == 0)
        {
            pares++; // verificando se o numero e par
        }
        else
        {
            impares++; // numero e impar caso nao seja par
        }
    }

    printf("\nValores Pares e Impares: \n");
    printf("Total de pares: %d\n", pares);
    printf("Total de impares: %d\n", impares);

    free(x);

    return 0;
}