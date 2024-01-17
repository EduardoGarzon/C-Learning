/*
    Faça um algoritmo que leia dois vetores de 10 elementos do teclado
    e verifique se eles são iguais ou não.

    Para serem iguais, todos os elementos dos dois vetores devem coincidir,
    nas mesmas posições.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[10], vetor2[10];
    int flag = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Informe um valor para o vetor 1: ");
        scanf("%d", &vetor[i]);
    }

    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf("Informe um valor para o vetor 2: ");
        scanf("%d", &vetor2[i]);

        if (vetor2[i] == vetor[i])
        {
            flag = 1;
        }
    }

    printf("\n");

    if (flag == 1)
    {
        printf("Os vetores sao iguais.\n");
    }
    else
    {
        printf("Os vetores sao diferentes.\n");
    }

    system("pause");
    return 0;
}