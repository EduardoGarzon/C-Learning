/*
    Escreva uma função que remove o k-ésimo nó da lista encadeada.
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

// Procedimento para remover o K-esimo elemento da lista
void removeKesimo(LISTA *lista)
{
    if ((*lista)) // verifica se lista possui elementos
    {
        int posicao = 0;
        printf("Informe a posicao que deseja remover: ");
        scanf("%d", &posicao);
        getchar();

        if (posicao > 0) // posicao deve ser positiva e maior que zero
        {
            if (posicao == 1) // remove no inicio se for a primeira posicao
            {
                node *tmp = (*lista);
                (*lista) = tmp->proximo;
                free(tmp);
            }
            else
            {
                node *atual = (*lista);
                node *anterior;
                // percorre pela lista ate o contador atingir a posicao
                for (int i = 1; i < posicao; i++)
                {
                    anterior = atual;
                    atual = atual->proximo;
                }

                // se ta posicao existir um elemento, remove
                if (atual != NULL)
                {
                    anterior->proximo = atual->proximo;
                    free(atual);

                    printf("Elemento removido com sucesso!\n");
                }
                else
                {
                    printf("Posicao Invalida!\n");
                }
            }
        }
        else
        {
            printf("Posicao Invalida!\n");
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
        printf("[3] -> Remover K-esimo  \n");
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
            exibeLista(lista);
            getchar();
            break;
        case 2:
            insereFinal(lista);
            exibeLista(lista);
            getchar();
            break;
        case 3:
            removeKesimo(lista);
            exibeLista(lista);
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