/*
A sequência de Padovan é uma sequência de naturais P(n) definida pelos
valores iniciais P(0) = P(1) = p(2) = 1 e a seguinte relação recursiva:
P(n) = P(n - 2) + P(n - 3) se n > 2
Alguns valores da sequência são: 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16, 21, 28...
Faça uma função recursiva que receba um número N e retorne o N-ésimo termo
das sequências de Tribonacci e Padovan (uma função recursiva para cada).
*/

#include <stdio.h>
// variaveis globais para as sequencias
int prevprev = 0; // numero anterior ao anterior
int prev = 0;     // numero anterior
int curr = 0;     // numero atual
int next = 0;     // proximo numero
int i = 0;        // indice de contagem

// padovan: proximo sera a soma do numero anterior e seu anterior
int padovan(int prev, int prevprev, int curr, int next, int n, int i) // funcao recursiva para padovan
{
    if (i > n)
    {
        return next;
    }
    else
    {
        next = prevprev + prev;
        prevprev = prev;
        prev = curr;
        curr = next;
        printf("%d - ", next);
        return (padovan(prev, prevprev, curr, next, n, i += 1));
    }
}

// tribonacci: proximo sera a soma dos 3 numeros anteriotores ao atual
int trib(int prev, int prevprev, int curr, int next, int n, int i) // funcao recursiva para tribonacci
{
    if (i > n)
    {
        return next;
    }
    else
    {
        next = prevprev + prev + curr;
        prevprev = prev;
        prev = curr;
        curr = next;
        printf("%d - ", next);
        return (trib(prev, prevprev, curr, next, n, i += 1));
    }
}

int main()
{
    int n = 0;
    printf("Informe um numero inteiro positivo: "); // lendo a posicao desejada
    scanf("%d", &n);

    prevprev = 1; // valores predefinidos para padovan
    prev = 1;
    curr = 1;
    next = 1;
    i = 3;
    printf("Sequencia de Padovan: ");
    printf(" [%d]", padovan(prev, prevprev, curr, next, n, i)); // chamada da funcao recursiva padovan

    prevprev = 1; // valores predefinidos para tribonacci
    prev = 1;
    curr = 2;
    next = 0;
    i = 3;
    printf("\n\nSequencia de Tribonacci: ");
    printf(" [%d]", trib(prev, prevprev, curr, next, n, i)); // chamada da funcao recursiva tribonacci

    return 0;
}