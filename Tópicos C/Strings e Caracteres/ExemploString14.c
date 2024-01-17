/*
    Escrevendo uma string sem alocar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /*
        char nome[10] = "Luiz Eduardo"; Alocacao de memoria manual
        char nome2[] = "Luiz Eduardo";  Alocacao de memoria automatica
    */
    printf("Escrevendo string sem declarar: %s\n", "String nao declarada");

    printf("Caracteres da string -> %s == %lld\n", "String Teste", strlen("String Teste"));

    system("pause");
    return 0;
}