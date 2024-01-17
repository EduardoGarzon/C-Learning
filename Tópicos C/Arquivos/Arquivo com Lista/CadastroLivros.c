/*
    Elabore um programa que crie uma lista simplesmente encadeada que
    armazene o cadastro de livros (código, nome do titulo, ano), ao final da
    execução do programa todas as informações devem ser gravadas em um
    arquivo txt. Realizar a abertura do arquivo como “a”, dando a possibilidade
    do usuário abrir o arquivo outras vezes e inserir novos livros no mesmo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct // estrutura para cadastro de livros
{
    int codigo;
    int ano;
    char nome[11];
    struct node *prox;
} node;

typedef node *LISTA;

LISTA *criarLista()
{
    // aloca o ponteiro da cabeca da lista, o inicio
    LISTA *inicio = (LISTA *)malloc(sizeof(LISTA));

    // teste de alocacao
    if (inicio != NULL)
    {
        *inicio = NULL; // O conteudo de *inicio recebe NULL
    }
    else
    {
        printf("Erro na alocacao...\n");
        exit(0);
    }

    return inicio; // retorna o conteudo do ponteiro
}

void abrirarquivo(FILE *arquivo, LISTA *lista)
{
    arquivo = fopen("livros.txt", "r"); // abre arquivo para leitura

    fseek(arquivo, 0, SEEK_END); // move ponteiro para final do arquivo

    if (ftell(arquivo) != 0) // verifica se arquivo esta vazio
    {
        rewind(arquivo);

        node *tmp;

        while (!feof(arquivo))
        {
            if ((*lista) == NULL) // se lista vazia
            {
                node *novo = (node *)malloc(sizeof(node));

                fscanf(arquivo, "%d%s%d", &novo->codigo, &novo->nome, &novo->ano);
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

                fscanf(arquivo, "%d%s%d", &novo->codigo, &novo->nome, &novo->ano);
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

    printf("Informe o codigo do livro: ");
    scanf("%d", &novo->codigo);
    fflush(stdin);

    printf("Informe o nome do titulo do livro: ");
    gets(novo->nome);
    fflush(stdin);

    printf("Informe o ano do livro: ");
    scanf("%d", &novo->ano);

    printf("\n");

    novo->prox = NULL; // novo final da lista

    node *tmp; // ponteiro temporario, indice para os proximos elementos

    if ((*lista) == NULL) // se lista vazia
    {
        *lista = novo;
    }
    else
    {
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
    arquivo = fopen("livros.txt", "a");

    fprintf(arquivo, "\n");
    fprintf(arquivo, "%d", novo->codigo);

    fputs(novo->nome, arquivo);
    fprintf(arquivo, "\n");

    fprintf(arquivo, "%d", novo->ano);

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
            printf("Codigo do livro: %d\n", tmp->codigo);
            printf("Nome do livro: %s\n", tmp->nome);
            printf("Ano do livro: %d\n", tmp->ano);
            printf("\n");

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

int main()
{
    LISTA *lista = criarLista(); // ponteiro *lista recebe a cabeca da lista
    FILE *arquivo;

    abrirarquivo(arquivo, lista);

    int op = -1;
    do
    {
        printf("O que deseja: \n"); // Menu de opcoes da lista
        printf("1 - Inserir livro\n");
        printf("2 - Mostrar livros\n");
        printf("3 - Liberar lista de livros\n");
        printf("0 - Sair\n");
        printf("Informe a opcao: ");
        scanf("%d", &op); // leitura da opcao informada
        fflush(stdin);
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
            arquivo = fopen("livros.txt", "w");
            fclose(arquivo);
            break;
        case 0:
            libera(lista);
        default:
            printf("Programa encerrado.\n");
            break;
        }
    } while (op != 0);

    free(lista);

    system("pause");
    return 0;
}