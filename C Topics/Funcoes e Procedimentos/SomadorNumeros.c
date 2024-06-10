/*
    Faça uma função que receba dois números inteiros positivos por parâmetro
    e retorne a soma dos N números inteiros existentes entre eles.
*/

#include <stdio.h>
#include <stdlib.h>

int n1 = 0, n2 = 0, soma = 0; // variaveis globais

int somador()
{
    int i = 0;
    if (n1 < n2) // soma dos valores quando o primeiro é menor que o segundo
    {
        for (i = n1; i < n2; i++)
        {
            soma += i;
        }
    }
    else if (n1 > n2) // soma dos valores quando o segundo é menor que o primeiro
    {
        for (i = n2; i < n1; i++)
        {
            soma += i;
        }
    }
    else
    {
        printf("Os valores nao podem ser iguais.\n"); // erro quando os valores sao iguais
    }

    return soma;
}

int main()
{
    printf("Informe dois numeros: ");
    scanf("%d%d", &n1, &n2);

    somador(); // funcao que calcula os valores entre os numeros informados

    printf("\n");
    printf("Soma dos valores existentes entre %d e %d: %d\n", n1, n2, soma);

    system("pause");
    return 0;
}