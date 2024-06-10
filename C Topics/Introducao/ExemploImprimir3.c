#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Hexa; // Variaveis do tipo inteiro.
    int octal = 100;
    Hexa = 0x1FA;

    // Hexadecimal para Decimal.
    printf("Numero Decimal: %d | Numero Hexadecimal: %x.\n", Hexa, Hexa);
    // Decimal para Octal.
    printf("Numero Decimal: %d | Numero Octal: %o.\n", octal, octal);

    system("pause");
    return 0;
}
