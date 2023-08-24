/*
Funcoes e procedimentos de pilha.h
*/

#include <stdio.h> // procura na pasta do compilador
#include "pilha.h" // procura na pasta do arquivo as declaracoes de funcoes e assinaturas

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