/*
    Implementacao de uma lista simplesmente encadeada
*/

#include <stdio.h>
#include <stdlib.h>

// Definindo estrutura da lista
typedef struct Node
{
    int dado;             // dado
    struct Node *proximo; // ponteiro para o proximo no
} node;

// Funcao para alocar o header da lista
node *criarLista()
{
    node *novo = malloc(sizeof(node)); // aloca novo no
    if (novo)                          // testa alocacao
    {
        novo = NULL;
        printf("Lista Criada com Sucesso!\n");
    }
    else
    {
        printf("Erro ao criar lista!\n");
        exit(0);
    }

    return novo; // retorna no alocado
}

// Procedimento para inserir no inicio da lista
void insereInicio(node **lista)
{
    node *novo = malloc(sizeof(node)); // aloca novo no
    if (novo)                          // verifica alocacao do no
    {
        printf("Informe o valor que deseja inserir: ");
        scanf("%d", &novo->dado);
        fflush(stdin);

        novo->proximo = (*lista); // aponta para o inicio da lista
        (*lista) = novo;          // header recebe o novo no alocado

        printf("Elemento %d inserido no inicio!\n", (*lista)->dado);
    }
    else
    {
        printf("Erro ao alocar novo elemento!\n");
    }
}

// Procedimento para inserir no final da lista
void insereFinal(node **lista)
{
    node *novo = malloc(sizeof(node)); // aloca novo no
    if (novo)                          // testa alocacao
    {
        printf("Informe o valor que deseja inserir: ");
        scanf("%d", &novo->dado);
        fflush(stdin);

        novo->proximo = NULL;

        if ((*lista)) // verifica se lista possui elementos
        {
            node *aux = (*lista);
            while (aux->proximo) // percorre lista ate o final
            {
                aux = aux->proximo;
            }
            aux->proximo = novo; // adiciona novo no ao final da lista
        }
        else
        {
            (*lista) = novo; // se lista vazia
        }

        printf("Elemento %d inserido no final!\n", novo->dado);
    }
    else
    {
        printf("Erro ao alocar novo elemento!\n");
    }
}

// Procedimento para inserir no meio da lista
void insereMeio(node **lista)
{
    node *novo = malloc(sizeof(node)); // aloca novo no
    printf("Informe o elemento que deseja inserir no meio da lista: ");
    scanf("%d", &novo->dado);
    fflush(stdin);

    if (novo) // testa alocacao
    {
        if ((*lista)) // se lista com elemento(s)
        {
            node *aux = (*lista);
            if (!aux->proximo) // se apenas um elemento na lista
            {
                aux->proximo = novo; // adiciona novo no ao final da lista
                novo->proximo = NULL;

                printf("Elemento %d inserido com sucesso!\n", novo->dado);
            }
            else
            {
                int tamanho = 0;
                while (aux) // percorre a lista ate o final
                {
                    aux = aux->proximo;
                    tamanho++; // incrementa tamanho da lista
                }

                tamanho = tamanho / 2;     // divide o tamanho da lista para calcular o meio
                int index = 1;             // indice para percorrer ate o meio da lista
                aux = (*lista);            // reseta no aux
                node *next = aux->proximo; // recebe o proximo do atual

                while (index < tamanho) // percorre ate o meio da lista
                {
                    aux = aux->proximo;  // avanca o atual
                    next = aux->proximo; // avanco o para o proximo do atual
                    index++;
                }

                aux->proximo = novo;  // atual recebe o novo no
                novo->proximo = next; // novo no recebe o proximo do atual
            }
        }
        else // se lista vazia
        {
            novo->proximo = (*lista); // proximo recebe NULL
            (*lista) = novo;          // header recebe o novo

            printf("Elemento %d inserido com sucesso!\n", novo->dado);
        }
    }
    else
    {
        printf("Erro ao alocar no!\n");
    }
}

