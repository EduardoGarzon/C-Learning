/*
    Segunda versao da lista simplesmente encadeada que nao utiliza ponteiro para ponteiro.
*/

#include <stdio.h>
#include <stdlib.h>

/*
    Estrutura no.
    ELEMENTOS
*/
typedef struct no
{
    int valor;          // dado
    struct no *proximo; // ponteiro para proximo no
} No;

/*
    Estrutura lista.
    HEADER
*/
typedef struct
{
    No *inicio; // ponteiro para o primeiro no da lista
    int tam;    // tamanho da lista
} Lista;

/*
    Funcao que inicializa lista
*/
void criar_lista(Lista *lista)
{
    // lista vazia, inicio nulo e tamanho zero
    lista->inicio = NULL;
    lista->tam = 0;
}

// procedimento para inserir no início
void inserir_no_inicio(Lista *lista, int num)
{
    No *novo = malloc(sizeof(No)); // aloca no

    // verifica alocacao do novo no
    if (novo)
    {
        novo->valor = num;             // atribui valor
        novo->proximo = lista->inicio; // recebe NULL na primeira iteracao
        lista->inicio = novo;          // recebe o novo no alocado
        lista->tam++;                  // incrementa tamanho
        // Lista (header) -> No *inicio (novo) -> No *inicio->proximo == NULL
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
        // novo(num) -->(proximo) == NULL
        novo->valor = num;
        novo->proximo = NULL;

        // é o primeiro?
        if (lista->inicio == NULL) // lista(header) -> inicio(no) == NULL
            lista->inicio = novo;  // lista(header) -> inicio(no) == novo
        else
        {
            aux = lista->inicio; // aux(no) == lista(header) -> inicio(no)
            while (aux->proximo) // proximo != NULL
                aux = aux->proximo;
            aux->proximo = novo; // aux->proximo == NULL
            // aux->proximo = novo(no)
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no meio
void inserir_no_meio(Lista *lista, int num, int ant)
{
    No *aux, *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;

        // é o primeiro?
        if (lista->inicio == NULL)
        {
            novo->proximo = NULL;
            lista->inicio = novo;
        }
        else
        {
            aux = lista->inicio;
            // percorre enquanto o dado do elemento da lista for diferente da referencia
            // e o elemento atual tiver um proximo elemento.
            // percorre ate a referencia ou ate o final da lista
            while (aux->valor != ant && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
            // aux -> novo -> proximo ou NULL
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

/*
     Procedimento para inserir ordenado
*/
void inserir_ordenado(Lista *lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));

    // verifica alocacao
    if (novo)
    {
        novo->valor = num;
        // verifica se lista esta vazia
        if (lista->inicio == NULL)
        {
            novo->proximo = NULL;
            lista->inicio = novo;
            // antes header -> NULL depois header -> 1 -> NULL
        }
        else if (novo->valor < lista->inicio->valor) // verifica se é o primeiro elemento
        {
            novo->proximo = lista->inicio;
            lista->inicio = novo;
            // antes header -> 3 -> NULL depois header -> 1 -> 3 -> NULL
        }
        else
        {
            aux = lista->inicio;
            // percorre ate o final ou enquanto o elemento for maior ou igual ao atual
            while (aux->proximo && novo->valor >= aux->proximo->valor)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
            // antes header -> 1 -> 2 -> 10 -> NULL depois header -> 1 -> 2 -> novo -> 10 -> NULL
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

/*
    Função para remover um nó da lista
*/
No *remover(Lista *lista, int num)
{
    No *aux, *remover = NULL;

    // verifica se lista esta vazia
    if (lista->inicio)
    {
        // verifica se o primeiro elemento é o procurado
        if (lista->inicio->valor == num)
        {
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->tam--;
            // antes header -> 1 -> NULL depois header -> NULL
        }
        else
        {
            aux = lista->inicio;
            // percorre a lista ate o final e enquanto nao encontrar o elemento procurado
            while (aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if (aux->proximo)
            {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                lista->tam--;
                // antes header -> 1 -> 2 -> 3 -> NULL, depois header -> 1 -> 3 -> NULL
                // antes header -> 1 -> 2 -> 3 -> NULL, depois header -> 1 -> 2 -> NULL
            }
        }
    }

    return remover;
}

/*
      Função para buscar um elemento na lista
*/
No *buscar(Lista *lista, int num)
{
    No *aux, *no = NULL;

    aux = lista->inicio;
    while (aux && aux->valor != num)
        aux = aux->proximo;
    if (aux)
        no = aux;
    return no;
}

void imprimir(Lista lista)
{
    No *no = lista.inicio;
    printf("\n\tLista tam %d: ", lista.tam);
    while (no)
    {
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

int main()
{
    int opcao, valor, anterior;
    Lista lista; // No *lista = NULL;
    No *removido;

    criar_lista(&lista);

    do
    {
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - inserirF\n\t3 - InserirM\n\t4 - InserirO\n\t5 - Imprimir\n\t6 - Remover\n\t7 - Buscar\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_fim(&lista, valor);
            break;
        case 3:
            printf("Digite um valor e o valor de referencia: ");
            scanf("%d%d", &valor, &anterior);
            inserir_no_meio(&lista, valor, anterior);
            break;
        case 4:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_ordenado(&lista, valor);
            break;
        case 5:
            imprimir(lista);
            break;
        case 6:
            printf("Informe o valor a ser removido: ");
            scanf("%d", &valor);
            removido = remover(&lista, valor);
            if (removido)
            {
                printf("Elemento removido: %d", removido->valor);
                free(removido);
            }
            else
            {
                printf("\n\nFalha ao remover elemento.\n\n");
            }
            break;
        case 7:
            printf("Informe o valor a ser buscado: ");
            scanf("%d", &valor);
            removido = buscar(&lista, valor);
            if (removido)
            {
                printf("Elemento buscado encontrado: %d", removido->valor);
                free(removido);
            }
            else
            {
                printf("\n\nElemento nao encontrado.\n\n");
            }
            break;
        default:
            if (opcao != 0)
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}