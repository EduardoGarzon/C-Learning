/* 1. Escreva um programa que declare um inteiro, um real e um char, e ponteiros para cada
um deles. Associe as variáveis aos ponteiros (use &). Modifique os valores de cada
variável usando os ponteiros. Imprima os valores das variáveis antes e após a
modificação. */

#include <stdio.h>

int main()
{
    int inteiro = 0;
    float real = 0.0;
    char letra = 0;

    int *i = &inteiro; // atribuindo aos ponteiros o endereco das variaveis de tipos correspondentes
    float *flt = &real;
    char *l = &letra;

    printf("Informe um valor para a variavel inteiro: "); // leitura pelo ponteiro
    scanf("%d", i);
    printf("Informe um valor para a variavel float: ");
    scanf("%f", flt);
    printf("Informe um valor para a variavel char: ");
    scanf(" %c", l);

    printf("\nPrimeiros Valores Informados: "); // escrevendo os valores adicionais pelo ponteiro
    printf("\nInteiro informado: %d", inteiro);
    printf("\nFloat informado: %0.2f", real);
    printf("\nChar informado: %c\n", letra);

    printf("\nInforme um novo valor para a variavel inteiro: "); // segunda leitura pelos ponteiros
    scanf("%d", i);
    printf("Informe um novo valor para a variavel float: ");
    scanf("%f", flt);
    printf("Informe um novo valor para a variavel char: ");
    scanf(" %c", l);

    printf("\nValores Finais Informados: "); // escrevendo novamente os novos valores
    printf("\nInteiro informado: %d", inteiro);
    printf("\nFloat informado: %0.2f", real);
    printf("\nChar informado: %c", letra);

    return 0;
}