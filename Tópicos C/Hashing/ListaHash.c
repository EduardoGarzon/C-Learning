#include <stdio.h>
#include <stdlib.h>

#define TAM 31

typedef struct no
{
    int chave;
    struct no *proximo;
} No;

typedef struct
{
    No *inicio;
    int tam;
} Lista;

Lista tabela[TAM];

void inicializarLista(Lista *l)
{
    l->inicio = NULL;
    l->tam = 0;
}

void inserir_na_lista(Lista *l, int valor)
{
    No *novo = malloc(sizeof(No));

    if (novo)
    {
        novo->chave = valor;
        novo->proximo = l->inicio;
        l->inicio = novo;
        l->tam++;
    }
    else
    {
        printf("\n\tErro ao alocar memoria!\n");
    }
}

int remover_da_lista(Lista *l, int chave, int id)
{
    No *aux = l->inicio;
    No *anterior = NULL;

    if (l->tam == 0)
    {
        printf("Posicao acessada no vetor: %d\n", id);
        printf("\tLista Vazia!\n");
        return 0;
    }
    else if (l->inicio->chave == chave)
    {
        l->inicio = aux->proximo;
        printf("\tPosicao acessada no vetor: %d\n", id);
        printf("\tElemento removido da lista: %d\n", aux->chave);
        free(aux);
        l->tam--;
        return 1;
    }
    else
    {
        while (aux != NULL && aux->chave != chave)
        {
            anterior = aux;
            aux = aux->proximo;
        }

        if (aux == NULL)
        {
            printf("Posicao acessada no vetor: %d\n", id);
            printf("\tElemento nao encontrado!\n");
            return 0;
        }

        anterior->proximo = aux->proximo;
        printf("\tPosicao acessada no vetor: %d\n", id);
        printf("\tElemento removido da lista: %d\n", aux->chave);
        free(aux);
        l->tam--;
        return 1;
    }
}

int buscar_na_lista(Lista *l, int valor)
{
    No *aux = l->inicio;
    while (aux != NULL && aux->chave != valor)
    {
        aux = aux->proximo;
    }
    if (aux != NULL)
    {
        return aux->chave;
    }
    return 0;
}

void imprimir_lista(Lista *l)
{
    No *aux = l->inicio;
    printf(" Tam: %d: ", l->tam);
    while (aux != NULL)
    {
        printf("%d ", aux->chave);
        aux = aux->proximo;
    }
}

void inicializarTabela(Lista t[])
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        inicializarLista(&t[i]);
    }
}

int funcaoHash(int chave)
{
    return chave % TAM;
}

void inserir(Lista t[], int valor)
{
    int id = funcaoHash(valor);
    inserir_na_lista(&t[id], valor);
}

int remover(Lista t[], int chave)
{
    int id = funcaoHash(chave);
    int result = remover_da_lista(&t[id], chave, id);
    return result;
}

int busca(Lista t[], int chave)
{
    int id = funcaoHash(chave);
    return buscar_na_lista(&t[id], chave);
}

void imprimir(Lista t[])
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        printf("%2d = ", i);
        imprimir_lista(&t[i]);
        printf("\n");
    }
}

void limpa_tela()
{
    system("cls");
}

void continuar()
{
    printf("\nTecle [ENTER] para continuar...");
    getchar();
}

void menu()
{
    int opcao, valor, retorno;

    do
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 -Imprimir\n\t4 - Remover\n");
        printf("\tInforme a opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);
        limpa_tela();

        switch (opcao)
        {
        case 1:
            printf("\tQual valor deseja inserir? ");
            scanf("%d", &valor);
            fflush(stdin);
            inserir(tabela, valor);
            continuar();
            limpa_tela();
            break;
        case 2:
            printf("\tQual valor deseja buscar? ");
            scanf("%d", &valor);
            fflush(stdin);
            retorno = busca(tabela, valor);
            if (retorno != 0)
            {
                printf("\tValor encontrado: %d\n", retorno);
            }
            else
            {
                printf("\tValor nao encontrado!\n");
            }
            continuar();
            limpa_tela();
            break;
        case 3:
            imprimir(tabela);
            continuar();
            limpa_tela();
            break;
        case 4:
            printf("\tInforme o valor que deseja remover: ");
            scanf("%d", &valor);
            fflush(stdin);
            retorno = remover(tabela, valor);
            if (retorno == 1)
            {
                printf("\tElemento removido!\n");
            }
            else
            {
                printf("\tFalha ao remover.\n");
            }
            continuar();
            limpa_tela();
            break;
        default:
            printf("\tOpcao invalida!\n");
            break;
        }
    } while (opcao != 0);
}

int main()
{
    inicializarTabela(tabela);
    menu();
    return 0;
}
