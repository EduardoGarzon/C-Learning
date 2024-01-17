// Escrevendo os caracteres e seu codigo equivalente em ASCII.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    setlocale();

    char caractere;

    printf("Informe um caractere: ");
    scanf("%c", &caractere);

    printf("Caractere: %c | ASCII: %d\n", caractere, caractere);

    system("pause");
    return 0;
}