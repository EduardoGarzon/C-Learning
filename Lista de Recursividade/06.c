/*
6. Escreva uma função recursiva que calcule a soma dos dígitos de um
número inteiro. Por exemplo, se a entrada for 123, a saída deverá ser
1+2+3 = 6.
*/

#include <stdio.h>

int somar(int numero, int soma, int aux) // chamada da funcao recursiva que soma os digitos do numero
{
    if (numero == 0)
    {
        return soma;
    }
    else
    {
        aux = numero % 10;    // retorna sempre o ultimo digito
        numero = numero / 10; // divide para avancao ao proximo digito
        soma += aux;
        return (somar(numero, soma, aux));
    }
}

int main()
{
    int numero = 0;
    int soma = 0;
    int aux = 0;

    printf("Informe um numero inteiro: ");
    scanf("%d", &numero);

    printf("Soma dos digitos do numero informado: %d", somar(numero, soma, aux));

    return 0;
}