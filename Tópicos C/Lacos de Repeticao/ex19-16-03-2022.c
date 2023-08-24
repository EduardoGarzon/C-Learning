/* 19) Escreva um algoritmo que leia um valor inicial A e uma razão R
e imprima uma sequência em P.A. contendo 10 valores. */

#include <stdio.h>

int main()
{
    int A, B, cont, result;

    printf("Informe um valor inical A: ");
    scanf("%i", &A);

    printf("Informe uma razao R: ");
    scanf("%i", &B);

    for (cont = 0; cont <= 10; cont++)
    {
        result = ((A + (cont - 1)) / 2);
        printf("\n%i - Termo: %i\n", cont, result);
    }

    return 0;
}