#include <stdio.h>

int main()
{
    // Operador AND (&) bit a bit
    // A operacao é realizada sobre cada bit.
    // No resultado final cada bit sera 1 apenas se ambos os bits da operacao forem 1.

    // O operador && nao é bit a bit.
    // Verifica se os valores não são nulos, ou seja, diferentes de zero.
    // Retorna 1 caso não seja nulo e 0 para nulo.

    int a, b, c;

    a = 30;    // 0000.0000.0001.1110
    b = 19;    // 0000.0000.0001.0011
    c = a & b; // 0000.0000.0001.0010 == 18

    printf("Valor de a: %d e valor de b: %d\n", a, b);
    printf("Valor da operacao a & b: %d\n", c);
    printf("\n");

    // ALGUMAS APLICACOES

    // Testando bits usando máscara.
    // Descobrir se o quarto bit de um determiando valor é 1.

    a = 73;           // 01001001
    b = a & (1 << 3); // Máscara para testar se o quarto bit é 1. (direita para esquerda).

    printf("Determinando se o quarto bit do valor %d e 1.\n", a);
    printf("Operacao b = a & 1 << 3: %d\n", b); // 00001000
    printf("\n");

    // Descobrir se um numero é par ou ímpar.
    // Todo valor binário par tem o bit menos significativo igual a zero.

    // (2) 00000010 & 00000001 = 00000000 PAR
    // (3) 00000011 & 00000001 = 00000001 IMPAR

    a = 2;
    if (a & 1)
    {
        printf("O valor %d e impar!\n", a);
    }
    else
    {
        printf("O valor %d e par!\n", a);
    }

    // Limpando um bit

    // Limpando o quinto bit de um valor.
    // xxxx.xxxx -> xxx0.xxxx
    
    // 1. Criar uma mascára marcando o bit que deve ser 
    //    limpo com 0 e os demais com 1. (1110.1111)
    // 2. Realizar deslocamento ate o quinto bit e inserir 1.
    //    xxx1.xxxx -> 0001.0000
    // 3. Negar o retorno do deslocamento.
    //    0001.0000 -> 1110.1111 (máscara)
    
    a = 25;              // 0001.1001
    b = a & (~(1 << 4)); // 0000.1001
    
    printf("Limpando o quinto bit do valor %d\n", a);
    printf("Resultado da operacao b = a & (~(1 << 4)): %d\n", b);
    printf("\n");

    return 0;
}