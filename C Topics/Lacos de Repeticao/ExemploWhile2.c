/*
    Partindo de 500, imprimir os 100 primeiros números pares 
    e os 50 primeiros números ímpares.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, par, impar, cont;

    numero = 500;
    par = 0;
    impar = 0;

    printf("100 primeiros pares:\n");

    while (par < 100)
    {
        if (numero % 2 == 0)
        {
            par++;
            printf("%d PAR - %d\n", par, numero);
        }
        numero++;
    }

    printf("\n\n");
    printf("50 primeiros impares:\n");

    numero = 500;
    while (impar < 50)
    {
        if (numero % 3 == 0)
        {
            impar++;
            printf("%d IMPAR - %d\n", impar, numero);
        }
        numero++;
    }

    system("pause");
    return 0;
}