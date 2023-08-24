/*
    Exemplo de lista simplesmente encadeada que utiliza ponteiro para ponteiro.
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

No *Pessoa = NULL;   // instancia do ponteiro para struct no
No *Removido = NULL; // instancia para elementos removidos
No *Elemento = NULL; // instancia para elementos buscados

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
    Funcao que insere no final da lista
*/
void inserirFinal(No **lista, int v, char str[])
{
    // alocando no auxiliar e novo no
    No *aux, *novo = malloc(sizeof(No));

    // verifica alocacao e adiciona valores
    if (novo)
    {
        strcpy(novo->nome, str);
        novo->CPF = v;
        novo->proximo = NULL; // sempre null ja que sera inserido no final

        // verificar se lista esta vazia, ou seja, primeiro elemento
        if (*lista == NULL)
        {
            *lista = novo; // primeiro no da lista
            // header -> novo -> NULL
        }
        else
        {
            aux = *lista;        // no auxiliar recebe a cabeca da lista
            while (aux->proximo) // caminha ate o ultimo no da lista
            {
                aux = aux->proximo;
            }
            aux->proximo = novo; // adiciona o novo no ao fim da lista
            // header -> v1 -> v2 -> novo -> NULL
        }
    }
    else
    {
        printf("\n\nErro ao alocar memoria! [inserirFinal]\n\n");
    }
}

/*
    Funcao que insere no meio da lista
*/
void inserirMeio(No **lista, int v, char str[], int v_ant, char str_ant[])
{
    No *aux, *novo = malloc(sizeof(No));

    if (novo)
    {
        strcpy(novo->nome, str);
        novo->CPF = v;

        // verifica se lista vazia
        if (*lista == NULL)
        {
            novo->proximo = NULL;
            *lista = novo;
            // header -> novo -> NULL
        }
        else
        {
            aux = *lista; // no auxiliar recebe a cabeca da lista
            // percorre ate achar o elemento referencia ou chegar no final da lista
            while ((aux->CPF != v_ant || (strcmp(aux->nome, str_ant) != 0)) && aux->proximo)
            {
                aux = aux->proximo;
            }
            // o novo no é adicionado depois do no referencia
            novo->proximo = aux->proximo; // proximo no do novo recebe o proximo no do aux
            aux->proximo = novo;          // proximo no auc recebe o novo
            // header -> v1 -> novo -> NULL
            // header -> v1 -> novo -> v2 -> NULL
        }
    }
}

/*
    Funcao para inserir elementos ordenados na lista
*/
void inserirOrdenado(No **lista, int v, char str[])
{
    No *novo = malloc(sizeof(No));

    if (novo != NULL)
    {
        novo->CPF = v;
        strcpy(novo->nome, str);

        // verifica se lista esta vazia
        if (*lista == NULL)
        {
            novo->proximo = NULL;
            *lista = novo;
            // header -> novo -> NULL
        }
        else if (strlen(novo->nome) < strlen((*lista)->nome)) // verifica se é o menor elemento
        {
            novo->proximo = *lista;
            *lista = novo;
            // header -> novo -> proximo
        }
        else
        {
            No *aux = *lista;
            // insere ordenado
            // percorre ate fim da lista ou enquanto o elemento for maior ou igual ao atual
            while (aux->proximo && (strlen(novo->nome) >= strlen((aux)->proximo->nome)))
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
            // header -> v1 -> novo -> v2 -> ...
            // header -> v1 -> v2 -> novo -> NULL
        }
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
      Função para buscar um elemento na lista
*/
No *buscar_Elemento(No **lista, int v, char str[])
{
    No *aux, *no = NULL;

    aux = *lista;
    // percorre ate o fim da lista e enquanto nao achar o elemento
    while (aux && aux->CPF != v)
        aux = aux->proximo;
    if (aux)
        no = aux;
    return no;
}

/*
    Funcao para imprimir todos os elementos da lista
*/
void imprimirLista(No *lista)
{
    if (lista)
    {
        printf("\n\nLISTA\n\n");
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

    printf("\n\nTecle ENTER para prosseguir...");
    getchar();
    fflush(stdin);
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
    Captura de dados referenciais para inserir os dados apos.
    Inserindo no meio da lista.
*/
void capturarPosicao(int *v, char str[])
{
    printf("Informe o nome referencia: ");
    fgets(str, 31, stdin);          // le strings com espacos
    str[strcspn(str, "\n")] = '\0'; // remove o \n do fgets
    fflush(stdin);

    printf("Informe o cpf referencia: ");
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
    printf("[1] Inserir no Inicio da Lista\n");
    printf("[2] Inserir no Final da Lista\n");
    printf("[3] Inserir no Meio da Lista\n");
    printf("[4] Inserir Ordenado na Lista\n");
    printf("[5] Visualizar Elementos da Lista\n");
    printf("[6] Remover determinado elemento\n");
    printf("[7] Procurar Elemento na Lista\n");
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
        inserirInicio(&Pessoa, CPF, nome);
        listaMenu();
        break;
    case 2:
        capturarDados(&CPF, nome);
        inserirFinal(&Pessoa, CPF, nome);
        listaMenu();
        break;
    case 3:
        capturarDados(&CPF, nome);
        capturarPosicao(&CPF_anterior, Nome_anterior);
        inserirMeio(&Pessoa, CPF, nome, CPF_anterior, Nome_anterior);
        listaMenu();
        break;
    case 4:
        capturarDados(&CPF, nome);
        inserirOrdenado(&Pessoa, CPF, nome);
        listaMenu();
        break;
    case 5:
        imprimirLista(Pessoa);
        listaMenu();
        break;
    case 6:
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
    case 7:
        capturarDados(&CPF, nome);
        // retorna o elemento encontrado ou nao
        Elemento = buscar_Elemento(&Pessoa, CPF, nome);

        if (Elemento)
        {
            printf("\n\nElemento encontrado!\n\n");
            printf("NOME: %s | CPF: %d\n\n", Elemento->nome, Elemento->CPF);
        }
        else
        {
            printf("\n\nElemento nao encontrado!\n\n");
        }

        printf("\n\nTecle ENTER para prosseguir...");
        getchar();
        fflush(stdin);

        listaMenu();
        break;
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