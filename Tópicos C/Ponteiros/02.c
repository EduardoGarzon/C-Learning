/* 2. Escreva um programa que contenha duas variáveis inteiras. Compare o endereço de
ambas e exiba o maior. */

#include <stdio.h>

int main()
{
    int valor1 = 10;
    int valor2 = 20;

    int *v1 = &valor1;
    int *v2 = &valor2;

    printf("\nEndereco do ponteiro v1: %x", v1);
    printf("\nValor da variavel apontada: %d", *v1);
    printf("\n");
    printf("\nEnderedo do ponteiro v2: %x", v2);
    printf("\nValor da variavel apontada: %d", *v2);
    printf("\n");

    if (v1 > v2) // comparando qual endereco e o maior
    {
        printf("\nMaior endereco de memoria: ponteiro v1");
    }
    else if (v1 < v2)
    {
        printf("\nMaior endereco de memoria: ponterio v2");
    }
    else
    {
        printf("Erro.");
    }

    return 0;
}