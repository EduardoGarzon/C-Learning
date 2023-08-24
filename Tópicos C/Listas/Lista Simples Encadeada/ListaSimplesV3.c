/*
    Exemplo de lista simplesmente encadeada que utiliza ponteiro para ponteiro.
    Exemplo de como copiar para a lista C as listas A e B.
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
    char nome[31];
    int CPF;
    struct no *proximo; // ponteiro para o proximo no
} No;

No *Pessoa = NULL, *PessoaA = NULL, *PessoaB = NULL;
No *Removido = NULL;

/*
    Declaracao de Variaveis Globais
*/
int op; // opcao do menu
int CPF, CPF_anterior;
char nome[31], Nome_anterior[31];

/*
    Funcao que insere no inicio da lista.
    recebe a lista e o valor a ser inserido.
*/
void inserirInicio(No **lista, int v, char str[])
{
    No *novo = malloc(sizeof(No)); // aloca novo no

    if (novo)
    {
        // adiciona os valores ao novo no
        strcpy(novo->nome, str);
        novo->CPF = v;
        // o proximo do novo no aponta para o inicio da lista
        // pois lista ja contem o proximo que novo deve apontar
        novo->proximo = *lista;
        // o inicio da lista passa ser o novo no
        *lista = novo;
        // header -> novo -> proximo ou NULL
    }
    else
    {
        printf("\n\nErro ao alocar memoria! [inserirInicio]\n\n");
    }
}

/*
    Funcao para remover determinado elemento da lista
*/
No *remover_Elemento(No **lista, int v, char str[])
{
    No *aux, *remover = NULL;

    // verifia se lista nao esta vazia
    if (*lista)
    {
        // verifica se é o primeiro elemento
        if ((strcmp((*lista)->nome, str) == 0) || (*lista)->CPF == v)
        {
            remover = *lista;
            *lista = remover->proximo;
            // remover == header e header = header proximo
            // antes header -> 1 -> 2 depois header -> 2
        }
        else
        {
            aux = *lista;
            // percorre enquanto nao chegar no final e enquanto o elemento procurado for diferente do atual
            while (aux->proximo && (strcmp(aux->proximo->nome, str) != 0 || aux->proximo->CPF != v))
            {
                aux = aux->proximo;
            }
            if (aux->proximo)
            {
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                // antes header -> 1 -> 2 -> 3 -> NULL, depois header -> 1 -> 3 -> NULL
                // antes header -> 1 -> 2 -> 3 -> NULL, depois header -> 1 -> 2 -> NULL
            }
        }
    }
    return remover;
}

/*
    Procedimento que copia os elementos da lista2 para a lista1
*/
void copiar_Lista(No **lista1, No **lista2)
{
    No *aux = *lista2;
    while (aux)
    {
        inserirInicio(lista1, aux->CPF, aux->nome);
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
            printf("NOME: %s | CPF: %d\n\n", lista->nome, lista->CPF);
            lista = lista->proximo;
        }
    }
    else
    {
        printf("\n\nLISTA VAZIA\n\n");
    }
}

/*
    funcao para capturar dados do usuario
*/
void capturarDados(int *v, char str[])
{
    printf("Informe o nome: ");
    fgets(str, 31, stdin);          // le strings com espacos
    str[strcspn(str, "\n")] = '\0'; // remove o \n do fgets
    fflush(stdin);

    printf("Informe o cpf: ");
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
    CPF = 0;
    CPF_anterior = 0;
    memset(nome, 0, sizeof(nome));
    memset(Nome_anterior, 0, sizeof(Nome_anterior));

    clearScreen();
    printf("\n\n\tMenu de Opcoes\n\n");
    printf("[0] Finalizar Programa\n");
    printf("[1] Inserir no Inicio da Lista A\n");
    printf("[2] Inserir no Inicio da Lista B\n");
    printf("[3] Remover determinado elemento da Lista C\n");
    printf("[4] Visualizar Elementos da Lista A, B e C\n");
    printf("[5] Copiar lista A e B para lista C\n");
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
        capturarDados(&CPF, nome);
        inserirInicio(&PessoaA, CPF, nome);
        listaMenu();
        break;
    case 2:
        capturarDados(&CPF, nome);
        inserirInicio(&PessoaB, CPF, nome);
        listaMenu();
        break;
    case 3:
        capturarDados(&CPF, nome);
        // retorna elemento a ser removido por free
        Removido = remover_Elemento(&Pessoa, CPF, nome);
        if (Removido)
        {
            printf("Elemento Removido da Lista: %s\n", Removido->nome);
            free(Removido);
        }
        else
        {
            printf("\n\nElemento nao encontrado\n\n");
        }

        printf("\n\nTecle ENTER para prosseguir...");
        getchar();
        fflush(stdin);

        listaMenu();
        break;
    case 4:
        printf("\n\nLISTA C\n\n");
        imprimirLista(Pessoa);
        printf("\n\nLISTA A\n\n");
        imprimirLista(PessoaA);
        printf("\n\nLISTA B\n\n");
        imprimirLista(PessoaB);

        printf("\n\nTecle ENTER para prosseguir...");
        getchar();
        fflush(stdin);
        listaMenu();
        break;
    case 5:
        copiar_Lista(&Pessoa, &PessoaA);
        copiar_Lista(&Pessoa, &PessoaB);
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