/*
    Crie um programa que contenha uma função que
    permita passar por parâmetro dois números inteiros A e B.

    A função deverá calcular a soma entre estes dois números e
    armazenar o resultado na variável A.

    Esta função não deverá possuir retorno,
    mas deverá modificar o valor do primeiro parâmetro.

    Imprima os valores atualizados de A e B na função principal.
*/

#include <stdio.h>
#include <stdlib.h>

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

    printf("\n");
    printf("Soma entre A:%d e B:%d\n", a, b);

    soma(&a, &b); // parametros referenciando o endereco das variaveis

    printf("\n");
    printf("Resultado - A: %d\n", a);
    printf("Valor de B: %d\n", b);

    system("pause");
    return 0;
}