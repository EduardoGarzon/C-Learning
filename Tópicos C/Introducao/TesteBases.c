/* Variaveis */

#include <stdio.h>

int main()
{
    int Hexa; // Variaveis do tipo inteiro.

    int octal = 100;
    Hexa = 0x1FA;

    printf("Numero Decimal: %d | Numero Hexadecimal : %x.\n", Hexa, Hexa); // Hexadecimal para Decimal.
    printf("Numero Decimal: %d | Numero Octal: %o.\n", octal, octal);      // Decimal para Octal.

    return 0;
}
