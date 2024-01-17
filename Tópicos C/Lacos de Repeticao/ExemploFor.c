// Sequencia de 1 ate 10 utilizando laco derepeticao For

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int contador;
    int numero = 0;

    for (contador = 1; contador <= 10; contador++)
    {
        numero = numero + 1;
        printf("Sequencia: %d\n", numero);
    }

    system("pause");
    return 0;
}