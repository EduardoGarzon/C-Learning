/*
    Escreva um programa que declare um inteiro, um real e um char, e
    ponteiros para cada um deles.

    Associe as variáveis aos ponteiros (use &).

    Modifique os valores de cada variável usando os ponteiros.

    Imprima os valores das variáveis antes e após a modificação.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int inteiro = 0;
    float real = 0.0;
    char letra = 0;

    // atribuindo aos ponteiros o endereco das variaveis de tipos correspondentes
    int *i = &inteiro;
    float *flt = &real;
    char *l = &letra;

    printf("Informe um valor para a variavel inteiro: "); // leitura pelo ponteiro
    scanf("%d", i);
    printf("Informe um valor para a variavel float: ");
    scanf("%f", flt);
    printf("Informe um valor para a variavel char: ");
    scanf(" %c", l);

    printf("\n");
    // escrevendo os valores adicionais pelo ponteiro
    printf("Primeiros Valores Informados:\n");
    printf("Inteiro informado: %d\n", inteiro);
    printf("Float informado: %0.2f\n", real);
    printf("Char informado: %c\n", letra);

    printf("\n");
    // segunda leitura pelos ponteiros
    printf("Informe um novo valor para a variavel inteiro: ");
    scanf("%d", i);

    printf("Informe um novo valor para a variavel float: ");
    scanf("%f", flt);

    printf("Informe um novo valor para a variavel char: ");
    scanf(" %c", l);

    printf("\n");
    printf("Valores Finais Informados:\n"); // escrevendo novamente os novos valores
    printf("Inteiro informado: %d\n", inteiro);
    printf("Float informado: %0.2f\n", real);
    printf("Char informado: %c\n", letra);

    system("pause");
    return 0;
}