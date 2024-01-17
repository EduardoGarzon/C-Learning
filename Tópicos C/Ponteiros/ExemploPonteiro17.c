/*
    Escreva um programa que contenha duas variáveis inteiras.
    Compare o endereço de ambas e exiba o maior.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor1 = 10;
    int valor2 = 20;

    int *v1 = &valor1;
    int *v2 = &valor2;

    printf("\n");
    printf("Endereco do ponteiro v1: %x\n", v1);
    printf("Valor da variavel apontada: %d\n", *v1);

    printf("\n");
    printf("Endereco do ponteiro v2: %x\n", v2);
    printf("Valor da variavel apontada: %d\n", *v2);
    printf("\n");

    if (v1 > v2) // comparando qual endereco e o maior
    {
        printf("Maior endereco de memoria: ponteiro v1\n");
    }
    else if (v1 < v2)
    {
        printf("Maior endereco de memoria: ponterio v2\n");
    }
    else
    {
        printf("Erro.\n");
    }

    system("pause");
    return 0;
}