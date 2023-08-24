/*
    Exercicio 01 - Trocar os valores de duas variaveis com variavel auxiliar
    Ler um valor para a variavel a e um valor para a variavel b
    trocar o valor das duas variaveis entre elas e exibir na tela
*/

#include <stdio.h>

int main()
{
    int valor1, valor2, auxiliar;

    printf("Informe o valor 1 e valor 2: ");
    scanf("%d%d", &valor1, &valor2);

    auxiliar = valor1;
    valor1 = valor2;
    valor2 = auxiliar;

    printf("Valores trocados: \nValor 1: %d \nValor 2: %d\n", valor1, valor2);

    return 0;
}