// Procedimento para inserir um elemento ordenado na lista
void inserirOrdenado(node **lista)
{
    if ((*lista)) // verifica se lista possui elementos
    {
        node *novo = malloc(sizeof(node)); // aloca novo no
        printf("Informe o elemento que deseja inserir: ");
        scanf("%d", &novo->dado);
        fflush(stdin);

        if (novo) // verifica alocacao
        {
            node *aux = (*lista); // aux recebe a lista
            if (!aux->proximo)    // verifica se lista possui apenas um elemento
            {
                if (novo->dado > aux->dado) // insere depois do atual se novo for maior
                {
                    aux->proximo = novo;  // proximo do atual recebe o novo
                    novo->proximo = NULL; // proximo do novo recebe NULL
                }
                else // insere antes do atual se novo for menor
                {
                    novo->proximo = (*lista); // proximo recebe a lista
                    (*lista) = novo;          // header recebe o novo
                }
            }
            else // se lista possui mais de um elemento
            {
                node *aux3 = aux; // recebe a lista

                if (novo->dado < aux->dado) // insere no inicio se o novo for menor que o primeiro atual
                {
                    novo->proximo = (*lista); // proximo do novo recebe o inicio da lista
                    (*lista) = novo;          // header recebe o novo
                }
                else // verifica os proximos elementos da lista
                {
                    while (aux) // percorre a lista ate o fim
                    {
                        if (novo->dado > aux->dado) // avanca o atual e o anterior se o novo for maior que o atual
                        {
                            aux3 = aux;         // anterior recebe o atual
                            aux = aux->proximo; // atual recebe o proximo
                        }
                        else
                        {
                            break; // encerra o laco quando o novo for menor
                        }
                    }

                    if (!aux) // insere no final caso o atual seja NULL
                    {
                        aux3->proximo = novo; // anterior aponta para o novo
                        novo->proximo = NULL; // novo aponta para NULL
                    }
                    else // insere no meio caso nao seja o final da lista
                    {
                        aux3->proximo = novo; // anterior aponta para o novo
                        novo->proximo = aux;  // novo aponta para o antigo atual
                    }
                }
            }
        }
        else
        {
            printf("Erro ao alocar no!\n");
        }
    }
    else
    {
        printf("Lista Vazia!\n");
    }
}

// Procedimento para remover no inicio da lista
void removeInicio(node **lista)
{
    if ((*lista)) // verifica se lista possui elementos
    {
        node *aux, *proxNode;

        aux = (*lista);          // aux recebe o inicio da lista
        (*lista) = aux->proximo; // header aponta para o proximo do atual
        int elemento = aux->dado;

        free(aux); // desaloca o atual

        printf("Elemento %d removido do inicio com sucesso!\n", elemento);
    }
    else
    {
        printf("Lista Vazia!\n");
    }
}

// Procedimento para remover no final da lista
void removeFim(node **lista)
{
    if ((*lista)) // verifica se lista possui elementos
    {
        node *aux = (*lista); // recebe o inicio da lista
        node *noAnterior;

        while (aux->proximo) // enquanto proximo nao for NULL
        {
            noAnterior = aux;   // anterior recebe o atual
            aux = aux->proximo; // atual recebe seu proximo
        }
        int elemento = aux->dado;

        noAnterior->proximo = NULL; // penultimo aponta para NULL
        free(aux);                  // desaloca o ultimo

        printf("Elemento %d removido do final com sucesso!\n", elemento);
    }
    else
    {
        printf("Lista Vazia!\n");
    }
}

// Procedimento para remover um elemento por busca da lista
int removerElemento(node **lista)
{
    if ((*lista)) // verifica se lista possui elementos
    {
        int elemento = 0;
        printf("Informe o elemento que deseja remover: ");
        scanf("%d", &elemento);
        fflush(stdin);

        node *aux = (*lista); // recebe o inicio da lista

        if (!aux->proximo) // verifica se lista possui apenas um elemento
        {
            if (aux->dado == elemento) // se o atual for igual ao elemento procurado
            {
                (*lista) = NULL; // header recebe NULL
                free(aux);       // desaloca o atual
                return elemento;
            }
        }
        else if (aux->dado == elemento) // se lista possui mais elementos verifica se 'e o primeiro
        {
            node *aux2 = aux->proximo; // recebe o proximo do atual
            (*lista) = aux2;           // lista recebe o proximo do atual
            free(aux);                 // desaloca o atual
            return elemento;
        }
        else // se lista maior que 1 e nao 'e o primeiro elemento
        {
            node *anterior = aux; // anterior recebe o atual
            aux = aux->proximo;   // atual recebe seu proximo
            while (aux)           // enquanto existir proximo
            {
                if (aux->dado == elemento) // se o proximo for igual ao elemento procurado
                {
                    if (aux->proximo == NULL) // verifica se 'e o fim da lista
                    {
                        anterior->proximo = NULL; // o atual aponta para NULL
                        free(aux);                // libera o proximo
                        return elemento;
                    }
                    else // caso nao esteja no final da lista
                    {
                        anterior = aux->proximo; // o atual aponta para seu proximo
                        free(aux);               // libera o proximo
                        return elemento;
                    }
                }
                anterior = aux;     // anterior recebe o atual
                aux = aux->proximo; // atual recebe o proximo
            }
        }
        return 0;
    }
    else
    {
        printf("Lista Vazia!\n");
    }
}

