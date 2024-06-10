/*
    Implementacao de uma lista duplamente encadeada
*/

#include <stdio.h>
#include <stdlib.h>

/* Header */
struct Node
{
    int valor;
    struct Node *proximo;  // ponteiro para o proximo no
    struct Node *anterior; // ponteiro para o no anterior
};
typedef struct Node node; // renomeando struct
typedef node *LISTA;      // ponteiro header

// Funcao que inicia a listaDE
LISTA *criarLista()
{
    LISTA *inicio = (LISTA *)malloc(sizeof(LISTA));

    if (inicio)
    {
        *inicio = NULL;

        printf("Lista criada com sucesso!\n");
        getchar();
    }
    else
    {
        printf("Erro ao criar lista!\n");
        getchar();
        exit(1);
    }

    return inicio;
}

// Procedimento para inserir no inicio da listaDE
void insereInicio(LISTA *lista)
{
    node *novo = (node *)malloc(sizeof(node));
    if (novo)
    {
        printf("Informe o valor: ");
        scanf("%d", &novo->valor);
        getchar();

        novo->proximo = (*lista);
        novo->anterior = NULL;

        if ((*lista))
        {
            (*lista)->anterior = novo;
        }

        (*lista) = novo;

        printf("Elemento adicionado no inicio!\n");
        getchar();
    }
    else
    {
        printf("Erro ao alocar novo no!\n");
        getchar();
        exit(1);
    }
}

// Procedimento para inserir no final da listaDE
void inserirFinal(LISTA *lista)
{
    node *novo = (node *)malloc(sizeof(node));
    if (novo)
    {
        printf("Informe o valor: ");
        scanf("%d", &novo->valor);
        getchar();

        novo->proximo = NULL;

        if ((*lista))
        {
            node *aux = (*lista);
            while (aux->proximo != NULL)
            {
                aux = aux->proximo;
            }

            aux->proximo = novo;
            novo->anterior = aux;
        }
        else
        {
            (*lista) = novo;
            novo->anterior = NULL;
        }

        printf("Elemento adicionado no final da lista!\n");
        getchar();
    }
    else
    {
        printf("Erro ao alocar novo no!\n");
        getchar();
        exit(1);
    }
}

// Procedimento para inserir no meio da listaDE
void inserirMeio(LISTA *lista)
{
    node *novo = (node *)malloc(sizeof(node)); // aloca novo no

    if (novo) // testa alocacao
    {
        printf("Informe o valor: ");
        scanf("%d", &novo->valor);
        getchar();

        if ((*lista)) // se lista com elemento(s)
        {
            node *aux = (*lista);
            if (!aux->proximo) // se apenas um elemento na lista
            {
                aux->proximo = novo; // adiciona novo no ao final da lista
                novo->proximo = NULL;
                novo->anterior = aux;
            }
            else
            {
                int tamanho = 0;
                while (aux) // percorre a lista ate o final
                {
                    aux = aux->proximo;
                    tamanho++; // incrementa tamanho da lista
                }

                tamanho = tamanho / 2;     // divide o tamanho da lista para calcular o meio
                int index = 1;             // indice para percorrer ate o meio da lista
                aux = (*lista);            // reseta no aux
                node *next = aux->proximo; // recebe o proximo do atual

                while (index < tamanho) // percorre ate o meio da lista
                {
                    aux = aux->proximo;  // avanca o atual
                    next = aux->proximo; // avanco o para o proximo do atual
                    index++;
                }

                aux->proximo = novo; // atual recebe o novo no
                novo->anterior = aux;
                novo->proximo = next; // novo no recebe o proximo do atual
                next->anterior = novo;
            }
        }
        else // se lista vazia
        {
            novo->proximo = (*lista); // proximo recebe NULL
            novo->anterior = NULL;
            (*lista) = novo; // header recebe o novo
        }

        printf("Elemento inserido no meio da lista!\n");
        getchar();
    }
    else
    {
        printf("Erro ao alocar novo no!\n");
        getchar();
        exit(1);
    }
}

