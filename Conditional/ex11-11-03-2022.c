// 11. Elabore um algoritmo que leia 3 números inteiros, identifique e imprima o maior deles.

#include <stdio.h>

int main()
{
    int numero, maior;

    printf("Informe um numero inteiro positivo: ");
    scanf("%i", &numero);

    maior = numero;

    printf("Informe outro numero: ");
    scanf("%i", &numero);

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

    printf("Maior numero informado: %i", maior);
    return 0;
}
