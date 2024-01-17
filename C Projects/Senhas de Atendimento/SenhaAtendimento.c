#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node // estrutura para cadastro de livros
{
    char nome[21];
    char tipo;
    int ordem;
    char atendimento;
    struct Node *prox;
};

typedef struct Node node; // redefindo struct Node para node
typedef node *LISTA;

int contador_ordem = 0; // contador para a ordem das senhas
char iniciais[4];       // vetor para inicias do nome

LISTA *criarLista()
{
    // aloca o ponteiro da cabeca da lista, o inicio
    LISTA *inicio = (LISTA *)malloc(sizeof(LISTA));
    if (inicio != NULL) // teste de alocacao
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

void abrirarquivo(FILE *atendimentos, LISTA *lista)
{
    atendimentos = fopen("atendimentos.txt", "r"); // abre atendimentos para leitura

    fseek(atendimentos, 0, SEEK_END); // move ponteiro para final do atendimentos

    if (ftell(atendimentos) != 0) // verifica se atendimentos esta vazio
    {

        rewind(atendimentos);
        node *tmp;

        while (1)
        {
            if ((*lista) == NULL) // se lista vazia
            {
                node *novo = (node *)malloc(sizeof(node));

                fscanf(atendimentos, "%s %c%d %c", &novo->nome, &novo->tipo, &novo->ordem, &novo->atendimento);

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

                fscanf(atendimentos, "%s %c%d %c", &novo->nome, &novo->tipo, &

                                                                             novo->ordem,
                       &novo->atendimento);
                tmp->prox = novo;
                novo->prox = NULL;
            }
            if (feof(atendimentos))
            {
                break;
            }
        }
    }

    fclose(atendimentos);

    atendimentos = fopen("atendimentos.txt", "w");

    fclose(atendimentos);
}

void Retirarsenha(LISTA *lista) // funcao recebe o ponteiro do inicio
{
    node *tmp = *lista;
    node *antaux;

    node *novo = (node *)malloc(sizeof(node));

    if (novo == NULL)
    {
        printf("Erro na alocacao!");
        exit(0);
    }

    printf("Informe o nome: ");
    gets(novo->nome);
    fflush(stdin);

    memcpy(iniciais, &novo->nome[0], 3); // armazena as 3 primeiras iniciais do nome
    iniciais[3] = '\0';

    printf("Informe o tipo da senha: ");
    scanf(" %c", &novo->tipo);
    fflush(stdin);

    printf("\n");

    contador_ordem += 1; // incrementa o contador de chamada das senhas
    novo->ordem = contador_ordem;
    novo->atendimento = 'N';

    novo->prox = NULL; // novo final da lista

    if ((*lista) == NULL) // se lista vazia
    {
        *lista = novo;
    }
    else
    {
        while (tmp->prox != NULL) // busca o ultimo elemento
        {
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }

    addsenha(novo);
    addatendimento(novo);
}

void addsenha(node *novo) // adiciona ao arquivo senhas.txt a senha cadastrada
{
    LISTA *senhas;

    senhas = fopen("senhas.txt", "w");

    fprintf(senhas, "\n\n");
    fprintf(senhas, "Agencia Bancaria\n");
    fprintf(senhas, "SENHA:\n");
    fprintf(senhas, "%c%d\n", novo->tipo, novo->ordem);
    fputs(iniciais, senhas);
    fprintf(senhas, "\n");
    fprintf(senhas, "Fique atento ao Painel");

    fclose(senhas);
}

// adiciona ao arquivo atendimento.txt os dados dos atendimentos realizados
void addatendimento(node *novo)
{
    LISTA *atendimentos;

    atendimentos = fopen("atendimentos.txt", "a");

    fputs(novo->nome, atendimentos);
    fprintf(atendimentos, "\n");
    fprintf(atendimentos, "%c%d", novo->tipo, novo->ordem);
    fprintf(atendimentos, "\n");
    fprintf(atendimentos, "%c", novo->atendimento);
    fprintf(atendimentos, "\n");

    fclose(atendimentos);
}

void exibirsenha(LISTA *lista) // exibe as senhas cadastradas
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
            printf("SENHA: %c%d\n", tmp->tipo, tmp->ordem);
            printf("ATENDIMENTO: %c\n", tmp->atendimento);

            tmp = tmp->prox;
        }
    }
    printf("\n");
}

void libera(LISTA *lista) // libera toda a lista
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

void chamarsenha(LISTA *lista) // chamada das senhas por ordem
{
    if ((*lista) != NULL)
    {
        node *tmp, *proxNode;

        tmp = *lista;
        tmp->atendimento = 'S';

        memcpy(iniciais, &tmp->nome[0], 3); // armazena as 3 primeiras iniciais do nome
        iniciais[3] = '\0';

        printf("\n");
        printf("-----------------------------------\n");
        printf("SENHA: %c%d\n", tmp->tipo, tmp->ordem);
        printf("%s\n", iniciais);
        printf("ATENDIMENTO: %c\n", tmp->atendimento);
        printf("Atendimendo Realizado!\n");
        printf("----------------------------------\n");

        *lista = tmp->prox;

        free(tmp);
    }
    else
    {
        printf("Lista ja esta vazia!");
    }
}

int main()
{
    LISTA *lista = criarLista(); // ponteiro *lista recebe a cabeca da lista
    FILE *atendimentos;

    abrirarquivo(atendimentos, lista);

    int op = -1;
    do
    {
        printf("O que deseja: \n"); // Menu de opcoes da lista
        printf("1 - Retirar Senha\n");
        printf("2 - Exibir Senhas\n");
        printf("3 - Chamar Senha\n");
        printf("0 - Sair e liberar lista\n");
        printf("Informe a opcao: ");
        scanf("%d", &op); // leitura da opcao informada
        getchar();

        printf("\n");

        switch (op)
        {
        case 1:
            Retirarsenha(lista);
            break;
        case 2:
            exibirsenha(lista);
            break;
        case 3:
            chamarsenha(lista);
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

    system("pause");
    return 0;
}