#include <stdio.h>
#include <stdlib.h>

int main()
{
    // variavel que vai ser apontada pelo ponteiro
    int valor = 10;

    // declaracao de ponteiro simples do tipo inteiro
    int *ponteiro;

    // atribuindo o endereco de memoria da variavel valor para o ponteiro
    ponteiro = &valor;

    printf("Utilizando Ponteiros:\n");
    printf("Conteudo da variavel Valor: %d\n", valor);
    printf("Endereco da variavel Valor: %x\n", &valor);

    printf("Conteudo da variavel ponteiro (endereco de memoria): %x\n", ponteiro);
    printf("Conteudo da variavel que o ponteiro esta apontando: %d\n", *ponteiro);

    system("pause");
    return 0;
}