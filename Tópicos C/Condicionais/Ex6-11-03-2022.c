/* 6. Faça um algoritmo que leia a velocidade de um veículo em km/h e calcule 
e imprima a velocidade em m/s (metros por segundo). */

#include <stdio.h>

int main()
{
    float velocidade;

    printf("Informe a velocidade do carro em Km/h: ");
    scanf("%f", &velocidade); // entrada de dados;

    velocidade /= 3.6; // Conversao, velocidade em Km/h dividido por 3,6;

    printf("\nVelocidade de Km/h para M/s: %0.2f", velocidade); // saida de dados;
    return 0;
}