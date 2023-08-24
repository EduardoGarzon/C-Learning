/* 4. Elabore um algoritmo que leia 20 números do teclado e os armazene em um vetor.
Em seguida, leia um número n qualquer e apresente na tela a quantidade de vezes que
o número n aparece no vetor. Se o número não estiver no vetor, informe. */

#include <stdio.h>

int main()
{
    int vetor[20];
    int numero;
    int vezes = 0;

    for (int i = 0; i < 20; i++)
    {
        printf("Informe um valor: ");
        scanf("%i", &vetor[i]);
    }

    printf("\nInforme um numero: ");
    scanf("%i", &numero);

    for (int i = 0; i < 20; i++)
    {
        if (vetor[i] == numero)
        {
            vezes++;
        }
    }
    if (vezes > 0)
    {
        printf("\nQuantidade de vezes que %i aparece no vetor: %i", numero, vezes);
    }
    else
    {
        printf("\nO numero %i nao esta no vetor.", numero);
    }
}