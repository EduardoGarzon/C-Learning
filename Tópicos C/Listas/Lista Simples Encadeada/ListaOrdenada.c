/*
    Implementar uma lista com insercao ordenada e
    exlcusao de elementos escolhida pelo usuario.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node // nome da estrura
{
    int num;           // dados
    struct Node *prox; // ponteiro de proximo elemento da lista (+1)
};

typedef struct Node node; // renomeando a estrutura
typedef node *LISTA;      // ponteiro da estrutura para o inicio da lista

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

void ordenar(LISTA *lista)
{
    int cont, aux;
    node *tmp;

    if ((*lista) == NULL)
    {
        printf("Lista Vazia!\n");
    }
    else
    {
        do
        {
            cont = 0;     // flag que indica mudanca de posicao
            tmp = *lista; // tmp recebe a cabeca da lista

            while (tmp->prox != NULL) // enquanto o proximo for diferente de NULL
            {
                // se o dado atual for maior que o proximo dado
                if (tmp->num > tmp->prox->num)
                {
                    aux = tmp->num;            // auxiliar recebe o dado atual
                    tmp->num = tmp->prox->num; // dado atual recebe o proximo dado
                    tmp->prox->num = aux;      // proximo dado recebe o dado atual em aux
                    cont++;                    // incrementa indicando que ouve mudanca
                }
                tmp = tmp->prox; // tmp pula para a proxima posicao
            }

        } while (cont != 0); // repete enquanto continuar mudando de posicao
    }
}

void inserir(LISTA *lista) // funcao recebe o ponteiro do inicio
{
    node *tmp, *antaux;
    tmp = *lista; // tmp receve o ponteiro inicial da lista

    node *novo = (node *)malloc(sizeof(node)); // novo espaco para *novo do tipo node

    if (novo == NULL) // teste na alocacao
    {
        printf("Erro na alocacao!\n");
        exit(0);
    }

    printf("Informe o valor da nova posicao: ");
    scanf("%d", &novo->num); // leitura do valor para o novo espaco alocado

    if ((*lista == NULL)) // insere no inicio de uma lista vazia
    {
        novo->prox = (*lista); // ponteiro para o proximo recebe o NULL de *lista
        *lista = novo;         // ponteiro *lista aponta para novo
    }
    else if (novo->num < (*lista)->num) // insere no inicio com lista de apenas 1 elemento
    {
        novo->prox = tmp; // novo elemento aponta para o primeiro elemento apontado por tmp
        *lista = novo;    // ponteiro inicial da lista aponta para novo
    }
    else
    {
        // percorre a lista ate o final ou ate que o novo seja menor que o proximo
        while (novo->num > tmp->num && tmp->prox != NULL)
        {
            antaux = tmp;    // guardo o elemento anterior ao atual
            tmp = tmp->prox; // pula para os proximos elementos guardando o atual
        }
        if (novo->num > tmp->num && tmp->prox == NULL) // insere no final da lista
        {
            novo->prox = NULL; // proximo do novo recebe null
            tmp->prox = novo;  // ultimo elemento aponta para o novo ultimo
        }
        if (novo->num < tmp->num && novo->num > antaux->num) // insere no meio da lista
        {
            antaux->prox = novo; // valor anterior aponta para o novo
            novo->prox = tmp;    // novo aponta para o proximo
        }
    }
}

void remover(LISTA *lista)
{
    node *tmp, *ant;
    int *aux;
    int valor = 0;

    printf("Informe o valor que deseja remover da lista: ");
    scanf("%d", &valor);

    if ((*lista) == NULL)
    {
        printf("Lista Vazia!\n");
    }
    else
    {
        // lista com apenas um elemento
        if ((*lista)->prox == NULL && (*lista)->num == valor)
        {
            tmp = *lista;
            (*lista) = (*lista)->prox;

            free(tmp);
        }
        else if ((*lista)->prox != NULL)
        {
            tmp = *lista;

            while (tmp->prox != NULL)
            {
                if (tmp->num == valor)
                {
                    if ((*lista)->num == tmp->num) // remove primeiro elemento
                    {
                        tmp = *lista;
                        (*lista) = (*lista)->prox;

                        free(tmp);

                        tmp = *lista;
                        ant = *lista;
                    }
                    else // remove elementos do meio
                    {
                        aux = tmp;
                        tmp = tmp->prox;
                        ant->prox = tmp;

                        free(aux);
                    }
                }
                else
                {
                    ant = tmp;
                    tmp = tmp->prox;
                }
            }
            if (tmp->prox == NULL && tmp->num == valor) // remove elemento final
            {
                ant->prox = NULL;

                free(tmp);
            }
        }
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
            printf("%5d", tmp->num);
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
    int op = -1;

    do
    {
        printf("O que deseja: \n"); // Menu de opcoes da lista
        printf("1 - Inserir ordenado\n");
        printf("2 - Remover elemento\n");
        printf("3 - Mostrar lista\n");
        printf("4 - Liberar toda lista\n");
        printf("0 - Sair\n");
        scanf("%d", &op); // leitura da opcao informada
        getchar();

        switch (op)
        {
        case 1:
            inserir(lista); // chamada da funcao para inserir elemento na lista
            break;
        case 2:
            remover(lista);
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