/*
    Seja uma lista dinâmica e encadeada com elementos repetidos,
    implemente uma rotina para eliminar todas as ocorrências de X da lista.
*/

#include <stdio.h>
#include <stdlib.h>

// Criacao da Estrutura/Header da lista
struct Node
{                         // Tipo do elemento da lista
    int dado;             // dado que a lista armazena
    struct Node *proximo; // ponteiro do tipo da lista para o proximo no
};
typedef struct Node node; // renomeando o tipo, apelido
typedef node *LISTA;      // declaracao do ponteiro da Header da lista

// Funcao para criar a lista, declaracao do Header
LISTA *criarLista()
{
    LISTA *inicio = (LISTA *)malloc(sizeof(LISTA)); // aloca header da lista
    if (inicio != NULL)
    {
        *inicio = NULL; // header é NULL
    }
    else
    {
        printf("Erro ao alocar o header da lista!\n");
        exit(0);
    }
    return inicio; // retorna o header alocado
}

// Procedimento para inserir no inicio da lista
void insereInicio(LISTA *lista)
{
    node *novo = (node *)malloc(sizeof(node)); // declara novo no e aloca
    if (novo == NULL)
    {
        printf("Erro ao alocar novo no!\n");
        exit(0);
    }

    printf("Informe o valor do novo elemento: ");
    scanf("%d", &novo->dado); // leitura do novo elemento
    getchar();                // retira o \n do buffer

    novo->proximo = (*lista); // proximo do novo aponta para o antigo atual
    (*lista) = novo;          // inicio da lista recebe o novo
}

// Procedimento para inserir no final da lista
void insereFinal(LISTA *lista)
{
    node *novo = (node *)malloc(sizeof(node)); // declara e aloca novo no
    if (novo == NULL)
    {
        printf("Erro ao alocar novo no!\n");
        exit(0);
    }

    printf("Informe o valor do novo elemento: ");
    scanf("%d", &novo->dado);
    getchar();

    novo->proximo = NULL;

    if ((*lista) == NULL) // insere no inicio se lista vazia
    {
        *lista = novo;
    }
    else
    {
        node *tmp;
        tmp = (*lista);              // no temporario recebe o header
        while (tmp->proximo != NULL) // avanca ate o final da lista
        {
            tmp = tmp->proximo;
        }
        tmp->proximo = novo; // final da lista recebe o novo no
    }
}

// Procedimento para exibir os elementos da lista
void exibeLista(LISTA *lista)
{
    if ((*lista) == NULL)
    {
        printf("LISTA VAZIA!\n");
    }
    else
    {
        node *tmp;
        tmp = (*lista); // no temporario recebe o header

        printf("<-------------------------->\n");
        printf("    ELEMENTOS DA LISTA:     \n");
        printf("<-------------------------->\n\n");
        printf("|INICIO: ");
        while (tmp != NULL) // enquanto existir elementos
        {
            printf("%d -> ", tmp->dado); // imprime o atual
            tmp = tmp->proximo;          // avanca para o proximo
        }
        printf("FIM|\n");
    }
}

// Procedimento para deslocar todos os elementos da lista a partir do inicio
void liberaLista(LISTA *lista)
{
    if ((*lista) == NULL)
    {
        printf("LISTA VAZIA!\n");
    }
    else
    {
        node *tmp;
        while ((*lista) != NULL) // avanca enquanto existir elementos na lista
        {
            tmp = (*lista);               // recebe o elemento do inicio
            (*lista) = (*lista)->proximo; // header aponta para o proximo
            free(tmp);                    // desaloca o elemento inicial
        }
        (*lista) = NULL; // header é NULO

        printf("Lista liberada com sucesso!\n");
    }
}

// Funcao para remover um elemento do inicio da lista
void removeInicio(LISTA *lista)
{
    if ((*lista) != NULL)
    {
        node *tmp;
        tmp = (*lista);          // no temporario recebe o inicio da lista
        (*lista) = tmp->proximo; // header avanca para o proximo
        free(tmp);               // libera o no inicial
        printf("Elemento removido com sucesso!\n");
    }
    else
    {
        printf("LISTA VAZIA!\n");
    }
}

// Funcao para remover um elemento do final da lista
void removeFinal(LISTA *lista)
{
    node *noAnterior, *tmp;
    tmp = (*lista); // no teporario recebe o header

    if ((lista) != NULL && tmp->proximo == NULL) // verifica se existe apenas um elemento na lista
    {
        (*lista) = NULL; // header é nulo
        free(tmp);       // desaloca tmp
        printf("Elemento removido com sucesso!\n");
    }
    else if ((*lista) != NULL) // se lista possuir mais elementos
    {
        while (tmp->proximo != NULL) // avanca ate chegar no final da lista
        {
            noAnterior = tmp;   // salva o no atual
            tmp = tmp->proximo; // atual avanca para seu proximo
        }
        noAnterior->proximo = NULL; // proximo do anterior recebe NULL
        free(tmp);                  // desaloca o atual
        printf("Elemento removido com sucesso!\n");
    }
    else
    {
        printf("LISTA VAZIA!\n");
    }
}

// Funcao para remover elementos repetidos da lista
void removeRepeticoes(LISTA *lista)
{
    if (*lista)
    {
        if (!(*lista)->proximo)
        {
            printf("Lista com unico elemento!\n");
        }
        else
        {
            node *comparado = *lista;
            while (comparado)
            {
                node *atual = comparado->proximo;
                node *anterior = comparado;

                while (atual)
                {
                    if (atual->dado == comparado->dado)
                    {
                        node *tmp = atual;
                        atual = atual->proximo;
                        anterior->proximo = atual;
                        free(tmp);
                    }
                    else
                    {
                        anterior = atual;
                        atual = atual->proximo;
                    }
                }
                comparado = comparado->proximo;
            }
            printf("Elementos Repetidos Removidos com Sucesso!\n");
        }
    }
    else
    {
        printf("Lista Vazia!\n");
    }
}

int main()
{
    system("cls");

    LISTA *lista;
    lista = criarLista();

    printf("Lista criada com sucesso!\n");
    getchar();

    int op = 0;

    do
    {
        system("cls");
        printf("[1] -> Inserir Inicio   \n");
        printf("[2] -> Inserir Final    \n");
        printf("[3] -> Remover Inicio   \n");
        printf("[4] -> Remover Final    \n");
        printf("[5] -> Liberar Lista    \n");
        printf("[6] -> Exibir Lista     \n");
        printf("[7] -> Remove Repeticoes\n");
        printf("[0] -> Encerrar Programa\n");
        scanf("%d", &op);
        getchar();
        system("cls");

        switch (op)
        {
        case 0:
            printf("Encerrando Programa!\n");
            break;
        case 1:
            insereInicio(lista);
            getchar();
            break;
        case 2:
            insereFinal(lista);
            getchar();
            break;
        case 3:
            removeInicio(lista);
            getchar();
            break;
        case 4:
            removeFinal(lista);
            getchar();
            break;
        case 5:
            liberaLista(lista);
            getchar();
            break;
        case 6:
            exibeLista(lista);
            getchar();
            break;
        case 7:
            removeRepeticoes(lista);
            getchar();
            break;
        default:
            printf("Opcao Invalida!\n");
            break;
        }
    } while (op != 0);

    system("pause");
    return 0;
}