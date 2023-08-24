/*
Exemplo de ponteiro para ponteiro.
Uma variavel do tipo ponteiro guarda o endereco de memoria de outra variavel do tipo ponteiro.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variavel do tipo inteiro
    int A = 10;
    // Ponteiro para um inteiro
    int *B;
    // Ponteiro para um Ponteiro de inteiro
    int **C;

    // ponteiro do tipo int recebe o end. da variavel A do tipo int.
    B = &A;
    // ponteiro duplo C recebe o endereco do ponteiro B de tipo int.
    C = &B;

    printf("Endereco da var A: %p\n", &A);
    printf("Conteudo da var A: %d\n\n", A);

    printf("Endereco do ponteiro B: %p\n", &B);
    printf("Conteudo do ponteiro B: %p\n", B);
    printf("Conteudo apontado por B: %d\n\n", *B);

    printf("Endereco do ponteiro C: %p\n", &C);
    printf("Conteudo do ponteiro C: %p\n", C);
    printf("Conteudo apontado por C: %p\n", *C);

    system("pause");
    return 0;
}