#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor = 10; // variavel que sera apontada

    int *ponteiro;   // ponteiro simples
    int **ponteiro2; // ponteiro duplo

    // ponteiro simples recebe o endereco de memoria da variavel (aponta)
    ponteiro = &valor;

    // ponteiro duplo recebe o endereco de memoria do ponteiro simples (aponta)
    ponteiro2 = &ponteiro;

    // o ponteiro duplo a ponta para o ponteiro simples que aponta para a variavel
    // o ponteiro duplo armazena o endereco de memoria do ponteiro simples
    // que armazena o endereco de memoria da variavel e
    // assim ambos apontam para o valor da mesma variavel

    printf("Enderedo de memoria da variavel valor: %x\n", &valor);
    printf("Conteudo da variavel inteira valor: %d\n", valor);

    printf("\n");

    printf("Endereco de memoria que o ponteiro simples armazena: %x\n", ponteiro);
    printf("Conteudo que o ponteiro simples aponta: %d\n", *ponteiro);
    printf("Endereco de memoria do ponteiro simples: %x\n", &ponteiro);

    printf("\n");

    printf("Endereco de memoria que o ponteiro duplo armazena: %x\n", ponteiro2);
    printf("Conteudo que o ponteiro duplo aponta: %d\n", **ponteiro2);
    printf("Endereco de memoria do ponteiro duplo: %x\n", &ponteiro2);

    system("pause");
    return 0;
}