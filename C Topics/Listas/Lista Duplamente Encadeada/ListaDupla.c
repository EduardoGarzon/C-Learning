/*
    Exemplo de lista duplamente encadeado.
*/

#include <stdio.h>
#include <stdlib.h>

/*
    HEADER DA LISTA
*/
typedef struct no
{
    int valor;
    struct no *proximo;  // proximo nó
    struct no *anterior; // nó anterior
} No;

No *lista = NULL, *remover = NULL;
int op = -1, valor = 0, anterior = 0;

// procedimento para inserir no início
void inserir_Inicio(No **lista, int num)
{
    No *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        novo->proximo = *lista;
        novo->anterior = NULL;

        if (*lista)
            (*lista)->anterior = novo;
        *lista = novo;

        // <- header -> <- novo -> <- v1 -> NULL
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no fim
void inserir_Fim(No **lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        novo->proximo = NULL;

        // é o primeiro?
        if (*lista == NULL)
        {
            *lista = novo;
            novo->anterior = NULL;

            // NULL <- header -> NULL
        }
        else
        {
            aux = *lista;

            // percorre ate o ultimo elemento da lista
            while (aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
            novo->anterior = aux;

            // <- header -> <- v1 -> <- novo -> NULL
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no meio
void inserir_Meio(No **lista, int num, int ant)
{
    No *aux, *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        // é o primeiro?
        if (*lista == NULL)
        {
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;

            // <- header -> <- novo -> NULL
        }
        else
        {
            aux = *lista;

            // percorre ate o final ou enquanto o valor procurado for diferente do atual
            while (aux->valor != ant && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;

            // header -> <- v1 -> v2 -> NULL entao novo -> v2
            if (aux->proximo)
                aux->proximo->anterior = novo;
            novo->anterior = aux;
            aux->proximo = novo;

            // antes header -> v1 -> v2 -> NULL
            // depois <- header -> <- v1 -> <- novo -> <- v2 -> NULL
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir valor ordenado
void inserir_Ordenado(No **lista, int num)
{
    No *aux, *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->valor = num;
        // a lista está vazia?
        if (*lista == NULL)
        {
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;

            // <- header -> null <- novo -> null
        } // é o menor?
        else if (novo->valor < (*lista)->valor)
        {
            novo->proximo = *lista;
            (*lista)->anterior = novo;
            *lista = novo;

            // header <--> <- novo -> <- v1 -> NULL
        }
        else
        {
            aux = *lista;

            // percorre ate o final ou enquanto o valor for maior que o atual
            while (aux->proximo && novo->valor > aux->proximo->valor)
                aux = aux->proximo;
            novo->proximo = aux->proximo;

            if (aux->proximo)
                aux->proximo->anterior = novo;
            novo->anterior = aux;
            aux->proximo = novo;

            // header <--> <- v1 -> <- novo -> <- v2 -> NULL
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para remover elemento da lista
No *remover_Elemento(No **lista, int num)
{
    No *aux, *remover = NULL;

    // verifica se lista vazia
    if (*lista)
    {
        // verifica se primeiro elemento
        if ((*lista)->valor == num)
        {
            remover = *lista;
            *lista = remover->proximo;

            // verifica se existe proximo senao e NULL
            if (*lista)
                (*lista)->anterior = NULL;

            // antes header <--> <- v1 -> <- v2 ->NULL
            // depois header <--> <- v2 -> NULL
        }
        else
        {
            aux = *lista;

            // percorre ate o final ou enquanto o valor procurado for diferente do atual
            // compara com o proximo pois comeca no header
            while (aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if (aux->proximo)
            {
                remover = aux->proximo;           // recebe o proximo
                aux->proximo = remover->proximo;  // recebe o proximo do proximo
                if (aux->proximo)                 // verifica se o novo proximo é NULL
                    aux->proximo->anterior = aux; // se for elemento aponta para o anterior
            }

            // antes header <--> <- v1 -> <- v2 -> <- v3 -> NULL
            // depois header <--> <- v1 -> <- v2 -> NULL
        }
    }

    return remover;
}

// procedimento para buscar elemento na lista
No *buscar_Elemento(No **lista, int num)
{
    No *aux, *no = NULL;

    aux = *lista;
    while (aux && aux->valor != num)
        aux = aux->proximo;

    // verifica se é NULL ou elemento
    if (aux)
        no = aux;
    return no; // retorna NULL ou o elemento encontrado
}

// imprimir os elementos da lista
void imprimir_Lista(No *no)
{
    printf("\n\tLISTA: ");

    if (no)
    {
        while (no)
        {
            printf("%d ", no->valor);
            no = no->proximo;
        }
    }
    else
    {
        printf("\n\nLISTA VAZIA!\n\n");
    }

    printf("\n\n");
}

// retorna ponteiro para o último nó da lista para poder imprimir do final
No *ultimo(No **lista)
{
    No *aux = *lista;

    if (*lista)
    {
        while (aux->proximo)
            aux = aux->proximo;
    }
    else
    {
        printf("\n\nLISTA VAZIA!\n\n");
    }

    return aux;
}

// imprime a lista do fim para o início
// recebe um ponteiro para o último nó da lista
void imprimirContrario(No *no)
{
    printf("\n\tLista: ");

    while (no)
    {
        printf("%d ", no->valor);
        no = no->anterior;
    }

    printf("\n\n");
}

void capturar_Dados(int *v)
{
    printf("Informe um valor: ");
    scanf("%d", &(*v));
    fflush(stdin);
}

void limpa_Tela()
{
    system("cls");
}

void menu_Lista()
{

    limpa_Tela();

    printf("\n\n\tMENU DA LISTA ENCADEADA\n\n");
    printf("[0] Encerrar programa.\n");
    printf("[1] Inserir no Inicio da Lista.\n");
    printf("[2] Inserir no Final da Lista.\n");
    printf("[3] Inserir no Meio da Lista.\n");
    printf("[4] Inserir Ordenado na Lista.\n");
    printf("[5] Remover Elemento da Lista.\n");
    printf("[6] Buscar Elemento na Lista.\n");
    printf("[7] Imprimir Lista (Inicio -> Final)\n");
    printf("[8] Imprimir Lista (Final -> Inicio)\n");
    scanf("%d", &op);
    fflush(stdin);

    switch (op)
    {
    case 0:
        limpa_Tela();

        printf("\n\n\tEncerrando Programa...\n\n");
        free(lista);

        exit(0);

        break;
    case 1:
        limpa_Tela();

        capturar_Dados(&valor);
        inserir_Inicio(&lista, valor);

        menu_Lista();

        break;
    case 2:
        limpa_Tela();

        capturar_Dados(&valor);
        inserir_Fim(&lista, valor);

        menu_Lista();

        break;
    case 3:
        limpa_Tela();

        printf("informe o valor de referencia: ");
        scanf("%d", &anterior);
        getchar();

        capturar_Dados(&valor);
        inserir_Meio(&lista, valor, anterior);

        menu_Lista();

        break;
    case 4:
        limpa_Tela();

        capturar_Dados(&valor);
        inserir_Ordenado(&lista, valor);

        menu_Lista();

        break;
    case 5:
        limpa_Tela();
        capturar_Dados(&valor);

        remover = remover_Elemento(&lista, valor);

        if (remover)
        {
            printf("Elemento a ser removido: %d\n", remover->valor);
            free(remover);
        }
        else
            printf("\n\n\tElemento inexistente!\n\n");

        printf("\n\nTecle ENTER para prosseguir...");
        getchar();

        menu_Lista();

        break;
    case 6:
        limpa_Tela();

        capturar_Dados(&valor);

        remover = buscar_Elemento(&lista, valor);

        if (remover)
        {
            printf("Elemento Buscado: %d\n", remover->valor);
        }
        else
        {
            printf("\n\nElemento nao encontrado.\n\n");
        }

        printf("\n\nTecle ENTER para prosseguir...");
        getchar();

        menu_Lista();

        break;
    case 7:
        limpa_Tela();

        imprimir_Lista(lista);

        printf("\n\nTecle ENTER para prosseguir...");
        getchar();

        menu_Lista();

        break;
    case 8:
        limpa_Tela();
        imprimirContrario(ultimo(&lista));

        printf("\n\nTecle ENTER para prosseguir...");
        getchar();

        menu_Lista();

        break;
    default:
        break;
    }
}

int main()
{
    menu_Lista();

    system("pause");
    return 0;
}