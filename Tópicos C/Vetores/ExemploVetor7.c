/*
    Faça um programa que leia um vetor de 10 números
    inteiros positivos e negativos.

    Some separadamente os positivos e os negativos e,
    no final, imprima todo o vetor original e as somas
    correspondentes.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[10];
    int positivo = 0;
    int negativo = 0;

    for (int i = 0; i <= 9; i++)
    {
        printf("Informe um numero inteiro positivo ou negativo: ");
        scanf("%d", &vetor[i]);

        if (vetor[i] >= 0)
        {
            positivo += vetor[i];
        }
        else
        {
            negativo += vetor[i];
        }
    }

    printf("\n");
    printf("Vetor na ordem: \n");
    for (int i = 0; i <= 9; i++)
    {
        printf("Posicao %d - Valor: %d\n", i, vetor[i]);
    }

    printf("\n");
    printf("Soma dos valores positivos: %d\n", positivo);
    printf("Soma dos negativos: %d\n", negativo);

    system("pause");
    return 0;
}