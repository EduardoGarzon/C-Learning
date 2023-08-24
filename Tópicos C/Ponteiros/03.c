/* 3. Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis do
teclado. Em seguida, compare seus endereços e exiba o conteúdo do maior endereço */

#include <stdio.h>

int main()
{
    int valor1 = 0, valor2 = 0;
    int *v1 = &valor1;
    int *v2 = &valor2;

    printf("\nInforme o conteudo da variavel 1: ");
    scanf("%d", v1);

    printf("\nInforme o conteudo da variavel 2: ");
    scanf("%d", v2);

    if (v1 > v2) // comparando enderecos
    {
        printf("\nMaior endereco - v1: %x", v1);
        printf("\nValor: %d", *v1);
    }
    else if (v2 > v1)
    {
        printf("\nMaior endereco - v2: %x", v2);
        printf("\nValor: %d", *v2);
    }

    return 0;
}