/*
    Calcular e escrever a soma dos números ímpares compreendidos entre 100 e 200.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, soma;

    for (numero = 100; numero <= 200; numero++)
    {
        if ((numero % 3) == 0)
        {
            soma = soma + numero;
        }
    }

    printf("Soma dos numeros impares entre 100 e 200: %d\n", soma);

    system("pause");
    return 0;
}
