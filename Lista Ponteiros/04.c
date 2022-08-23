/* 4. Crie um programa que contenha uma função que permita passar por parâmetro dois
números inteiros A e B. A função deverá calcular a soma entre estes dois números e
armazenar o resultado na variável A. Esta função não deverá possuir retorno, mas deverá
modificar o valor do primeiro parâmetro. Imprima os valores atualizados de A e B na
função principal. */

#include <stdio.h>

int soma(int *a, int *b) // ponteiros recebem o parametro por referencia
{
    *a = *a + *b; // soma
}

int main()
{
    int a = 0, b = 0;

    printf("Informe um valor para A: ");
    scanf("%d", &a);
    printf("Informe um valor para B: ");
    scanf("%d", &b);

    printf("\nSoma entre A:%d e B:%d", a, b);
    soma(&a, &b); // parametros referenciando o endereco das variaveis
    printf("\nResultado - A: %d", a);
    printf("\nValor de B: %d", b);

    return 0;
}