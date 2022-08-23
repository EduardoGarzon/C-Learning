/* 6. Faça um algoritmo que leia dois vetores de 10 elementos do teclado e verifique
se eles são iguais ou não. Para serem iguais, todos os elementos dos dois vetores devem coincidir,
nas mesmas posições. */

#include <stdio.h>

int main()
{
    int vetor[10], vetor2[10];
    int flag = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Informe um valor para o vetor 1: ");
        scanf("%i", &vetor[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Informe um valor para o vetor 2: ");
        scanf("%i", &vetor2[i]);
        if (vetor2[i] == vetor[i])
        {
            flag = 1;
        }
    }

    if (flag == 1)
    {
        printf("Os vetores sao iguais.");
    }
    else
    {
        printf("Os vetores sao diferentes.");
    }

    return 0;
}