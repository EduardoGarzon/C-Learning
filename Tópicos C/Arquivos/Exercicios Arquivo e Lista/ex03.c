/*
3. Construa uma lista encadeada para ler e manipular informações de
cadastros de clientes (CPF, nome, ano de nascimento). Ao final todas as
informações devem ser gravadas em um arquivo txt por ordem de ano de
nascimento. Importante: que o usuário pode abrir este arquivo diversas
vezes e realizar a inserção de informações no fim do mesmo.
*/

// Por algum motivo, inserir o nome com espacos
// causa problemas na leitura do arquivo para gravar na lista no inicio do programa
// utilizando fgets nao encontrei solucao para o problema
// apenas gets se comporta normalmente

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node // estrutura para cadastro de livros
{
    char CPF[13];
    int ano;
    char nome[21];
    struct Node *prox;
};
typedef struct Node node; // redefindo struct Node para node
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
    arquivo = fopen("clientes.txt", "r"); // abre arquivo para leitura
    fseek(arquivo, 0, SEEK_END);          // move ponteiro para final do arquivo
    if (ftell(arquivo) != 0)              // verifica se arquivo esta vazio
    {
        rewind(arquivo);
        node *tmp;
        while (!feof(arquivo))
        {
            if ((*lista) == NULL) // se lista vazia
            {
                node *novo = (node *)malloc(sizeof(node));
                fscanf(arquivo, "%s%d%s", &novo->CPF, &novo->ano, &novo->nome);
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
                fscanf(arquivo, "%s%d%s", &novo->CPF, &novo->ano, &novo->nome);
                tmp->prox = novo;
                novo->prox = NULL;
            }
        }
    }
    fclose(arquivo);
    arquivo = fopen("clientes.txt", "w");
    fclose(arquivo);
}

void inserirOrdenado(LISTA *lista) // funcao recebe o ponteiro do inicio
{
    node *tmp, *antaux;
    tmp = *lista;
    node *novo = (node *)malloc(sizeof(node));
    if (novo == NULL)
    {
        printf("Erro na alocacao!");
        exit(0);
    }
    printf("Informe o nome: ");
    gets(novo->nome);
    fflush(stdin);
    printf("Informe o CPF: ");
    gets(novo->CPF);
    fflush(stdin);
    printf("Informe o ano de nascimento: ");
    scanf("%d", &novo->ano);
    fflush(stdin);
    printf("\n");
    novo->prox = NULL;
    if ((*lista == NULL))
    {
        *lista = novo;
    }
    else if (novo->ano < (*lista)->ano)
    {
        novo->prox = (*lista);
        *lista = novo;
    }
    else
    {
        while (novo->ano > tmp->ano && tmp->prox != NULL) // percorre a lista ate o final ou ate que o novo seja menor que o proximo
        {
            antaux = tmp;    // guardo o elemento anterior ao atual
            tmp = tmp->prox; // pula para os proximos elementos guardando o atual
        }
        if (novo->ano > tmp->ano && tmp->prox == NULL) // insere no final da lista
        {
            novo->prox = NULL; // proximo do novo recebe null
            tmp->prox = novo;  // ultimo elemento aponta para o novo ultimo
        }
        if (novo->ano < tmp->ano && novo->ano > antaux->ano) // insere no meio da lista
        {
            antaux->prox = novo; // valor anterior aponta para o novo
            novo->prox = tmp;    // novo aponta para o proximo
        }
    }
}

void addfile(FILE *arquivo, LISTA *lista)
{
    arquivo = fopen("clientes.txt", "a");
    node *tmp = *lista;
    while (tmp != NULL)
    {
        fprintf(arquivo, "\n");
        fputs(tmp->CPF, arquivo);
        fprintf(arquivo, "\n");
        fprintf(arquivo, "%d ", tmp->ano);
        fputs(tmp->nome, arquivo);
        tmp = tmp->prox;
    }
    fclose(arquivo);
    libera(lista);
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
            printf("NOME: %s\n", tmp->nome);
            printf("CPF: %s\n", tmp->CPF);
            printf("ANO DE NASCIMENTO: %d\n", tmp->ano);
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
        printf("1 - Cadastrar clientes\n");
        printf("2 - Exibir clientes\n");
        printf("3 - Liberar lista de clientes\n");
        printf("0 - Sair\n");
        printf("Informe a opcao: ");
        scanf("%d", &op); // leitura da opcao informada
        getchar();
        printf("\n");

        switch (op)
        {
        case 1:
            inserirOrdenado(lista);
            break;
        case 2:
            exibe(lista);
            break;
        case 3:
            libera(lista);
            break;
        case 0:
            addfile(arquivo, lista);
            break;
        default:
            printf("Opcao nao cadastrada...\n");
            break;
        }
    } while (op != 0);
    free(lista);
    return 0;
}