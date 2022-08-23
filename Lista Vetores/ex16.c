/* 16. Crie um vetor VET com 15 posições. Leia 14 valores e armazene em VET. Leia um valor X.
Inclua o valor X na primeira posição do vetor VET fazendo com que os elementos existentes
dentro do vetor sejam deslocados em uma posição para o final.
Logo após o processamento, escrever o vetor VET.
Exemplo: VET= 1 3 2 7 5 9...;  X=15;  VET final = 15 1 3 2 7 5 9... */

#include <stdio.h>

int main()
{
    int vetor[15];

    for (int i = 1; i < 15; i++)
    {
        printf("Informe um valor: ");
        scanf("%i", &vetor[i]);
    }

    printf("\nVetor inicial: \n");
    for (int i = 1; i < 15; i++)
    {
        printf("%i\n", vetor[i]);
    }

    printf("Informe o valor X: ");
    scanf("%i", &vetor[0]);

    printf("\nVetor final:\n");
    for (int i = 0; i < 15; i++)
    {
        printf("%i\n", vetor[i]);
    }

    return 0;
}