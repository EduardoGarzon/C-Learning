#include <stdio.h>

int main()
{
    int valor = 10; // variavel que sera apontada

    int *ponteiro;   // ponteiro simples
    int **ponteiro2; // ponteiro duplo

    ponteiro = &valor;     // ponteiro simples recebe o endereco de memoria da variavel (aponta)
    ponteiro2 = &ponteiro; // ponteiro duplo recebe o endereco de memoria do ponteiro simples (aponta)

    // o ponteiro duplo a ponta para o ponteiro simples que aponta para a variavel
    // o ponteiro duplo armazena o endereco de memoria do ponteiro simples que armazena o endereco de memoria da variavel e assim ambos apontam para o valor da mesma variavel
    
    printf("\nEnderedo de memoria da variavel valor: %x", &valor);
    printf("\nConteudo da variavel inteira valor: %d", valor);

    printf("\n");
    printf("\nEndereco de memoria que o ponteiro simples armazena: %x", ponteiro);
    printf("\nConteudo que o ponteiro simples aponta: %d", *ponteiro);
    printf("\nEndereco de memoria do ponteiro simples: %x", &ponteiro);

    printf("\n");
    printf("\nEndereco de memoria que o ponteiro duplo armazena: %x", ponteiro2);
    printf("\nConteudo que o ponteiro duplo aponta: %d", **ponteiro2);
    printf("\nEndereco de memoria do ponteiro duplo: %x", &ponteiro2);
    return 0;
}