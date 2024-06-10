/*
    Considerando a implementação de uma lista encadeada para armazenar
    números reais dada pelo tipo abaixo:
        struct lista{
            float info;
            struct lista * prox;
        };
        typedef struct lista Lista;

    Implemente uma função que, dados um lista encadeada e um número
    inteiro não negativo n, remova da lista seus n primeiros nós e retorne a
    lista resultante.
    Caso n seja maior ou igual ao que o cumprimento da lista,
    todos os seus elementos devem ser removidos e o resultado da função
    deve ser uma lista vazia.
*/

#include <stdio.h>
#include <stdlib.h>

// Criacao da Estrutura/Header da lista
struct lista
{                          // Tipo do elemento da lista
    float info;            // info que a lista armazena
    struct lista *proximo; // ponteiro do tipo da lista para o proximo no
};
typedef struct lista Lista; // renomeando o tipo, apelido
typedef Lista *LISTA;       // declaracao do ponteiro da Header da lista

// Funcao para criar a lista, declaracao do Header
LISTA *criarLista()
{
    LISTA *inicio = (LISTA *)malloc(sizeof(LISTA)); // aloca header da lista
    if (inicio != NULL)
    {
        *inicio = NULL; // header é NULL
    }
    else
    {
        printf("Erro ao alocar o header da lista!\n");
        exit(0);
    }
    return inicio; // retorna o header alocado
}

// Procedimento para inserir no inicio da lista
void insereInicio(LISTA *lista)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista)); // declara novo no e aloca
    if (novo == NULL)
    {
        printf("Erro ao alocar novo no!\n");
        exit(0);
    }

    printf("Informe o valor do novo elemento: ");
    scanf("%f", &novo->info); // leitura do novo elemento
    getchar();                // retira o \n do buffer

    novo->proximo = (*lista); // proximo do novo aponta para o antigo atual
    (*lista) = novo;          // inicio da lista recebe o novo
}

// Procedimento para inserir no final da lista
void insereFinal(LISTA *lista)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista)); // declara e aloca novo no
    if (novo == NULL)
    {
        printf("Erro ao alocar novo no!\n");
        exit(0);
    }

    printf("Informe o valor do novo elemento: ");
    scanf("%f", &novo->info);
    getchar();

    novo->proximo = NULL;

    if ((*lista) == NULL) // insere no inicio se lista vazia
    {
        *lista = novo;
    }
    else
    {
        Lista *tmp;
        tmp = (*lista);              // no temporario recebe o header
        while (tmp->proximo != NULL) // avanca ate o final da lista
        {
            tmp = tmp->proximo;
        }
        tmp->proximo = novo; // final da lista recebe o novo no
    }
}

// Procedimento para exibir os elementos da lista
void exibeLista(LISTA *lista)
{
    if ((*lista) == NULL)
    {
        printf("LISTA VAZIA!\n");
    }
    else
    {
        Lista *tmp;
        tmp = (*lista); // no temporario recebe o header

        printf("<-------------------------->\n");
        printf("    ELEMENTOS DA LISTA:     \n");
        printf("<-------------------------->\n\n");
        printf("|INICIO: ");
        while (tmp != NULL) // enquanto existir elementos
        {
            printf("%f -> ", tmp->info); // imprime o atual
            tmp = tmp->proximo;          // avanca para o proximo
        }
        printf("FIM|\n");
    }
}

// Procedimento para deslocar todos os elementos da lista a partir do inicio
void liberaLista(LISTA *lista)
{
    if ((*lista) == NULL)
    {
        printf("LISTA VAZIA!\n");
    }
    else
    {
        Lista *tmp;
        while ((*lista) != NULL) // avanca enquanto existir elementos na lista
        {
            tmp = (*lista);               // recebe o elemento do inicio
            (*lista) = (*lista)->proximo; // header aponta para o proximo
            free(tmp);                    // desaloca o elemento inicial
        }
        (*lista) = NULL; // header é NULO

        printf("Lista liberada com sucesso!\n");
    }
}

