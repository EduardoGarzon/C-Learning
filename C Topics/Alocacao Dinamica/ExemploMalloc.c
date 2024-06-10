/*
    Exemplo de alocacao dinamica com malloc em C.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *x; // ponteiro para um inteiro

    x = malloc(sizeof(int)); // aloca um inteiro e retona seu endereco para x

    if (!x) // verifica alocacao
    {
        printf("Erro ao alocar memoria!\n");
        return -1;
    }

    *x = 50;
    printf("Valor atribuido ao int alocado: %d\n", *x);

    system("pause");
    return 0;
}