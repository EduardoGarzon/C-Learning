/*
Inverter a ordem das letras de uma string utilizando PILHA
    Exemplo:
        entrada == ABRA A PORTA
        saida == ARBA A ATROP
Cada caractere é empilhado na PILHA e ao desempilhar a palavra fica invertida
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// pilha que armazena cada caractere do texto
typedef struct no
{
    char caractere;
    struct no *proximo;
} No;

// empilha cada caractere do texto na pilha
No *empilhar(No *pilha, char caractere)
{
    No *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->caractere = caractere;
        novo->proximo = pilha;
        return novo;
    }
    else
    {
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
}

// retorna o caractere do topo
No *desempilhar(No **pilha)
{
    No *remover = NULL;
    if (*pilha)
    {
        remover = *pilha;
        *pilha = remover->proximo;
        return remover;
    }
    else
    {
        printf("Pilha Vazia!\n");
        return NULL;
    }
}

// inverte as letras da string
void inverter_letras(char texto[])
{
    int i = 0;
    No *pilha = NULL;
    No *remover;

    while (texto[i] != '\0') // enquanto nao chegar no fim da string
    {
        if (texto[i] != ' ') // se o caractere nao for um espaco
        {
            pilha = empilhar(pilha, texto[i]); // empilha o caractere
        }
        else
        { // se caractere for um espaco
            while (pilha)
            {
                remover = desempilhar(&pilha);
                printf("%c", remover->caractere); // desempilha e escreve invertido pois comeca do topo
                free(remover);
            }
            printf(" "); // espaco para a proxima palavra
        }
        i++;
    }
    while (pilha) // laco para ultima palavra ainda armazenada na pilha
    {
        remover = desempilhar(&pilha);
        printf("%c", remover->caractere);
        free(remover);
    }
    printf("\n");
}

int main()
{
    char texto[100]; //= {"Luiz eduardo"};

    printf("Informe a string: ");
    fgets(texto, 100, stdin);
    inverter_letras(texto);
    return 0;
}