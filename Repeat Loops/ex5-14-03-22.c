/* 05) Faça um algoritmo que imprima todos os números pares compreendidos entre 85 e 907.
O algoritmo deve também calcular a soma destes valores. 14/03/2022 */

#include <stdio.h>

int main()
{
    int contador, soma;
    soma = 0;

    for (contador = 85; contador < 907; contador++)
    {
        if (contador % 2 == 0)
        {
            printf("\nPAR - %i", contador);
            soma += contador;
        }
    }
    printf("\n\nSoma dos valores pares de 85 ate 907: %i", soma);
    return 0;
}