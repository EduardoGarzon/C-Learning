/*
    Escreva um programa que contenha duas variáveis inteiras.
    Leia essas variáveis do teclado.
    Em seguida, compare seus endereços e exiba o conteúdo do maior endereço
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor1 = 0, valor2 = 0;
    int *v1 = &valor1;
    int *v2 = &valor2;

    printf("Informe o conteudo da variavel 1: ");
    scanf("%d", v1);

    printf("Informe o conteudo da variavel 2: ");
    scanf("%d", v2);

    printf("\n");

    if (v1 > v2) // comparando enderecos
    {
        printf("Maior endereco - v1: %x\n", v1);
        printf("Valor: %d\n", *v1);
    }
    else if (v2 > v1)
    {
        printf("Maior endereco - v2: %x\n", v2);
        printf("Valor: %d\n", *v2);
    }

    system("pause");
    return 0;
}