// Procedimento para exibir a listaDE
void exibirLista(LISTA *lista)
{
    if ((*lista))
    {
        node *aux = (*lista);
        printf("ListaDE: ");
        while (aux)
        {
            printf("%d <-> ", aux->valor);
            aux = aux->proximo;
        }
        getchar();
    }
    else
    {
        printf("Lista Vazia!\n");
        getchar();
    }
}

// Procedimento para imprimir listaDE a partir do fim
void exibirListaFim(LISTA *lista)
{
    if ((*lista))
    {
        node *aux = (*lista);
        while (aux->proximo)
        {
            aux = aux->proximo;
        }
        printf("ListaDE [FIM -> INICIO]: ");
        while (aux != NULL)
        {
            printf("%d <-> ", aux->valor);
            aux = aux->anterior;
        }

        getchar();
    }
    else
    {
        printf("Lista Vazia!\n");
        getchar();
    }
}

// Procedimento para liberar a listaDE
void liberarLista(LISTA *lista)
{
    if (lista)
    {
        node *aux = (*lista);
        while (aux)
        {
            (*lista) = (*lista)->proximo;
            free(aux);
            aux = (*lista);
        }
        printf("Lista liberada!\n");
        getchar();
    }
    else
    {
        printf("Lista Vazia!\n");
        getchar();
    }
}

// Procedimento para remover do inicio da listaDE
void removerInicio(LISTA *lista)
{
    if (lista)
    {
        node *aux = (*lista);
        (*lista) = (*lista)->proximo;
        (*lista)->anterior = NULL;
        free(aux);

        printf("Elemento removido do inicio!\n");
        getchar();
    }
    else
    {
        printf("Lista Vazia!\n");
        getchar();
    }
}

// Procedimento para remover do final da listaDE
void removerFinal(LISTA *lista)
{
    if ((*lista))
    {
        node *aux = (*lista);
        while (aux->proximo)
        {
            aux = aux->proximo;
        }
        aux->anterior->proximo = NULL;
        free(aux);

        printf("Elemento removido do final!\n");
        getchar();
    }
    else
    {
        printf("Lista Vazia!\n");
        getchar();
    }
}

// Funcao para remover um elemento buscado da listaDE
int removerBusca(LISTA *lista)
{
    if ((*lista)) // verifica se lista possui elementos
    {
        int elemento = 0;
        printf("Informe o valor: ");
        scanf("%d", &elemento);
        getchar();

        node *aux = (*lista); // recebe o inicio da lista

        if (!aux->proximo) // verifica se lista possui apenas um elemento
        {
            if (aux->valor == elemento) // se o atual for igual ao elemento procurado
            {
                (*lista) = NULL; // header recebe NULL
                free(aux);       // desaloca o atual
                return elemento;
            }
        }
        else if (aux->valor == elemento) // se lista possui mais elementos verifica se 'e o primeiro
        {
            (*lista) = (*lista)->proximo;
            (*lista)->anterior = NULL;
            free(aux);
            return elemento;
        }
        else // se lista maior que 1 e nao 'e o primeiro elemento
        {
            while (aux && (aux->valor != elemento))
            {
                aux = aux->proximo;
            }

            if (aux)
            {
                if (aux->proximo)
                {
                    aux->anterior->proximo = aux->proximo;
                    aux->proximo->anterior = aux->anterior;
                    free(aux);
                }
                else
                {
                    aux->anterior->proximo = NULL;
                    free(aux);
                }

                return elemento;
            }
        }
        return 0;
    }
    else
    {
        printf("Lista Vazia!\n");
        getchar();
    }
}

// Funcao para retornar o elemento buscado na listaDE
int buscarElemento(LISTA *lista)
{
    if ((*lista))
    {
        int dado = 0;
        printf("Informe o valor: ");
        scanf("%d", &dado);
        getchar();

        node *aux = (*lista);
        while (aux && (aux->valor != dado))
        {
            aux = aux->proximo;
        }

        if (aux)
        {
            return aux->valor;
        }
    }
    else
    {
        printf("Lista Vazia!\n");
        getchar();
    }
    return 0;
}

