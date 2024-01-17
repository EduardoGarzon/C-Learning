#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Garante que o valor da variavel sera constante.
    // Ocasiona erro caso uma nova atribuicao seja realizada.
    const float PI = 3.141592;

    // PI = 123.123; // ERRO

    printf("Pi: %f\n", PI);

    system("pause");
    return 0;
}