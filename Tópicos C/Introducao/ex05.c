/*
    Exercicio 05 - Converter valor real para dolar
    Considere US$ 1,0 = R$ 5,00
*/

#include <stdio.h>

int main()
{
    float valor, conversao;

    printf("Informe o total em R$: ");
    scanf("%f", &valor);

    conversao = valor / 5.00;

    printf("R$%.2f sao US$%.2f convertidos\n", valor, conversao);

    return 0;
}