/*
    Convertendo um numero em texto em C.

    Objetivo: como utilizar o valor digitado pelo usuario na configuracao do scanf
    para delimitar o maximo de caracteres que podem ser lidos do teclado.

    Precisamos converter o numero informado para texto e
    entao montar a string de configuracao para o scanf.

    Padrao de configuracao do scanf: %x[^\n] ler no maximo x caracteres ate o ENTER pressionado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int tamanho = 0;
    char str1[10] = {"%"};
    char str2[10];

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);
    getchar();

    // Funcao que imprime dados em uma string.

    // Parametros: string onde os dados serao escritos,
    // tipo de dado a ser escrito e a variavel onde esta o dado a ser convertido.

    // A funcao nao valida o tamanho do valor pondendo ocorrer estouro de memoria.
    // sprintf(str, "%d", valor);

    // Funcao que imprime dados em uma string e valida o valor de var.
    // Parametros: string onde os dados serao escritos,
    // n max de caracteres a ser lido, tipo de dado a ser escrito e
    // a variavel onde esta o dado a ser convertido.

    // É preciso 2 % para imprimir o %.

    snprintf(str1, 10, "%%%d[^\n]", tamanho);

    // Concatena ao final da string.
    strcat(str1, str2);

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    char palavras[tamanho];

    printf("Digite uma frase: ");
    // scanf("%50[^\n], palavras");
    scanf(str1, palavras);

    printf("frase: %s\n", palavras);

    system("pause");
    return 0;
}
