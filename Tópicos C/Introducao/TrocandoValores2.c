/*
    Trocar os valores de duas variaveis sem variavel auxiliar.
    Ler um valor para a variavel a e um valor para a variavel b e
    trocar o valor das duas variaveis entre elas e exibir na tela.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valor1, valor2;

    printf("Informe o valor 1 e valor 2: ");
    scanf("%d%d", &valor1, &valor2);

    // valor1 = 10 e valor2 = 20
    // 10 = 10 + 20 (30)
    valor1 = valor1 + valor2;
    // 20 = 30 - 20 (10)
    valor2 = valor1 - valor2;
    // 30 = 30 - 10 (20)
    valor1 = valor1 - valor2;

    printf("Valores trocados: \nValor 1: %d \nValor 2: %d\n", valor1, valor2);

    system("pause");
    return 0;
}