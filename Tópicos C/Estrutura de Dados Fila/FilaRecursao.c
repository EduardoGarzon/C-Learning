#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

No *fila = NULL;

void inserir_na_fila(No **fila, int valor)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->valor = valor;
        novo->proximo = NULL;
        if (*fila == NULL)
            *fila = novo; // insere no início se fila vazia
        else
        {
            aux = *fila;
            while (aux->proximo)
                aux = aux->proximo; // insere no final se fila não estiver vazia
            aux->proximo = novo;
        }
    }
    else
        printf("\nErro ao alocar memoria.\n");
}

void insert_recursion(int counter)
{
    if (counter == 10)
    {
        inserir_na_fila(&fila, counter);
    }
    else
    {
        inserir_na_fila(&fila, counter);
        insert_recursion(counter + 1);
    }
}

void remover_recursion(No **fila)
{
    No *remover = NULL;

    if (*fila == NULL)
    {
        printf("\tFila vazia\n");
    }
    else
    {
        remover = *fila;
        *fila = remover->proximo;
        printf("Elemento removido: %d\n", remover->valor);
        free(remover);
        remover_recursion(fila);
    }
}

void imprimir_recursion(No *fila, int counter)
{
    if (fila == NULL)
    {
        printf("\n\t------- FIM FILA --------\n");
        return;
    }

    if (counter == 0)
    {
        printf("\t------- FILA --------\n\t");
    }
    printf("%d   counter: %d\n", fila->valor, counter);
    if (fila->proximo)
        printf("\t-----------------------\n\t");
    imprimir_recursion(fila->proximo, counter + 1);
}

int main()
{
    int counter = 0;
    insert_recursion(counter);

    counter = 0;
    imprimir_recursion(fila, counter);

    remover_recursion(&fila);

    return 0;
}
