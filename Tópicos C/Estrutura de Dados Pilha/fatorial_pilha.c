/*
Simulando recursao com uma estrutura de dados PILHA
*/

#include <stdio.h>
#include <stdlib.h>

// struct pilha para cada numero do valor a ser fatorado
typedef struct no
{
    int valor;
    struct no *proximo;
} No;

No *empilhar(No *topo, int numero)
{
    No *novo = malloc(sizeof(No)); // instancia novo No
    if (novo)
    {
        novo->valor = numero; // recebe o numero
        novo->proximo = topo; // aponta para o topo sendo o novo topo
        return novo;          // retorna o endereco do novo topo
    }
    else
    {
        printf("Erro ao alocar memoria!\n");
        return NULL;
    }
}

No *desempilhar(No **topo)
{
    No *remover = NULL;
    if (*topo)
    {
        remover = *topo;          // remover recebe o topo atual
        *topo = remover->proximo; // topo atual recebe o novo topo
        return remover;           // retorna o topo atual para ser removido
    }
    else
    {
        printf("Pilha vazia!\n");
        return NULL;
    }
}

void imprime_pilha(No *topo)
{
    printf("----- TOPO DA PILHA -----\n");
    while (topo)
    {
        printf("Numero: %d\n", topo->valor);
        topo = topo->proximo;
    }
    printf("----- BASE DA PILHA -----\n\n");
}

int pilha_fatorial(int numero)
{
    No *remover;
    No *topo = NULL;
    while (numero > 1)
    {
        topo = empilhar(topo, numero); // empilha cada numero do valor a ser fatorado
        numero--; // decrementa o valor informado
    }

    imprime_pilha(topo);

    while (topo)
    {
        remover = desempilhar(&topo); // recebe o topo atual a ser removido
        numero = numero * remover->valor; // calculo do fatorial
        free(remover); // libera o topo atual
    }
    return numero;
}

int main()
{
    int valor = 0;
    printf("Informe um valor para calcular o fatorial: ");
    scanf("%d", &valor);
    printf("Fatorial por pilha: %d\n", pilha_fatorial(valor));

    return 0;
}