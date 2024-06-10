// Sequencia de 0 ate 10 utilizando while

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 0;

    while (numero <= 10)
        printf("%i\n", numero++);

    system("pause");
    return 0;
}