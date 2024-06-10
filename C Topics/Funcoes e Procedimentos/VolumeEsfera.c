/*
    Faça uma função e um programa de teste para o cálulo do volume de uma
    esfera. Sendo que o raio é passado por parâmetro V = 4/3 * pi * R^3.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

volume(int raio, int vl)
{
    vl = (4 * 3.14 * (pow(raio, 3))) / 3; // formula do calculo do volume da esfera
    return vl;                            // retorno do valor calculado
}

int main()
{
    int raio = 0; // variavel para o raio
    int vl = 0;   // variavel para o volume

    printf("Informe o valor do Raio da esfera: ");
    scanf("%d", &raio);
    printf("\n");

    vl = volume(raio, vl); // chamada da funcao que vai receber retorno do volume

    printf("O volume da esfera e: %d cm3\n", vl);

    system("pause");
    return 0;
}