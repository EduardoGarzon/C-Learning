#include <stdio.h>

int main()
{
    /*
        Armazenar valores maiores do que o tipo primitivo possui,
        o operador long dobra a quantidade de memoria disponivel na variavel.

        antigamente o tipo int ocupava 2 bytes logo o long int ocupa 4 bytes e por isso
        hoje nao existe distincao de tamanho entre long int e int, ambos possuem 4 bytes.

        Utilizamos long long int para obter o dobro de capacidade tendo agora 8 bytes.

        Para imprimir long long int utilizamos lld(long long decimal) ou lli(long long integer)
    */

    int x;
    long int y;
    long long int z;

    float a = sizeof x;
    float b = sizeof y;
    float c = sizeof z;

    printf("int: %f \nlong int: %f \nlong long int: %f\n", a, b, c);

    return 0;
}