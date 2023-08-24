/*
2. Faça um programa que crie uma lista encadeada para armazenar os
dados de carros: marca (máximo 15 letras), ano e preço. Todas as
informações devem ser gravadas em um arquivo txt. Leia um valor p e
mostre as informações de todos os carros com preço menor que p.
Importante: que o usuário pode abrir este arquivo diversas vezes e realizar
a inserção de informações no fim do mesmo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct // estrutura para cadastro de carros
{
    float preco;
    int ano;
    char marca[11];
    struct Node *prox;
} node;
typedef node *LISTA;

LISTA *criarLista()
{
    LISTA *inicio = (LISTA *)malloc(sizeof(LISTA)); // aloca o ponteiro da cabeca da lista, o inicio
    if (inicio != NULL)                             // teste de alocacao
    {
        *inicio = NULL; // O conteudo de *inicio recebe NULL
    }
    else
    {
        printf("Erro na alocacao... \n");
        exit(0);
    }
    return inicio; // retorna o conteudo do ponteiro
}

void abrirarquivo(FILE *arquivo, LISTA *lista)
{
    arquivo = fopen("carros.txt", "r"); // abre arquivo para leitura
    fseek(arquivo, 0, SEEK_END);        // move ponteiro para final do arquivo
    if (ftell(arquivo) != 0)            // verifica se arquivo esta vazio
    {
        rewind(arquivo);
        node *tmp;
        while (!feof(arquivo))
        {
            if ((*lista) == NULL) // se lista vazia
            {
                node *novo = (node *)malloc(sizeof(node));
                fscanf(arquivo, "%s%d%f", &novo->marca, &novo->ano, &novo->preco);
                *lista = novo;
                novo->prox = NULL;
            }
            else
            {
                tmp = (*lista);
                while (tmp->prox != NULL) // busca o ultimo elemento
                {
                    tmp = tmp->prox;
                }
                node *novo = (node *)malloc(sizeof(node));
                fscanf(arquivo, "%s%d%f", &novo->marca, &novo->ano, &novo->preco);
                tmp->prox = novo;
                novo->prox = NULL;
            }
        }
    }
    fclose(arquivo);
}

void insereFinal(LISTA *lista) // funcao recebe o ponteiro do inicio
{
    node *novo = (node *)malloc(sizeof(node)); // alocando novo espaco para *novo
    if (novo == NULL)
    {
        printf("Erro na alocacao!");
        exit(0);
    }
    printf("Informe a marca do carro: ");
    gets(novo->marca);
    fflush(stdin);
    printf("Informe o ano do carro: ");
    scanf("%d", &novo->ano);
    fflush(stdin);
    printf("Informe o preco do carro: ");
    scanf("%f", &novo->preco);
    fflush(stdin);
    printf("\n");
    novo->prox = NULL;    // novo final da lista
    if ((*lista) == NULL) // se lista vazia
    {
        *lista = novo;
    }
    else
    {
        node *tmp; // ponteiro temporario, indice para os proximos elementos
        tmp = (*lista);
        while (tmp->prox != NULL) // busca o ultimo elemento
        {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
    addfile(novo);
}

void addfile(node *novo)
{
    FILE *arquivo;
    arquivo = fopen("carros.txt", "a");
    fprintf(arquivo, "\n");
    fputs(novo->marca, arquivo);
    fprintf(arquivo, "\n");
    fprintf(arquivo, "%d ", novo->ano);
    fprintf(arquivo, "%0.2f", novo->preco);
    fclose(arquivo);
}

void exibe(LISTA *lista)
{
    if ((*lista) == NULL)
    {
        printf("Lista Vazia!\n");
    }
    else
    {
        node *tmp; // ponteiro temporario;
        tmp = (*lista);
        while (tmp != NULL)
        {
            printf("\n");
            printf("Marca do carro: %s\n", tmp->marca);
            printf("Ano do carro: %d\n", tmp->ano);
            printf("Preco do carro: R$ %0.2f\n", tmp->preco);
            tmp = tmp->prox;
        }
    }
    printf("\n");
}

void libera(LISTA *lista)
{
    if ((*lista) == NULL)
    {
        printf("Lista Vazia!\n");
    }
    else
    {
        node *tmp;
        while ((*lista) != NULL)
        {
            tmp = *lista;
            *lista = (*lista)->prox;
            free(tmp);
        }
        *lista = NULL;
    }
}

void pesquisa(LISTA *lista)
{
    node *tmp; // ponteiro temporario;
    tmp = (*lista);
    float p;
    printf("Informe o valor: ");
    scanf("%f", &p);
    fflush(stdin);
    printf("\nCARROS NA FAIXA DE PRECO: \n");
    while (tmp != NULL)
    {
        if (tmp->preco <= p)
        {
            printf("\n");
            printf("Marca do carro: %s\n6", tmp->marca);
            printf("Ano do carro: %d\n", tmp->ano);
            printf("Preco do carro: %0.2f\n", tmp->preco);
        }
        tmp = tmp->prox;
    }
    printf("\n");
}

int main()
{
    LISTA *lista = criarLista(); // ponteiro *lista recebe a cabeca da lista
    FILE *arquivo;
    abrirarquivo(arquivo, lista);
    int op = -1;

    do
    {
        printf("O que deseja: \n"); // Menu de opcoes da lista
        printf("1 - Cadastrar carros\n");
        printf("2 - Mostrar carros\n");
        printf("3 - Liberar lista de carros\n");
        printf("4 - Pesquisar por preco\n");
        printf("0 - Sair\n");
        printf("Informe a opcao: ");
        scanf("%d", &op); // leitura da opcao informada
        fgetchar();
        printf("\n");

        switch (op)
        {
        case 1:
            insereFinal(lista);
            break;
        case 2:
            exibe(lista);
            break;
        case 3:
            libera(lista);
            FILE *arquivo;
            arquivo = fopen("carros.txt", "w");
            fclose(arquivo);
            break;
        case 4:
            pesquisa(lista);
            break;
        case 0:
            libera(lista);
            break;
        default:
            printf("Opcao nao cadastrada...\n");
            break;
        }
    } while (op != 0);
    free(lista);
    return 0;
}