/*
    Somatorio de 1 ate n com recursao.

    numero = 4

    chamada recursiva, empilhar:
        topo
        pilha -> 1 + 0
        pilha -> 2 + soma(1)
        pilha -> 3 + soma(2)
        pilha -> 4 + soma(3)
        base

    desempilhar, realizar somas
        topo
        pilha -> 1 + 0       = 1
        pilha -> 2 + soma(1) = 3
        pilha -> 3 + soma(3) = 6
        pilha -> 4 + soma(6) = 10
        base
*/

#include <stdio.h>
#include <stdlib.h>

int somatorio_Recursivo(int numero)
{
    if (numero == 0)
    {
        return 0;
    }
    else
    {
        printf("numero [%d] + numero - 1 [%d]\n", numero, numero - 1);

        return numero + somatorio_Recursivo(numero - 1);
    }
}

int main()
{
    int numero = 0;

    printf("Infome um valor inteiro: ");
    scanf("%d", &numero);

    printf("Somatorio recursivo de 1 ate %d: %d\n", numero, somatorio_Recursivo(numero));

    system("pause");
    return 0;
}