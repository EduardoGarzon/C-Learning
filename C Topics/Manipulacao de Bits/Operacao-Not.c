#include <stdio.h>

int main()
{
    // Operador NOT (~)
    // Nega o valor de cada bit.
    // 1 == ~00000001 = 11111110 == -2

    // Complemento de 2
    // Método para encontrar o equivalente negativo em binário de um valor positivo.

    // 1. Escrever o valor positivo em binário.
    // 2. Inverter seus bits.
    // 3. Somar mais 1.

    // 1. 2 == 00000010
    // 2. 00000010 = 11111101
    // 3. 11111101 = 11111110 == -2

    int a = 0, b = 0;

    a = 1;
    b = ~a;
    printf("Valor de a: %d\n", a);
    printf("Valor negado de a: %d\n", b);

    printf("\n");

    a = 10;
    b = ~a;
    printf("Valor de a: %d\n", a);
    printf("Valor negado de a: %d\n", b);

    printf("\n");

    a = 100;
    b = ~a;
    printf("Valor de a: %d\n", a);
    printf("Valor negado de a: %d\n", b);

    return 0;
}