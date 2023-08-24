/* A funcao sizeof determina um numero bytes para armazenar determinado tipo de dado,
o tamanho pode variar de acordo com o tipo de compilador */

#include <stdio.h>

int main()
{
    int x = sizeof(int);
    printf("Tamanho int: %d", x);

    x = sizeof(float);
    printf("\nTamanho float: %d", x);

    x = sizeof(double);
    printf("\nTamanho double: %d", x);

    x = sizeof(char);
    printf("\nTamanho char: %d", x);

    return 0;
}