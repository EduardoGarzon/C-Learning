/*
    Faça um programa para simular uma calculadora,
    onde o usuário tem a opção de calcular as 4 operações básicas,
    mais a operação de resto da divisão.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1, numero2;
    float result;

    printf("Informe um numero: ");
    scanf("%d", &numero1);

    printf("Informe outro numero: ");
    scanf("%d", &numero2);

    printf("\n");

    result = numero1 + numero2; // Soma
    printf("Soma: %0.0f\n", result);

    result = numero1 - numero2; // Subtracao
    printf("Subtracao: %0.0f\n", result);

    result = numero1 * numero2; // Multiplicacao
    printf("Multiplicacao: %0.0f\n", result);

    printf("\n");
    if (numero2 == 0)
    {
        printf("Nao e possivel dividir um numero por 0.\n");
    }
    else
    {
        result = numero1 / numero2; // Divisao
        printf("Divisao: %0.1f\n", result);

        numero1 %= numero2; // Resto da Divisao
        printf("Resto da divisao: %i\n", numero1);
    }

    system("pause");
    return 0;
}