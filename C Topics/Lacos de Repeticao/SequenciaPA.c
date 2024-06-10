/*
    Escreva um algoritmo que leia um valor inicial A
    e uma razão R e imprima uma sequência em P.A.
    contendo 10 valores.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A, B, cont, result;

    printf("Informe um valor inical A: ");
    scanf("%d", &A);

    printf("Informe uma razao R: ");
    scanf("%d", &B);

    for (cont = 0; cont <= 10; cont++)
    {
        result = ((A + (cont - 1)) / 2);
        printf("%d - Termo: %d\n", cont, result);
    }

    system("pause");
    return 0;
}