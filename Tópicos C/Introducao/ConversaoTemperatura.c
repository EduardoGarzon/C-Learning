/*
    Faça um algoritmo que leia uma temperatura em graus Celsius
    e apresente-a convertida em graus Fahrenheit.
    A fórmula de conversão é: F = (9 * C + 160) / 5,
    na qual F é a temperatura em Fahrenheit e C é a temperatura em Celsius.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float temperatura;

    printf("Informe uma temperatura em Celsius: ");
    scanf("%f", &temperatura);

    temperatura = ((9 * temperatura) + 160) / 5;

    printf("Temperatura em Celsius para Fahrenheit: %0.1f\n", temperatura);

    system("pause");
    return 0;
}