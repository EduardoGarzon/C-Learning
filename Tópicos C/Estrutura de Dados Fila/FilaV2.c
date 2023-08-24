/*
    Estrutura FILA - Segunda versão
*/

#include <stdio.h>
#include <stdlib.h>

// Struct No
typedef struct no
{
    int valor;
    struct no *proximo; // Aponta para o proximo no
} No;

// Struct Fila
typedef struct
{
    No *prim; // Aponta para o primeiro elemento da fila
    No *fim;  // Aponta para o ultimo elemento da fila
    int tam;  // Tamanho da FILA
} Fila;

// Iniciando a fila
void criar_fila(Fila *fila)
{
    fila->prim = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

// Inserindo da fila
void inserir_na_fila(Fila *fila, int num)
{
    No *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->valor = num;
        novo->proximo = NULL;
        if (fila->prim == NULL) // se fila vazia
        {
            fila->prim = novo;
            fila->fim = novo;
        }
        else
        {
            // final da fila
            fila->fim->proximo = novo; // ultimo elemento aponta para o novo ultimo
            fila->fim = novo;          // fim aponta para o novo ultimo
        }
        fila->tam++;
    }
    else
        printf("\nErro ao alocar memoria.\n");
}

No *remover_da_fila(Fila *fila)
{
    No *remover = NULL;

    if (fila->prim)
    {
        remover = fila->prim; // remove o primeiro elemento
        fila->prim = remover->proximo;
        fila->tam--;
    }
    else
        printf("\tFila vazia\n");
    return remover;
}

void imprimir(Fila *fila)
{
    No *aux = fila->prim;
    printf("\t------- FILA --------\n\t");
    while (aux)
    {
        printf("%d\n", aux->valor);
        aux = aux->proximo;
    }
    printf("\n\t------- FIM FILA --------\n");
}

int main()
{
    No *r; // no auxiliar para remocao de elemento
    Fila fila;
    int opcao, valor;

    criar_fila(&fila);

    do
    {
        printf("\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_na_fila(&fila, valor);
            break;
        case 2:
            r = remover_da_fila(&fila);
            if (r)
            {
                printf("Removido: %d\n", r->valor);
                free(r);
            }
            break;
        case 3:
            imprimir(&fila);
            break;
        default:
            if (opcao != 0)
                printf("\nOpcao invaluda!\n");
        }

    } while (opcao != 0);

    return 0;
}