/*
    Escrever um algoritmo que leia um valor
    para uma variável N de 1 a 10 e calcule a
    tabuada de N.
    Mostre a tabuada na forma: 0 x N = 0, 1 x N = 1N, 2 x N = 2N, ..., 10 x N = 10N
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, cont, result;

    printf("Informe um numero entre 1 e 10: ");
    scanf("%d", &numero);

    for (cont = 1; cont <= 10; cont++)
    {
        result = numero * cont;
        printf("%i X %i = %i\n", numero, cont, result);
    }

    system("pause");
    return 0;
}