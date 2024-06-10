/*
    Crie um vetor VET com 15 posições.
    Leia 14 valores e armazene em VET.
    Leia um valor X.
    Inclua o valor X na primeira posição do vetor VET
    fazendo com que os elementos existentes dentro do vetor
    sejam deslocados em uma posição para o final.

    Logo após o processamento, escrever o vetor VET.

    Exemplo: VET= 1 3 2 7 5 9...;
             X=15;
            VET final = 15 1 3 2 7 5 9...
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[15], x = 0;

    for (int i = 0; i < 14; i++)
    {
        printf("Informe um valor: ");
        scanf("%d", &vetor[i]);
    }

    printf("\n");
    printf("Vetor inicial:\n");
    for (int i = 0; i < 14; i++)
    {
        printf("%d ", vetor[i]);
    }

    printf("\n");
    printf("Informe o valor X: ");
    scanf("%d", &x);

    for (int i = 14; i > 0; i++)
    {
        vetor[i] = vetor[i - 1];
    }

    vetor[0] = x;

    printf("Vetor final:\n");
    for (int i = 0; i <= 14; i++)
    {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    system("pause");
    return 0;
}