/*
Um ponteiro é uma variavel que guarda o endereco de memoria de outra variavel apenas.
Tambem conhecido como apontador aceita apenas enderecos de memoria.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero = 10;
    int *ponteiro;

    // ponteiro = 10 Atribuicao invalida
    ponteiro = &numero;

    printf("Valor da variavel numero: %d\n", numero);
    printf("Endereco da variavel numero: %p\n", &numero);
    printf("\n");
    printf("Valor da variavel ponteiro: %p\n", ponteiro);
    printf("Endereco da variavel ponteiro: %p\n", &ponteiro);
    printf("Valor apontado pelo ponteiro: %d\n", *ponteiro);

    system("pause");
    return 0;
}