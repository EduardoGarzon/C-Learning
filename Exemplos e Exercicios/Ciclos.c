/*  Alguns tipos de variáveis não aceitam modificadores de tipos:
    Int - Aceita todos
    Char - Somente unsigned e signed
    Double - Somente long
    Float - Não aceita modificadores
    -------------------------------------------------------------
    #define PI 3.14
    const float PI = 3.14;
    -------------------------------------------------------------
    unsigned - sem sinal */

#include <stdio.h>

int main()
{
    int result = 0;

    for (int i = 0; i <= 10; i++)
    {
        printf("Tabuada do %i:\n", i);
        for (int num = 1; num <= 10; num++)
        {
            result = num * i;
            printf("%i X %i = %i\n", i, num, result);
        }
        printf("\n");
    }
    return 0;
}