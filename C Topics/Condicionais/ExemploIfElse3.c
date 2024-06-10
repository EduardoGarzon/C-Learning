// Elabore um algoritmo que leia 3 números inteiros, identifique e imprima o maior deles.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, maior;

    printf("Informe um numero inteiro positivo: ");
    scanf("%d", &numero);

    maior = numero;

    printf("Informe outro numero: ");
    scanf("%d", &numero);

    if (numero >= maior)
    {
        maior = numero;
    }

    printf("Informe outro numero: ");
    scanf("%i", &numero);

    if (numero >= maior)
    {
        maior = numero;
    }

    printf("Maior numero informado: %d", maior);

    system("pause");
    return 0;
}
