/*
    Trocar os valores de duas variaveis com uma variavel auxiliar.
    Ler um valor para a variavel a e um valor para a variavel b e
    trocar o valor das duas variaveis entre elas e exibir na tela.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor1, valor2, auxiliar;

    printf("Informe o valor 1 e valor 2: ");
    scanf("%d%d", &valor1, &valor2);

    auxiliar = valor1;
    valor1 = valor2;
    valor2 = auxiliar;

    printf("Valores trocados: \nValor 1: %d \nValor 2: %d\n", valor1, valor2);

    system("pause");
    return 0;
}