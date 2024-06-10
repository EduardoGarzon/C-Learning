/*
    Exemplo de lista simples circular
*/

#include <stdio.h>
#include <stdlib.h>

/*
    No
*/
typedef struct no
{
    int valor;
    struct no *proximo;
} No;

/*
    Header
*/
typedef struct
{
    No *inicio; // aponta para inicio da lista
    No *fim;    // aponta para fim da lista
    int tam;
} Lista;

void criar_lista(Lista *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

// procedimento para inserir no início
void inserir_no_inicio(Lista *lista, int num)
{
    No *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;             // valor = numero
        novo->proximo = lista->inicio; // novo -> inicio (NULL)
        lista->inicio = novo;          // inicio -> novo

        if (lista->fim == NULL)
            lista->fim = novo; // fim -> novo

        lista->fim->proximo = lista->inicio; // ultimo elemento -> inicio (circular)
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no fim
void inserir_no_fim(Lista *lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;

        // é o primeiro?
        if (lista->inicio == NULL)
        {
            lista->inicio = novo;                // inicio -> novo
            lista->fim = novo;                   // fim -> novo
            lista->fim->proximo = lista->inicio; // ultimo elemento -> inicio (circular)
        }
        else
        {
            lista->fim->proximo = novo; // ultimo elemento -> novo
            lista->fim = novo;          // fim -> novo
            // as duas linhas a seguir são sinônimas.
            // Escolha a que achar mais fácil compreender
            // lista->fim->proximo = lista->inicio;
            novo->proximo = lista->inicio; // ultimo elemento -> inicio (circular)
        }

        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir ordenado
void inserir_ordenado(Lista *lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;

        // se lista vazia, insere primeiro elemento
        if (lista->inicio == NULL)
        {
            inserir_no_inicio(lista, num);
        }
        else if (novo->valor < lista->inicio->valor) // se for menor que o primeiro valor
        {
            inserir_no_inicio(lista, num);
        }
        else
        {
            aux = lista->inicio; // aux -> inicio

            // percorre enquanto nao fizer a volta circular e
            // o novo valor for maior que o atual
            while (aux->proximo != lista->inicio && novo->valor > aux->proximo->valor)
                aux = aux->proximo;

            // se o proximo elemento for o inicio da lista
            if (aux->proximo == lista->inicio)
                inserir_no_fim(lista, num); // proximo -> inicio?
            // insere no final, antes de girar a lista para o inicio
            else
            {
                novo->proximo = aux->proximo;
                aux->proximo = novo;
                lista->tam++;

                // header -> v1 -> v2 -> v3 -> v1
                // header -> v1 -> v2 -> novo -> v3 -> v1
            }
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// função para remover um nó
No *remover(Lista *lista, int num)
{
    No *aux, *remover = NULL;

    // verifica se lista nao esta vazia
    if (lista->inicio)
    {
        // se apenas um elemeno na lista
        if (lista->inicio == lista->fim && lista->inicio->valor == num)
        {
            remover = lista->inicio; // remover -> novo
            lista->inicio = NULL;
            lista->fim = NULL;
            lista->tam--;
        }
        else if (lista->inicio->valor == num) // senao se o primeiro for o valor
        {
            // lista -> novo -> v1 -> novo
            remover = lista->inicio;             // remover -> novo
            lista->inicio = remover->proximo;    // inicio -> v1
            lista->fim->proximo = lista->inicio; // fim -> v1
            lista->tam--;

            // lista -> v1 -> v1
        }
        else
        {
            aux = lista->inicio; // aux -> inicio

            // percorre enquanto nao girar a lista e
            // enquanto o valor procurado for diferente do atual
            while (aux->proximo != lista->inicio && aux->proximo->valor != num)
                aux = aux->proximo;
            if (aux->proximo->valor == num)
            {
                if (lista->fim == aux->proximo) // é o ultimo elemento da lista?
                {
                    // header -> v1 -> v2 -> v3 -> novo -> v1

                    remover = aux->proximo;          // remover -> novo
                    aux->proximo = remover->proximo; // v3 -> v1
                    lista->fim = aux;                // fim -> v3

                    // header -> v1 -> v2 -> v3 -> v1
                }
                else // senao estiver no final
                {
                    // header -> v1 -> novo -> v2 -> v3 -> v1

                    remover = aux->proximo;          // remover -> novo
                    aux->proximo = remover->proximo; // v1 -> v2

                    // header -> v1 -> v2 -> v3 -> v1
                }

                lista->tam--;
            }
        }
    }

    return remover;
}

// função para buscar um valor
No *buscar(Lista *lista, int num)
{
    No *aux = lista->inicio; // aux -> inicio (primeiro elemento)

    if (aux) // enquanto existir elemento
    {
        do
        {
            if (aux->valor == num)
                return aux;
            aux = aux->proximo;
        } while (aux != lista->inicio); // faz enquanto nao girar a lista
    }

    return NULL;
}

// procedimento para imprimir a lista circular
void imprimir(Lista lista)
{
    No *no = lista.inicio;

    printf("\n\tLista tamanho %d: ", lista.tam);

    if (no)
    {
        do
        {
            printf("%d ", no->valor);
            no = no->proximo;
        } while (no != lista.inicio); // faz enquanto nao girar a lista

        printf("\n\tInicio: %d\n", no->valor);
    }

    printf("\n\n");
}

void limpa_Tela()
{
    system("cls");
}

int main()
{

    int opcao, valor, anterior;
    // No *lista = NULL;
    Lista lista;
    No *removido;

    criar_lista(&lista);

    do
    {
        limpa_Tela();

        printf("\n\n\n\t0 - Encerrar Programa\n\t1 - Inserir no Inicio\n\t2 - inserir no Final\n\t3 - Inserir Ordenado\n\t4 - Remover Elemento\n\t5 - Imprimir Lista\n\t6 - Buscar Elemento\n");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            limpa_Tela();

            printf("Digite um valor: ");
            scanf("%d", &valor);
            fflush(stdin);

            inserir_no_inicio(&lista, valor);

            break;
        case 2:
            limpa_Tela();

            printf("Digite um valor: ");
            scanf("%d", &valor);
            fflush(stdin);

            inserir_no_fim(&lista, valor);

            break;
        case 3:
            limpa_Tela();

            printf("Digite um valor: ");
            scanf("%d", &valor);
            fflush(stdin);

            inserir_ordenado(&lista, valor);

            break;
        case 4:
            limpa_Tela();

            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            fflush(stdin);

            removido = remover(&lista, valor);

            if (removido)
            {
                printf("Elemento removido: %d\n", removido->valor);
                free(removido);
            }
            else
                printf("elemento inesistente!\n");

            printf("\n\nTecle ENTER para prosseguir...");
            getchar();

            break;
        case 5:
            limpa_Tela();

            imprimir(lista);

            printf("\n\nTecle ENTER para prosseguir...");
            getchar();

            break;
        case 6:
            limpa_Tela();

            printf("Digite um valor a ser buscado: ");
            scanf("%d", &valor);
            fflush(stdin);

            removido = buscar(&lista, valor);

            if (removido)
                printf("Valor encontrado: %d\n", removido->valor);
            else
                printf("Valor nao encontrado!\n");

            printf("\n\nTecle ENTER para prosseguir...");
            getchar();

            break;
        default:
            limpa_Tela();

            if (opcao != 0)
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    system("pause");
    return 0;
}