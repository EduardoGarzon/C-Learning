/*
    Converter valor real para dolar.
    Considere US$ 1,0 = R$ 5,00.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float valor, conversao;

    printf("Informe o total em R$: ");
    scanf("%f", &valor);

    conversao = valor / 5.00;

    printf("R$%.2f sao US$%.2f convertidos\n", valor, conversao);

    system("pause");
    return 0;
}