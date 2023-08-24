/*Seja r um número entre 0 e 1 no sistema decimal e (0.d1d2...dj...)2 sua representação no sistema binário.Os dígitos d1,d2,...,dj,... são obtidos pelo algoritmo: */

#include <stdio.h>

int main()
{
    double numero = 0;
    int novo[7];
    int i = 0;
    int base = 0;

    printf("Informe a parte fracionaria do numero decimal: ");
    scanf("%lf", &numero);
    printf("Informe a base para conversao: ");
    scanf("%d", &base);

    printf("Fracao decimal convertida para base %d: ", base);
    while (numero != 0)
    {
        numero = numero * base;
        novo[i] = ((int)numero);
        if ((int)numero > 0)
        {
            numero = numero - (int) numero;
        }
        printf("%d", novo[i]);
        i++;
    }

    return 0;
}