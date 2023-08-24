#include <stdio.h>

int main()
{
    /*
        O operador unsigned pode ser aplicado em variaveis int com os prefixos long e short tambem

        Uma variavel do tipo int de 4 bytes (32 bits),
        ou seja 2^32, nas arquiteturas atuais compreende em uma regiao separada de memoria
        um intervalo de inteiros que pode ir de -2.147.483.648 ate 2.147.483.648

        unsigned permite valores sem sinal a partir de 0, aumentando a capacidade de armazenamento dos valores

        unsigned int       - 0 ate 4.294.967.295 - %u para imprimir
        unsigned short int - 0 ate 65.535        - %hu para imprimir
        unsigned long int  - 0 ate 4.294.967.295 - %lu para imprimir

    */

    unsigned int w;
    unsigned short int x;
    unsigned long int y;
    unsigned long long int z;

    int a = sizeof w;
    int b = sizeof x;
    int c = sizeof y;
    int d = sizeof z;

    printf("unsigned int: %d\n", a);
    printf("unsigned short int: %d\n", b);
    printf("unsigned long int: %d\n", c);
    printf("unsigned long long int: %d\n", d);

    return 0;
}