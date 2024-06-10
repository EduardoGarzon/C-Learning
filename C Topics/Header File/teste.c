#include <stdio.h>
#include "BibliotecaTeste.h"

int main()
{
    int a = 0, b = 0, c = 0;
    char string[50];

    printf("Informe um numero inteiro: ");
    scanf("%d", &a);

    printf("Informe outro numero: ");
    scanf("%d", &b);

    c = soma(a, b, c);
    printf("Soma dos numeros %d e %d: %d\n", a, b, c);

    printf("\n\nInforme seu nome: ");
    fgets(string, 100, stdin);

    printf("Tamanho: %d\n", tamanho(string));

    system("pause");
    return 0;
}