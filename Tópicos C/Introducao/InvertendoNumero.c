// Invertendo um numero utilizando o resto da divisao.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, X;

    printf("Informe um numero inteiro positivo ou negativo: ");
    scanf("%d", &numero);

    printf("Numero invertido: ");

    if (numero >= 0)
    {
        do
        {
            X = numero % 10;
            printf("%i", X);
            numero /= 10;
        } while (numero != 0);
    }
    else if (numero < 1)
    {
        numero *= -1;
        printf("-");

        do
        {
            X = numero % 10;
            printf("%i", X);
            numero /= 10;
        } while (numero != 0);
    }

    system("pause");
    return 0;
}