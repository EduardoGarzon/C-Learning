#include <stdio.h>
#include <stdio.h>

int main()
{
    int numero = 10;
    int *ponteiro;
    int *pont;

    *ponteiro = numero;

    // *ponteiro = &numero -> armazena o endereco da variavel
    // pont = *ponteiro    -> nao funciona
    // pont = &ponteiro    -> nao funciona
    // *pont = *ponteiro   -> nao funcina
    // *pont = ponteiro    -> nao funciona
    // *pont = &ponteiro   -> nao funciona

    pont = ponteiro;

    printf("\n");
    printf("Enderedo de memoria da variavel valor: %x\n", &numero);
    printf("Conteudo da variavel inteira valor: %d\n", numero);
    // printf("\nEnderedo de memoria da variavel valor: %d", &numero); Incorreto
    // printf("\nEnderedo de memoria da variavel valor: %x", numero); Incorreto

    printf("\n");
    printf("Endereco de memoria do ponteiro: %x\n", ponteiro);
    printf("Conteudo que o ponteiro simples aponta: %d\n", *ponteiro);
    printf("Endereco de memoria que o ponteiro simples armazena: %x\n", &ponteiro);
    // printf("\nTESTE: %d", ponteiro) nao funciona;

    printf("\n");
    printf("Endereco de memoria do ponteiro: %x\n", pont);
    printf("Conteudo que o ponteiro simples aponta: %d\n", *pont);
    printf("Endereco de memoria que o ponteiro simples armazena: %x\n", &pont);

    system("pause");
    return 0;
}