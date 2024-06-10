/*
    Construa um algoritmo em que o usuário fornecerá 10 valores inteiros.
    Imprima os valores na ordem em que foram digitados e também na ordem inversa.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[3];

    for (int indice = 0; indice <= 2; indice++)
    {
        printf("Informe um valor: ");
        scanf("%d", &vetor[indice]);
    }

    printf("\n");
    printf("Sequencia ordenada:\n");
    for (int indice = 0; indice <= 2; indice++)
    {
        printf("%d\n", vetor[indice]);
    }

    printf("\n");
    printf("Sequencia inversa:\n");
    for (int indice = 2; indice >= 0; indice--)
    {
        printf("%d\n", vetor[indice]);
    }

    system("pause");
    return 0;
}