// Sequencia de 1 ate 10 utilizando laco derepeticao For

#include <stdio.h>

int main()
{
    int contador;
    int numero = 0;

    for (contador = 1; contador <= 10; contador++)
    {
        numero = numero + 1;
        printf("Sequencia: %i\n", numero);
    }
}