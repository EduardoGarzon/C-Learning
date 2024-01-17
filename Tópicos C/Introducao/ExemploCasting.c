/*
        Casting é uma operacao para alterar o tipo de um determinado valor.

        (int) 3.1415 / 3.0
        (float) 421 / 37
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a = 3.1415;
    float b = 3.0;

    int c = (int)a / b;

    printf("Float sem casting: %f \nFloat com casting para int: %d\n", (a / b), c);
    printf("Int sem casting: %d \nInt com casting para float: %f\n", (421 / 37), (float)(421 / 37));

    system("pause");
    return 0;
}