#include <stdio.h>

int main()
{
    int a = 1, b = 0;

    printf("Valor decimal de a: %d\n", a);
    printf("\n");

    // Deslocamento à esquerda.
    // Joga fora o bit mais significativo (bit mais à esquerda),
    // acrescenta um zero à direita.
    // a == 1 == 00000001 (8 bits).
    // b = a << 1 retorna 00000010.
    b = a << 1;
    printf("Deslocamento a esquerda b = a << 1: %d\n", b);
    b = a << 2;
    printf("Deslocamento a esquerda b = a << 2: %d\n", b);

    printf("\n");

    // Deslocamento à direita.
    // Joga fora o bit menos significativo (bit mais à direita),
    // acrescenta um zero à esquerda.
    // a = 10 = 00001010 (8 bits).
    // b = a >> 1 retorna 00000101.
    a = 10;

    printf("Valor decimal de a: %d\n", a);
    printf("\n");

    b = a >> 1;
    printf("Deslocamento a direita b = a >> 1: %d\n", b);
    b = a >> 2;
    printf("Deslocamento a direita b = a >> 2: %d\n", b);
    printf("\n");

    return 0;
}