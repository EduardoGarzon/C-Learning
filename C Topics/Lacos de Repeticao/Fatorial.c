// Calculando o fatorial de um numero utilizando a estrutura while

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador, fatorial;

    printf("Infome um numero: ");
    scanf("%d", &fatorial);

    contador = fatorial;

    printf("%d = ", fatorial);

    while (contador != 0)
    {
        printf("%d ", contador);
        contador--;
        if (contador > 0)
        {
            fatorial *= contador;
        }
    }
    printf(" = %d", fatorial);

    system("pause");
    return 0;
}