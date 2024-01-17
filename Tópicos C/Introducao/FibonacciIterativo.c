/*
    Comparando tempo de execucao do algortimo de Fibonacci por recursao e iteracao
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Função iterativa para calcular um termo n da sequência de fibonacci.
    Como a sequência cresce muito rápido,
    está sendo usado o operador long para que o tipo int ocupe 8 bytes.
*/
long long int fiboI(int n)
{
    long long int a = 0, b = 1, c;
    int i = 2;

    if (n == 1)
        return a;
    else
    {
        if (n == 2)
            return b;
        else
        {
            while (i < n)
            {
                c = a + b; // fib(50) = fib(48) + fib(49)
                a = b;     // fib(48) = fib(49)
                b = c;     // fib(49) = fib(50)
                i++;
            }

            return c;
        }
    }
}

int main()
{
    int n = 30;

    printf("Fibonacci iterativo: %lld\n", fiboI(n));

    system("pause");
    return 0;
}