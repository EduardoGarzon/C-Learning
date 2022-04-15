// Calculando o fatorial de um numero utilizando a estrutura while

#include <stdio.h>

int main()
{
    int contador, fatorial;

    printf("Infome um numero: ");
    scanf("%i", &fatorial);

    contador = fatorial;

    printf("%i = ", fatorial);

    while (contador != 0)
    {
        printf("%i ", contador);
        contador--;
        if (contador > 0)
        {
            fatorial *= contador;
        }
    }
    printf(" = %i", fatorial);
}