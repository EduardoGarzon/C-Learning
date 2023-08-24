#include <stdio.h>

int main()
{
    /*
        o tipo double tem o dobro da capacidade de um float, ou seja,
        float tem 32 bits (4 bytes) e double 64 bits (8 bytes).

        long double para 16 bytes ou 128 bits

        %Lf para imprimir o valor long double (sem estar no windows)

        Funcao do compilador para imprimir numero grande no  windows __mingw_printf("%Lf\n", valor);

    */

    double x;
    long double y;

    int a = sizeof x;
    int b = sizeof y;

    printf("Double: %d \nLong Double: %d\n", a, b);

    return 0;
}