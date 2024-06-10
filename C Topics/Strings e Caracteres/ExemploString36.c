#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nome[] = "Eduardo";

    //strset(nome, '?');     // converte todos os caracteres da string para o char dado
    //strnset(nome, 'x', 1); // converte os n primeiros caracteres para o char dado
    //strrev(nome);          // inverte uma string

    printf("%s\n", nome);

    system("pause");
    return 0;
}