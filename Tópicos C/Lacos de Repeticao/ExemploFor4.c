/*
    Faça um algoritmo que imprima todos os números pares
    compreendidos entre 85 e 907. O algoritmo deve também
    calcular a soma destes valores.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador, soma;
    soma = 0;

    for (contador = 85; contador < 907; contador++)
    {
        if (contador % 2 == 0)
        {
            printf("PAR - %i\n", contador);
            soma += contador;
        }
    }
    printf("\n\n");
    printf("Soma dos valores pares de 85 ate 907: %d\n", soma);

    system("pause");
    return 0;
}