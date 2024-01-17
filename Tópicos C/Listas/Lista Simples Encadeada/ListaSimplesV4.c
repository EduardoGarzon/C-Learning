/*
    Exemplo de lista simplesmente encadeada que utiliza ponteiro para ponteiro.
    Exemplo de como dividir uma lista A em uma lista par e outra impar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Estrutura No para a Lista.
    Cabeca da lista.
    Ponteiro para o primeiro ponteiro da lista que aponta para o primeiro elemento.
*/
typedef struct no
{
    int valor;
    struct no *proximo; // ponteiro para o proximo no
} No;

No *valores = NULL, *Par = NULL, *Impar = NULL;

int valor = 0;
int op;

/*
    Funcao que insere no inicio da lista.
    recebe a lista e o valor a ser inserido.
*/
void inserirInicio(No **lista, int v)
{
    No *novo = malloc(sizeof(No)); // aloca novo no

    if (novo)
    {
        novo->valor = v;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
    {
        printf("\n\nErro ao alocar memoria! [inserirInicio]\n\n");
    }
}

/*
    Funcao que insere os valores da lista A, pares na lista par e impares na lista impar
*/
void listas_PAR_IMPAR(No **A, No **P, No **I)
{
    No *aux = *A;

    while (aux)
    {
        if (aux->valor % 2 == 0)
        {
            inserirInicio(P, aux->valor); // Par
        }
        else
        {
            inserirInicio(I, aux->valor); // Impar
        }

        aux = aux->proximo;
    }
}

/*
    Funcao para imprimir todos os elementos da lista
*/
void imprimirLista(No *lista)
{
    if (lista)
    {
        while (lista)
        {
            printf("VALOR: %d\n\n", lista->valor);
            lista = lista->proximo;
        }
    }
    else
    {
        printf("\n\n\t\tLISTA VAZIA\n\n");
    }
}

/*
    funcao para capturar dados do usuario
*/
void capturarDados(int *v)
{
    printf("Informe o valor: ");
    scanf("%d", &(*v));
    fflush(stdin);
}

/*
    funcao limpa tela
*/
void clearScreen()
{
    system("cls");
}

void listaMenu()
{
    // zerando variaveis
    op = -1;

    clearScreen();

    printf("\n\n\tMenu de Opcoes\n\n");
    printf("[0] Finalizar Programa\n");
    printf("[1] Inserir no Inicio da Lista A\n");
    printf("[2] Visualizar Elementos da Lista A, PAR e IMPAR\n");
    printf("[3] Gerar Listas PAR e IMPAR\n");
    printf("\nINFORME A OPCAO: ");
    scanf("%d", &op);
    fflush(stdin);

    clearScreen();

    switch (op)
    {
    case 0:
        printf("\n\nEncerrando programa...\n\n");
        exit(0);

        break;
    case 1:
        capturarDados(&valor);
        inserirInicio(&valores, valor);

        listaMenu();

        break;
    case 2:
        printf("\n\nLISTA DOS VALORES\n\n");
        imprimirLista(valores);

        printf("\n\nLISTA PAR\n\n");
        imprimirLista(Par);

        printf("\n\nLISTA IMPAR\n\n");
        imprimirLista(Impar);

        printf("\n\nTecle ENTER para prosseguir...");
        getchar();
        fflush(stdin);

        listaMenu();

        break;
    case 3:
        listas_PAR_IMPAR(&valores, &Par, &Impar);
    default:
        printf("\n\nOpcao Invalida! Tente Novamente!\n\n");

        listaMenu();

        break;
    }
}

int main()
{
    listaMenu();

    system("pause");
    return 0;
}