#include <stdio.h>
#include <stdlib.h>

struct Node
{                      // estrutura de dados, tipo do elemento, estrutura do nó
    int valor;         // valores informados pelo usuario
    struct Node *prox; // ponteiro do tipo struct Node para o proximo elemento da lista
};

typedef struct Node node; // redefindo struct Node para node
typedef node *LISTA;

LISTA *criarLista()
{
    LISTA *inicio = (LISTA *)malloc(sizeof(LISTA)); // aloca o ponteiro da cabeca da lista, o inicio

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

void insereFinal(LISTA *lista) // funcao recebe o ponteiro do inicio
{
    node *novo = (node *)malloc(sizeof(node)); // alocando novo espaco para *novo

    if (novo == NULL)
    {
        printf("Erro na alocacao!\n");
        exit(0);
    }

    printf("Informe o valor da nova posicao: ");
    scanf("%d", &novo->valor);

    novo->prox = NULL; // novo final da lista

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
}

void retiraFinal(LISTA *lista)
{
    node *antNode, *tmp;
    tmp = *lista;

    if ((*lista) != NULL && tmp->prox == NULL) // se so existe um unico elemento na lista
    {
        *lista = NULL;

        free(tmp);

        printf("Elemento removido com sucesso!\n");
    }
    else if (*lista != NULL)
    {
        while (tmp->prox != NULL)
        {
            antNode = tmp;
            tmp = tmp->prox;
        }
        antNode->prox = NULL;

        free(tmp);

        printf("Elemento removido com sucesso!\n");
    }
    else
    {
        printf("Lista ja esta vazia!\n");
    }
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
            printf("%5d", tmp->valor);
            tmp = tmp->prox;
        }
    }
    printf("\n");
}

void libera(LISTA *lista)
{
    node *tmp, *antNode;
    tmp = *lista;

    if ((*lista) == NULL) // lista vazia
    {
        printf("Lista Vazia!\n");
    }
    else
    {
        while (tmp->prox != NULL)
        {
            while (tmp->prox != NULL)
            {
                antNode = tmp;
                tmp = tmp->prox;
            }
            antNode->prox = NULL;

            free(tmp);

            tmp = *lista;
        }

        if (tmp->prox == NULL)
        {
            *lista = NULL;
            free(tmp);
        }
    }
}

int main()
{
    LISTA *lista = criarLista(); // ponteiro *lista recebe a cabeca da lista
    int op = -1;

    do
    {
        printf("O que deseja: \n"); // Menu de opcoes da lista
        printf("1 - Inserir FINAL\n");
        printf("2 - Retirar FINAL\n");
        printf("3 - Mostrar lista\n");
        printf("4 - Liberar lista inteira do FINAL\n");
        printf("0 - Sair\n");
        scanf("%d", &op); // leitura da opcao informada

        switch (op)
        {
        case 1:
            insereFinal(lista);
            break;
        case 2:
            retiraFinal(lista);
            break;
        case 3:
            exibe(lista);
            break;
        case 4:
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