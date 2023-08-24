/*
Pilha versao 2
Estrutura de dados dinamica do tipo LIFO - Last In Last Out
Possui duas operacoes: push(empilhar) e pop(desempilhar)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estrura de dados que define a data de aniversario
typedef struct
{
    int ano, mes, dia;
} Data;

// estrutura de dados que define o tipo Pessoa
typedef struct
{
    char nome[100];
    Data data; // instancia da estrutra Data
} Pessoa;

// Estrutura pilha para pessoas
typedef struct no
{
    Pessoa p; // instancia da estrutura Pessoa
    struct no *proximo;
} No;

// Estrutura Pilha que armazena o topo da pilha
typedef struct
{
    No *topo;
    int tamanho;
} Pilha;

// cria pilha
void iniciar_Pilha(Pilha *pilha)
{
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

// funcao que le uma nova pessoa
Pessoa ler_pessoa()
{
    Pessoa p; // instancia da struct Pessoa
    printf("Informe o nome: ");
    scanf("%s", p.nome);
    fflush(stdin); // descarta o \n
    printf("Informe a data de aniversario [dd/mm/aaaa]: ");
    scanf("%d%d%d", &p.data.ano, &p.data.mes, &p.data.dia);
    fflush(stdin);
    printf("\n");
    return p;
}

// funcao que adiciona a pessoa na pilha - PUSH
void empilhar(Pilha *pilha)
{
    No *novo = malloc(sizeof(No)); // alocando nova instacia No

    if (novo)

    {
        novo->p = ler_pessoa();      // leitura da nova pessoa
        novo->proximo = pilha->topo; // novo nó aponta para o topo atual
        pilha->topo = novo;          // topo para ser o novo nó
        pilha->tamanho++;
    }
    else
    {
        printf("Erro na criacao da pessoa!\n");
    }
}

// funcao que remove a pessoa da pilha pelo topo - POP
No *desempilhar(Pilha *pilha)
{
    if (pilha->topo)
    {
        No *remover = pilha->topo;      // a nova instancia recebe o topo a ser removido
        pilha->topo = remover->proximo; // o topo recebe o novo topo apontado pela instancia
        pilha->tamanho--;
        return remover; // retorna o topo a ser removido
    }
    else
    {
        printf("Pilha vazia!\n");
        return NULL;
    }
}

void imprime_pessoa(Pessoa p)
{
    printf("Nome: %s | Data de Aniversario: %2d|%2d|%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

void imprime_pilha(Pilha *pilha)
{
    No *aux = pilha->topo;
    printf("----- TOPO DA PILHA -----\n");
    while (aux)
    {
        imprime_pessoa(aux->p);
        aux = aux->proximo;
    }
    printf("----- BASE DA PILHA -----\n");
    printf("Tamanho da Pilha: %d\n", pilha->tamanho);
    printf("\n");
}

int main()
{
    Pilha pilha;
    No *remover;
    int opcao = -1;

    iniciar_Pilha(&pilha);

    do
    {
        printf("[1] Adicionar Pessoa\n");
        printf("[2] Remover Pessoa\n");
        printf("[3] Imprimir Pilha\n");
        printf("[4] Sair\n");
        printf("Selecione a opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);
        printf("\n");
        switch (opcao)
        {
        case 1:
            empilhar(&pilha); // eviamos uma copia do ponteiro
            break;
        case 2:
            remover = desempilhar(&pilha); // enviamos o endereco do ponteiro para o ponteiro do topo
            if (remover)
            {
                printf("Elemento removido com sucesso!\n\n");
                free(remover); // libera o item a ser removido
            }
            else
            {
                printf("Nada para ser removido!\n\n");
            }
            break;
        case 3:
            if (pilha.tamanho != 0)
            {
                imprime_pilha(&pilha);
            }
            else
            {
                printf("Pilha Vazia!\n\n");
            }
            break;
        case 4:
            printf("Programa encerrado\n");
            exit(0);
            break;
        default:
            printf("Opcao invalida, tente novamente!\n");
            break;
        }
    } while (opcao != 0);
    return 0;
}