// Funcao para remover um elemento do inicio da lista
void removeInicio(LISTA *lista)
{
    if ((*lista) != NULL)
    {
        Lista *tmp;
        tmp = (*lista);          // no temporario recebe o inicio da lista
        (*lista) = tmp->proximo; // header avanca para o proximo
        free(tmp);               // libera o no inicial
        printf("Elemento removido com sucesso!\n");
    }
    else
    {
        printf("LISTA VAZIA!\n");
    }
}

// Funcao para remover um elemento do final da lista
void removeFinal(LISTA *lista)
{
    Lista *noAnterior, *tmp;
    tmp = (*lista); // no teporario recebe o header

    if ((lista) != NULL && tmp->proximo == NULL) // verifica se existe apenas um elemento na lista
    {
        (*lista) = NULL; // header é nulo
        free(tmp);       // desaloca tmp
        printf("Elemento removido com sucesso!\n");
    }
    else if ((*lista) != NULL) // se lista possuir mais elementos
    {
        while (tmp->proximo != NULL) // avanca ate chegar no final da lista
        {
            noAnterior = tmp;   // salva o no atual
            tmp = tmp->proximo; // atual avanca para seu proximo
        }
        noAnterior->proximo = NULL; // proximo do anterior recebe NULL
        free(tmp);                  // desaloca o atual
        printf("Elemento removido com sucesso!\n");
    }
    else
    {
        printf("LISTA VAZIA!\n");
    }
}

// Funcao para remover n nos a partir do inicio de uma lista
void removerNos(LISTA *lista)
{
    if ((*lista)) // verifica se lista vazia
    {
        int n = 0;
        printf("Informe um numero inteiro positivo de nos a serem removidos: ");
        scanf("%d", &n);
        getchar();

        if (n > 0) // valida entrada
        {
            int tamanho = 0;
            Lista *tmp = (*lista);
            while (tmp != NULL) // calcula o tamanho da lista
            {
                tamanho++;
                tmp = tmp->proximo;
            }

            if (n >= tamanho) // se o tamanho for menor ou igual que a entrada libera tudo
            {
                liberaLista(lista);
            }
            else
            {
                // libera cada elemento do inicio ate alcancar o valor da entrada
                for (int i = 0; i < n; i++)
                {
                    tmp = (*lista);               // recebe o elemento do inicio
                    (*lista) = (*lista)->proximo; // header aponta para o proximo
                    free(tmp);
                }
                printf("%d nos removidos a partir do inicio da lista!\n", n);
            }
        }
        else
        {
            printf("Zero ou Negativos nao sao permitidos!\n");
        }
    }
    else
    {
        printf("LISTA VAZIA!\n");
    }
}

int main()
{
    system("cls");

    LISTA *lista;
    lista = criarLista();

    printf("Lista criada com sucesso!\n");
    getchar();

    int op = 0;

    do
    {
        system("cls");
        printf("[1] -> Inserir Inicio         \n");
        printf("[2] -> Inserir Final          \n");
        printf("[3] -> Remover Inicio         \n");
        printf("[4] -> Remover Final          \n");
        printf("[5] -> Liberar Lista          \n");
        printf("[6] -> Exibir Lista           \n");
        printf("[7] -> Remover n nos do inicio\n");
        printf("[0] -> Encerrar Programa      \n");
        scanf("%d", &op);
        getchar();
        system("cls");

        switch (op)
        {
        case 0:
            printf("Encerrando Programa!\n");
            break;
        case 1:
            insereInicio(lista);
            getchar();
            break;
        case 2:
            insereFinal(lista);
            getchar();
            break;
        case 3:
            removeInicio(lista);
            getchar();
            break;
        case 4:
            removeFinal(lista);
            getchar();
            break;
        case 5:
            liberaLista(lista);
            getchar();
            break;
        case 6:
            exibeLista(lista);
            getchar();
            break;
        case 7:
            removerNos(lista);
            getchar();
            break;
        default:
            printf("Opcao Invalida!\n");
            break;
        }
    } while (op != 0);

    system("pause");
    return 0;
}