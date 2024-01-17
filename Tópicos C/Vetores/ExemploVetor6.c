/*
    Elabore um algoritmo que leia 20 números
    do teclado e os armazene em um vetor.

    Em seguida, leia um número n qualquer e
    apresente na tela a quantidade de vezes que
    o número n aparece no vetor.

    Se o número não estiver no vetor, informe.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[20];
    int numero;
    int vezes = 0;

    for (int i = 0; i < 20; i++)
    {
        printf("Informe um valor: ");
        scanf("%d", &vetor[i]);
    }

    printf("\n");
    printf("Informe um numero: ");
    scanf("%d", &numero);

    for (int i = 0; i < 20; i++)
    {
        if (vetor[i] == numero)
        {
            vezes++;
        }
    }

    if (vezes > 0)
    {
        printf("Quantidade de vezes que %d aparece no vetor: %d\n", numero, vezes);
    }
    else
    {
        printf("O numero %d nao esta no vetor.\n", numero);
    }

    system("pause");
    return 0;
}