// Procedimento para desalocar toda a lista
void liberarLista(node **lista)
{
    if ((*lista)) // verifica se lista possui elementos
    {
        node *aux;
        while ((*lista)) // enquanto existir elemento na lista
        {
            aux = (*lista);               // recebe o elemento do inicio
            (*lista) = (*lista)->proximo; // recebe o segundo
            free(aux);                    // desaloca o primeiro
        }
        (*lista) = NULL; // lista aponta para NULL

        printf("Lista desalocada com sucesso!\n");
    }
    else
    {
        printf("Lista Vazia!\n");
    }
}

// Procedimento para ordenar uma lista por SelectionSort
void ordenarLista(node **lista)
{
    if ((*lista)) // verifica se lista possui elementos
    {
        node *atual = (*lista); // atual aponta para o inicio

        while (atual) // enquanto existir elementos atuais
        {
            node *minimo = atual;            // menor no recebe o atual
            node *proximos = atual->proximo; // proximo no recebe o proximo do atual

            // Encontra o nó com o menor valor a direita do atual
            while (proximos)
            {
                if (proximos->dado < minimo->dado) // se o proximo for menor que o menor
                {
                    minimo = proximos; // atualiza o menor encontrado
                }
                proximos = proximos->proximo; // avanca para o proximo
            }

            // Troca os dados dos nós
            int temp = atual->dado;     // recebe o valor do atual
            atual->dado = minimo->dado; // atual recebe o menor encontrado
            minimo->dado = temp;        // novo menor passa a ser o antigo atual

            atual = atual->proximo; // atual recebe o seu proximo
        }
    }
    else
    {
        printf("Lista Vazia!\n");
    }
}

// Procedimento para ordenar uma lista de forma Crescente por BubbleSort
void ordenarCrescente(node **lista)
{
    if ((*lista)) // verifica se a lista possui elementos
    {
        int troca = 0;                   // variavel de controle de trocas
        node *atual = (*lista);          // atual aponta para o inicio da lista
        node *proximos = atual->proximo; // proximos aponta para o proximo do atual
        do
        {
            troca = 0;       // sem trocas
            while (proximos) // enquanto existir proximos elementos
            {
                if (atual->dado > proximos->dado) // troca se o atual for maior que o proximo
                {
                    int temp = atual->dado;       // variavel temporaria recebe o valor do atual
                    atual->dado = proximos->dado; // atual recebe o proximo
                    proximos->dado = temp;        // proximo recebe o atual
                    troca = 1;                    // trocou
                }
                atual = atual->proximo;    // avanca o atual
                proximos = atual->proximo; // avanca o proximo
            }
            // reseta ponteiros para o inicio
            atual = (*lista);          // atual aponta para o inicio
            proximos = atual->proximo; // recebe o proximo do atual

        } while (troca == 1); // repete o ciclo de comparacoes enquanto trocas ocorrerem
    }
    else
    {
        printf("Lista Vazia!\n");
    }
}

// Procedimento para ordenar uma lista de forma Decrescente por BubbleSort
void ordenarDecrescente(node **lista)
{
    if ((*lista)) // verifica se lista possui elementos
    {
        int troca = 0;                   // verificador de trocas
        node *atual = (*lista);          // atual recebe o inicio da lista
        node *proximos = atual->proximo; // proximos recebe o proximo do atual
        do
        {
            troca = 0;       // sem trocas
            while (proximos) // enquanto existir proximos
            {
                if (atual->dado < proximos->dado) // troca se o atual for menor que o proximo
                {
                    int temp = atual->dado;       // variavel temporaria recebe o atual
                    atual->dado = proximos->dado; // atual recebe o proximo
                    proximos->dado = temp;        // proximo recebe o atual
                    troca = 1;                    // trocou
                }
                atual = atual->proximo;    // atual recebe seu proximo
                proximos = atual->proximo; // proximo recebe o proximo do novo atual
            }
            // reseta ponteiros para o inicio
            atual = (*lista);          // atual recebe o inicio da lista
            proximos = atual->proximo; // proximo recebe o proximo do atual

        } while (troca == 1); // repete o ciclo de trocas enquanto trocas ocorrerem
    }
    else
    {
        printf("Lista Vazia!\n");
    }
}

