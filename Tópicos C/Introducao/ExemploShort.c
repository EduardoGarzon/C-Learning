#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        Uma variavel do tipo int ocupa 4 bytes ou seja 32 bits
        o operador short reduz pela metade o consumo de memoria
        tornando o codigo mais otimizado.

        4 bytes = 32 bits - 4x8
        2 bytes = 16 bits - 2x8
    */

    short int x;
    float tamanho = sizeof x;

    printf("%f\n", tamanho);

    system("pause");
    return 0;
}