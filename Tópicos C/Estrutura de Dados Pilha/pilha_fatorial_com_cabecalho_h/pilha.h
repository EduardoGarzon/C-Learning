/*
Arquivo de cabecalho .h
Definicao das estruturas e assinaturas das funcoes e procedimentos
*/

#ifndef PILHA_H_INCLUDED // if not defined PILHA_H_INCLUDED
#define PILHA_H_INCLUDED // Definicao criada

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

No *empilhar(No *topo, int numero);

No *desempilhar(No **topo);

void imprime_pilha(No *topo);

#endif // PILHA_H_INCLUDED