// Funcao que retorna o elemento procurado na lista
int buscarElemento(node **lista)
{
    if ((*lista)) // verifica se a lista possui elementos
    {
        int elemento = 0;
        printf("Informe o elemento que deseja buscar: ");
        scanf("%d", &elemento);
        fflush(stdin);

        node *aux = (*lista); // aponta para o inicio da lista

        while (aux) // enquanto existir elementos
        {
            if (aux->dado == elemento) // se o atual for igual ao elemento procurado
            {
                return aux->dado; // retorna o elemento encontrado
            }
            aux = aux->proximo; // avanca para o proximo caso contrario
        }

        return 0; // retorna 0 caso o elemento nao tenha sido encontrado
    }
    else
    {
        printf("Lista Vazia!\n");
        return 0;
    }
}

// Procedimento para exibir os elementos da lista
void exibirLista(node **lista)
{
    if ((*lista)) // verifica se lista possui elementos
    {
        int count = 0;        // index dos elementos
        node *aux = (*lista); // aponta para o inicio da lista

        printf("\nELEMENTOS DA LISTA:\n");

        while (aux) // enquanto existir elementos
        {
            printf("-----------------\n");
            printf("Elemento: %d\nDado: %d\n", count, aux->dado);
            printf("-----------------\n");
            aux = aux->proximo; // avanca para o proximo
            count++;            // incrementa index
        }
    }
    else
    {
        printf("Lista Vazia!\n");
    }
}

// Procedimento para confirmacao de continuacao do programa
void continuar()
{
    printf("\nTecle [ENTER] para continuar...\n");
    getchar();
}

// Procedimento para o menu interativo da lista
void menu()
{
    system("cls");              // limpa tela
    node *lista = criarLista(); // cria o header da lista
    continuar();                // aguarda confirmacao

    int op = 0, elemento = 0, removido = 0; // variaveis para operacao, elemento procurado e elemento removido

    do
    {
        system("cls"); // limpa tela
        printf("<---------------------------------------------->\n");
        printf("                    MENU                        \n");
        printf("<---------------------------------------------->\n");
        printf("    [1]     -> Inserir Inicio                   \n");
        printf("    [2]     -> Insere Final                     \n");
        printf("    [3]     -> Inserir Ordenado                 \n");
        printf("    [4]     -> Inserir Meio                     \n");
        printf("<---------------------------------------------->\n");
        printf("    [5]     -> Remover Inicio                   \n");
        printf("    [6]     -> Remover Fim                      \n");
        printf("    [7]     -> Remover Elemento [Busca]         \n");
        printf("    [8]     -> Liberar Lista                    \n");
        printf("<---------------------------------------------->\n");
        printf("    [9]     -> Exibir Lista                     \n");
        printf("    [10]    -> Buscar Elemento                  \n");
        printf("<---------------------------------------------->\n");
        printf("    [11]    -> Ordenar Lista [SelectionSort]    \n");
        printf("    [12]    -> Ordenar Lista [Crescente]        \n");
        printf("    [13]    -> Ordenar Lista [Decrescente]      \n");
        printf("<---------------------------------------------->\n");
        printf("    [14]    -> Sair do Programa                 \n");
        printf("<---------------------------------------------->\n");
        scanf("%d", &op);
        fflush(stdin);
        system("cls"); // limpa a tela apos operacao selecionada

        switch (op)
        {
        case 1:
            insereInicio(&lista);
            continuar();
            break;
        case 2:
            insereFinal(&lista);
            continuar();
            break;
        case 3:
            ordenarLista(&lista);
            inserirOrdenado(&lista);
            continuar();
            break;
        case 4:
            insereMeio(&lista);
            continuar();
            break;
        case 5:
            removeFim(&lista);
            continuar();
            break;
        case 6:
            removeInicio(&lista);
            continuar();
            break;
        case 7:
            removido = removerElemento(&lista);
            if (removido)
            {
                printf("Elemento %d removido com sucesso!\n", removido);
            }
            else
            {
                printf("Elemento nao encontrado!\n");
            }
            continuar();
            break;
        case 8:
            liberarLista(&lista);
            continuar();
            break;
        case 9:
            exibirLista(&lista);
            continuar();
            break;
        case 10:
            elemento = buscarElemento(&lista);
            if (elemento)
            {
                printf("Elemento encontrado: %d\n", elemento);
            }
            else
            {
                printf("Elemento nao encontrado na lista!\n");
            }
            continuar();
            break;
        case 11:
            ordenarLista(&lista);
            continuar();
            break;
        case 12:
            ordenarCrescente(&lista);
            continuar();
            break;
        case 13:
            ordenarDecrescente(&lista);
            continuar();
            break;
        case 14:
            printf("Programa Encerrado!\n");
            break;
        default:
            printf("Opcao invalida, tente novamente!\n");
            break;
        }
    } while (op != 14);
}

int main()
{
    menu();

    system("pause");
    return 0;
}