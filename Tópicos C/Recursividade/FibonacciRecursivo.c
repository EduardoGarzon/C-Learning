/*
    Calculando o enésimo numero da sequencia de Fibonacci por uma funcao recursiva.
    n += (n - 1) + (n - 2)

    1 -> 0
    2 -> 1
    3 -> 1 + 2 = 1
    4 -> 3 + 2 = 2
    ...

    10 = fib(9) + fib(8)
    9 = fib(8) + fib(7) REPETICAO DE CALCULOS fib(8)
    8 = fib(7) + fib(6) REPETICAO DE CALCULOS fib(7)
    ...

    Metodo recursivo (desvantajaoso) : inumeros termos sao calculados varias vezes repetindo varios calculos.
    Metodo iterativo (vantajoso)     : cada numero é calculado uma unica vez.
*/

#include <stdio.h>
#include <stdlib.h>

int fibonacci_Recursivo(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
        return fibonacci_Recursivo(n - 1) + fibonacci_Recursivo(n - 2);
}

int main()
{
    int n = 0;

    printf("Informe uma posicao para a sequencia Fibonacci: ");
    scanf("%d", &n);
    printf("\n");

    printf("Posicao [%d] | Fibonacci [%d]\n", n, fibonacci_Recursivo(n));

    system("pause");
    return 0;
}