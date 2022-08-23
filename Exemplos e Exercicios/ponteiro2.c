#include <stdio.h>
#include <stdio.h>

int main()
{
    int numero = 10;
    int *ponteiro;
    int *pont;

    *ponteiro = numero;

    // *ponteiro = &numero armazena o endereco da variavel
    // pont = *ponteiro nao funciona
    // pont = &ponteiro nao funciona
    // *pont = *ponteiro nao funcina
    // *pont = ponteiro nao funciona
    // *pont = &ponteiro nao funciona

    pont = ponteiro;

    printf("\n");
    printf("\nEnderedo de memoria da variavel valor: %x", &numero);
    printf("\nConteudo da variavel inteira valor: %d", numero);
    // printf("\nEnderedo de memoria da variavel valor: %d", &numero); Incorreto
    // printf("\nEnderedo de memoria da variavel valor: %x", numero); Incorreto

    printf("\n");
    printf("\nEndereco de memoria do ponteiro: %x", ponteiro);
    printf("\nConteudo que o ponteiro simples aponta: %d", *ponteiro);
    printf("\nEndereco de memoria que o ponteiro simples armazena: %x", &ponteiro);
    // printf("\nTESTE: %d", ponteiro) nao funciona;

    printf("\n");
    printf("\nEndereco de memoria do ponteiro: %x", pont);
    printf("\nConteudo que o ponteiro simples aponta: %d", *pont);
    printf("\nEndereco de memoria que o ponteiro simples armazena: %x", &pont);

    return 0;
}