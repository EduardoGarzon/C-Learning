/*
    Exercicio 04 - Calculando o valor a ser pago para o encanador
    Custo diario de R$45,00 para o encanador trabalhar
    8% de desconto para a receita
    Retornar o valor gasto de acordo com os dias trabalhados
*/

#include <stdio.h>

int main()
{
    float custo, dias, desconto;

    printf("Informe a quantide de dias trabalhados pelo encanador: ");
    scanf("%f", &dias);
    printf("\n");

    custo = dias * 45.00;
    desconto = (8 / 100) * custo;
    custo -= desconto;

    printf("Desconto da receita: %.2f\n", desconto);
    printf("Valor final considerando diaria de R$45.00: %.2f\n", custo);

    return 0;
}