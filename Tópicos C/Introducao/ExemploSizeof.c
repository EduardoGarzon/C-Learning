/*
    A funcao sizeof determina um numero bytes para armazenar determinado tipo de dado,
    o tamanho pode variar de acordo com o tipo de compilador.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = sizeof(int);
    printf("Tamanho int: %d\n", x);

    x = sizeof(float);
    printf("Tamanho float: %d\n", x);

    x = sizeof(double);
    printf("Tamanho double: %d\n", x);

    x = sizeof(char);
    printf("Tamanho char: %d\n", x);

    system("pause");
    return 0;
}