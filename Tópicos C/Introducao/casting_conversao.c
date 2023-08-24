#include <stdio.h>

int main()
{
    /*
        Casting é uma operacao para alterar o tipo de um determinado valor

        (int) 3.1415 / 3.0
        (float) 421 / 37
    */

    float a = 3.1415;
    float b = 3.0;

    int c = (int)a / b;

    printf("float sem casting: %f \nfloat com casting para int: %d\n", (a / b), c);
    printf("int sem casting: %d \nint com casting para float: %f\n", (421 / 37), (float)(421 / 37));

    return 0;
}