// Procedimento para ordenar a listaDE por BubbleSort
void ordenarLista(LISTA *lista)
{
    if (lista)
    {
        int trocou = 0;              // variavel de controle para trocas
        node *atual = (*lista);      // atual recebe o inicio da lista
        node *next = atual->proximo; // next recebe o proximo do atual
        do
        {
            trocou = 0;  // sem trocas
            while (next) // enquanto existir um proximo elemento
            {
                if (atual->valor > next->valor) // se o atual for maior que o proximo
                {
                    int tmp = atual->valor;     // variavel temporaria recebe o dado atual
                    atual->valor = next->valor; // atual recebe o seu proximo dado
                    next->valor = tmp;          // proximo recebe o atual
                    trocou = 1;                 // trocou
                }
                // avanca ponteiros
                atual = atual->proximo; // atual avanca para o proximo
                next = atual->proximo;  // avanca para o proximo do novo atual
            }
            // reseta ponteiros
            atual = (*lista);      // atual recebe o inicio da lista novamente
            next = atual->proximo; // next recebe o proximo do atual
        } while (trocou == 1);     // repete o ciclo enquanto ocorrerem trocas

        printf("Lista ordenada com sucesso!\n");
        getchar();
    }
    else
    {
        printf("Lista Vazia!\n");
        getchar();
    }
}

// Procedimento para o menu de opcoes da listaDE
void menu()
{
    LISTA *lista;
    lista = criarLista();

    int op = 0, removido = 0, retorno = 0;

    do
    {
        system("cls");

        printf("[0]  -> Sair\n");
        printf("[1]  -> Inserir no Inicio\n");
        printf("[2]  -> Inserir no Final\n");
        printf("[3]  -> Inserir no Meio\n");
        printf("[4]  -> Exibir Lista [Inicio -> Final]\n");
        printf("[5]  -> Exibir Lista [Final -> Inicio]\n");
        printf("[6]  -> Exibir Lista Crescente\n");
        printf("[7]  -> Exibir Lista Decrescente\n");
        printf("[8]  -> Liberar Lista\n");
        printf("[9]  -> Remover do Inicio\n");
        printf("[10] -> Remover do Final\n");
        printf("[11] -> Remover por Busca\n");
        printf("[12] -> Buscar Elemento\n");
        printf("[13] -> Ordenar Lista [BubbleSort]\n");
        scanf("%d", &op);
        getchar();

        printf("\n\n");

        switch (op)
        {
        case 0:
            printf("Encerrando Programa!\n");
            break;
        case 1:
            insereInicio(lista);
            break;
        case 2:
            inserirFinal(lista);
            break;
        case 3:
            inserirMeio(lista);
            break;
        case 4:
            exibirLista(lista);
            break;
        case 5:
            exibirListaFim(lista);
            break;
        case 6:
            ordenarLista(lista);
            exibirLista(lista);
            break;
        case 7:
            ordenarLista(lista);
            exibirListaFim(lista);
            break;
        case 8:
            liberarLista(lista);
            break;
        case 9:
            removerInicio(lista);
            break;
        case 10:
            removerFinal(lista);
            break;
        case 11:
            removido = removerBusca(lista);
            if (removido)
            {
                printf("Elemento %d removido com sucesso!\n", removido);
            }
            else
            {
                printf("Elemento nao encontrado!\n");
            }
            getchar();
            break;
        case 12:
            retorno = buscarElemento(lista);
            if (retorno)
            {
                printf("Elemento %d encontrado!\n", retorno);
            }
            else
            {
                printf("Elemento nao encontrado!\n");
            }
            getchar();
            break;
        case 13:
            ordenarLista(lista);
            break;
        default:
            printf("Opcao Invalida!\n");
            break;
        }

    } while (op != 0);
}

int main()
{
    menu();

    system("pause");
    return 0;
}
