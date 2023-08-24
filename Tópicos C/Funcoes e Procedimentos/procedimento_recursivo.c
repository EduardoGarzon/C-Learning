/*
Exemplo de procedimento recursivo.
Imprimindo intervale de 0 ate N do inicio ao fim e do fim ao inicio
Uma funcao ou procedimento recursivo chama a si mesmo durante a execucao
É um processo de repeticao.
A para de uma funcao ou procedimento recursivo é quando nao ocorre mais a sua chamada
*/

#include <stdio.h>
#include <stdlib.h>

// procedimento recursivo imprime sequencia inicio -> final
void imprimir_inicio(int numero)
{
    if (numero == 0)
    {
        printf("%d\n", numero);
    }
    else
    {
        // numero é salvo em uma pilha de recursao
        // apos o fim do procedimento é retornado o processo de desempilhar dos valores empilhados
        // empilhar    : base - 3, 2, 1, 0 - topo
        // desempilhar : topo - 0, 1, 2, 3 - topo
        // saida       : 0, 1, 2, 3
        // quando chega em 0 o print ocorre no processo de desempilhar
        // retorna para main quando a pilha de recursao estiver vazia
        imprimir_inicio(numero - 1);
        printf("%d\n", numero);
    }
}

// procedimento recursivo imprime sequencia final -> inicio
void imprimir_final(int numero)
{
    if (numero == 0)
    {
        printf("%d\n", numero);
    }
    else
    {
        // Empilhar    : base - 3, 2, 1, 0 - topo
        // Desempilhar : base - 0, 1, 2, 3 - topo
        // saida       : 3, 2, 1, 0
        printf("%d\n", numero);
        imprimir_final(numero - 1);
    }
}

int main()
{
    int numero = 0;
    printf("Informe um numero inteiro N: ");
    scanf("%d", &numero);

    printf("Sequencia inicio -> final:\n");
    imprimir_inicio(numero);
    printf("Sequencia final -> inicio:\n");
    imprimir_final(numero);

    system("pause");
    return 0;
}