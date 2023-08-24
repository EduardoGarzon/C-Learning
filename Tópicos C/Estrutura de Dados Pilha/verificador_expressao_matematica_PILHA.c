/*
Verificador de expressoes matematicas com a estrutura de dados PILHA
caracteres para verificar: (), {}, []
caso caracteres de abetura: insere na pilha
caso caracteres de fechamente: remove topo da pilha
se topo da pilha + caractere de fechamento == par entao expressao correta

o caractere do topo da pilha indica o ultimo que foi aberto
e por isso deve formar par com proximo caractere que fecha em seguida.
*/

#include <stdio.h>
#include <stdlib.h>

// estrutura pilha dos caracteres de abertura
typedef struct no
{
    char caractere;
    struct no *proximo;
} No;

// empilha os caracteres de abertura na pilha
No *empilhar(No *topo, char caractere)
{
    No *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->caractere = caractere;
        novo->proximo = topo;
        return novo;
    }
    else
    {
        printf("Erro ao alocar pilha!\n");
        return NULL;
    }
}

// desempilha os caracteres de abertura quando forma seus pares
No *desempilhar(No **topo)
{
    No *remover = NULL;
    if (*topo)
    {
        remover = *topo;
        *topo = remover->proximo;
        return remover;
    }
    else
    {
        printf("Pilha vazia!\n");
        return NULL;
    }
}

void imprimir_pilha(No *topo)
{
    printf("----- TOPO DA PILHA ----\n");
    while (topo)
    {
        printf("%c\n", topo->caractere);
        topo = topo->proximo;
    }

    printf("----- BASE DA PILHA -----\n\n");
}

// busca formas o par dos caracteres de abertura e fechamento () {} []
// compara o caractere de abertura do topo da pilha com o caractere de abertura lido
int comparar_paridade(char fecha, char abre)
{
    switch (fecha)
    {
    case ')':
        if (abre == '(')
            return 1;
        else
            return 0;
        break;
    case '}':
        if (abre == '{')
            return 1;
        else
            return 0;
    case ']':
        if (abre == '[')
            return 1;
        else
            return 0;
    }
}

// verifica a corretude da expressao
int verifica_expressao(char expressao[])
{
    No *remover;
    No *pilha = NULL;
    int i = 0;

    while (expressao[i] != '\0') // enquanto nao chegar no final da expresao le cada caractere
    {
        // empilha se for caractere de abertura
        if (expressao[i] == '(' || expressao[i] == '{' || expressao[i] == '[')
        {
            pilha = empilhar(pilha, expressao[i]);
        }
        else if (expressao[i] == ')' || expressao[i] == '}' || expressao[i] == ']')
        {
            // se for caractere de fechamento entao traz o caractere do topo da pilha
            remover = desempilhar(&pilha);
            if (remover)
            {
                // compara o caractere de fechamento lido com o caractere do topo da pilha
                if (comparar_paridade(expressao[i], remover->caractere) == 0)
                {
                    printf("EXPRESSAO MAL FORMATADA\n");
                    return 1;
                }
                free(remover);
            }
            else
            {
                printf("EXPRESSAO MAL FORMATADA\n");
                return 1;
            }
        }

        i++;
    }
    imprimir_pilha(pilha);
    if (pilha)
    {
        // se a pilha nao esta vazia significa que existe a falta de fechamento de caractere
        printf("EXPRESSAO MAL FORMATADA\n");
        return 1;
    }
    else
    {
        // pilha vazia indica que todos caracteres formam seus pares
        printf("EXPRESSAO BEM FORMATADA\n");
        return 0;
    }
}

int main()
{
    char exp[100]; // expressao

    printf("Informe a expressao que deseja verificar: ");
    scanf("%99s[^\n]", exp);
    printf("RETORNO DA VERIFICACAO: %d\n", verifica_expressao(exp));
}