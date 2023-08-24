/*
Comparando tempo de execucao do algortimo de Fibonacci por recursao e iteracao
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
        Função recursiva para calcular um termo n da sequência de fibonacci
        Como a sequência cresce muito rápido, está sendo usado o operador long para que o tipo int ocupe 8 bytes.
*/
long long int fiboR(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
        return fiboR(n - 1) + fiboR(n - 2);
}

/*
        Função iterativa para calcular um termo n da sequência de fibonacci
        Como a sequência cresce muito rápido, está sendo usado o operador long para que o tipo int ocupe 8 bytes.
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

    clock_t tIni, tFim;
    //float timeI = 0.0;
    float timeR = 0.0;

    //tIni = clock();
    printf("Fibonacci iterativo: %lld\n", fiboI(n));
    //tFim = clock();
    //timeI = (float)(((tFim - tIni) + 0.0) / CLOCKS_PER_SEC);
    //printf("Time: %fs\n\n", timespent);

    //tIni = clock();
    printf("Fibonacci recursivo: %lld\n", fiboR(n));
    //tFim = clock();
    //printf("Tempo em segundos: %f\n\n", difftime(tFim, tIni));
    //timeR = (float)(((tFim - tIni) + 0.0) / CLOCKS_PER_SEC);

    system("pause");
    return 0;
}