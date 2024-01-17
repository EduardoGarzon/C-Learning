/*
    Faça um algoritmo que leia a velocidade de um veículo em km/h
    e calcule e imprima a velocidade em m/s (metros por segundo).
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float velocidade;

    printf("Informe a velocidade do carro em Km/h: ");
    scanf("%f", &velocidade); // entrada de dados;

    velocidade /= 3.6; // Conversao, velocidade em Km/h dividido por 3,6;

    printf("Velocidade de Km/h para M/s: %0.2f\n", velocidade); // saida de dados;

    system("pause");
    return 0;
}