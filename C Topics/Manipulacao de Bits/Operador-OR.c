#include <stdio.h>

int main()
{
    // Operador OR (|) bit a bit

    int a = 0, b = 0, c = 0;
    a = 30;    // 0000.0000.0001.1110
    b = 19;    // 0000.0000.0001.0011
    c = a | b; // 0000.0000.0001.1111 = 31

    printf("Valor de a: %d e valor de b: %d\n", a, b);
    printf("Valor da operacao OR c = a | b: %d\n", c);
    printf("\n");

    // O operador || é diferente pois não compara bit a bit.
    // O operador compara se os valores são diferentes de nulo, ou seja, não zeros.
    // Retorna 0 apenas se ambos os valores forem nulos.

    // APLICACOES

    // Ativando um Bit

    // Colocar o bit 2 em 1 de uma determinada sequencia xxxx.xxxx
    // Basta criar uma mascara colocando 1 nas posicoes que queremos ativar. xxx1.xxxx

    a = 1;            // 0000.0001
    b = a | (1 << 2); // 0000.0101
    
    printf("Ativando um Bit:\n");
    printf("Valor de a: %d\n", a);
    printf("Resultado da operacao b = a | (1 << 2): %d\n", b);
    printf("\n");

    return 0;
}