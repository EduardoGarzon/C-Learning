/* 12. Faça um programa para simular uma calculadora, onde o usuário tem a opção de calcular as 4 operações
básicas, mais a operação de resto da divisão. */

#include <stdio.h>

int main()
{
    int numero1, numero2;
    float result;

    printf("Informe um numero: ");
    scanf("%i", &numero1);
    printf("Informe outro numero: ");
    scanf("%i", &numero2);

    result = numero1 + numero2; // Soma
    printf("\nSoma: %0.0f", result);

    result = numero1 - numero2; // Subtracao
    printf("\nSubtracao: %0.0f", result);

    result = numero1 * numero2; // Multiplicacao
    printf("\nMultiplicacao: %0.0f", result);

    if (numero2 == 0)
    {
        printf("\nNao e possivel dividir um numero por 0");
    }
    else
    {
        result = numero1 / numero2; // Divisao
        printf("\nDivisao: %0.1f", result);
        numero1 %= numero2; // Resto da Divisao
        printf("\nResto da divisao: %i", numero1);
    }
    return 0;
}