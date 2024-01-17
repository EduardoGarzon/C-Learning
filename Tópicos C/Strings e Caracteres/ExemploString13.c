/*
    Utilizando strncpy
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[5];
    char teste[10] = {"Luiz"};

    // (destino, source, qtd)
    // Copia n caracteres da string de origem para a string destino
    strncpy(string, teste, 4);
    printf("%s\n", string);

    system("pause");
    return 0;
}
