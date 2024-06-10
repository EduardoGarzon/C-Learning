/*
    Exemplo de tamanhos de ponteiros em C.

    Nao existe diferenca no tamanho entre os tipos de ponteiros
    uma vez que guardam enderecos de mesmo tamanho.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *inteiro;
    float *real;
    char *caractere;

    printf("Tamanho *int: %lld\n", sizeof(inteiro));
    printf("Tamanho *float: %lld\n", sizeof(real));
    printf("Tamanho *char: %lld\n", sizeof(caractere));

    system("pause");
    return 0;
}