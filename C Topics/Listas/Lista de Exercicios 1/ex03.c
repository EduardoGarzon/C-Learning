/*
    Crie um programa que simule um sistema de pila onde o primeiro que
    entra e o último que saí.
    A inserção sempre ocorrerá no fim da lista.
    O programa deverá ter as duas opções:
        1 – inclui na pilha e 2 – exclui da pilha.
    A cada inserção ou remoção a pilha deve ser apresentada na tela.

    Insere 1:

        Inicio
            1
        Fim

    Insere 2:

        Inicio
            2
            1
        Fim

    Remove:

        Inicio
            1
        Fim
*/

#include <stdio.h>
#include <stdlib.h>

// Criacao da Estrutura/Header da lista
struct Node
{                         // Tipo do elemento da PILHA
    int dado;             // dado que a PILHA armazena
    struct Node *proximo; // ponteiro do tipo da PILHA para o proximo no
};
typedef struct Node node; // renomeando o tipo, apelido
typedef node *PILHA;      // declaracao do ponteiro da Header da PILHA

// Funcao para criar a PILHA, declaracao do Header
PILHA *criarPilha()
{
    PILHA *inicio = (PILHA *)malloc(sizeof(PILHA)); // aloca header da PILHA
    if (inicio != NULL)
    {
        *inicio = NULL; // header é NULL
    }
    else
    {
        printf("Erro ao alocar o header da PILHA!\n");
        exit(0);
    }
    return inicio; // retorna o header alocado
}

// Procedimento para inserir no topo da PILHA
void insereFinal(PILHA *pilha)
{
    node *novo = (node *)malloc(sizeof(node)); // declara e aloca novo no
    if (novo == NULL)
    {
        printf("Erro ao alocar novo no!\n");
        exit(0);
    }

    printf("Informe o valor do novo elemento: ");
    scanf("%d", &novo->dado);
    getchar();

    novo->proximo = NULL;

    if ((*pilha) == NULL) // insere no inicio se pilha vazia
    {
        *pilha = novo;
    }
    else
    {
        node *tmp;
        tmp = (*pilha);              // no temporario recebe o header
        while (tmp->proximo != NULL) // avanca ate o final da pilha
        {
            tmp = tmp->proximo;
        }
        tmp->proximo = novo; // final da pilha recebe o novo no
    }
}

// Procedimento para exibir os elementos da pilha
void exibePilha(PILHA *pilha)
{
    if ((*pilha) == NULL)
    {
        printf("PILHA VAZIA!\n");
    }
    else
    {
        node *tmp;
        tmp = (*pilha); // no temporario recebe o header

        printf("<-------------------------->\n");
        printf("    ELEMENTOS DA PILHA:     \n");
        printf("<-------------------------->\n\n");
        printf("|BASE: ");
        while (tmp != NULL) // enquanto existir elementos
        {
            printf("%d ", tmp->dado); // imprime o atual
            tmp = tmp->proximo;       // avanca para o proximo
        }
        printf(":TOPO|\n");
    }
}

// Funcao para desempilhar do topo da pilha
void removeFinal(PILHA *pilha)
{
    node *noAnterior, *tmp;
    tmp = (*pilha); // no teporario recebe o header

    if ((*pilha) != NULL && tmp->proximo == NULL) // verifica se existe apenas um elemento na pilha
    {
        (*pilha) = NULL; // header é nulo
        free(tmp);       // desaloca tmp
        printf("Elemento removido com sucesso!\n");
    }
    else if ((*pilha) != NULL) // se pilha possuir mais elementos
    {
        while (tmp->proximo != NULL) // avanca ate chegar no final da pilha
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
        printf("PILHA VAZIA!\n");
    }
}

int main()
{
    system("cls");

    PILHA *pilha;
    pilha = criarPilha();

    printf("Pilha criada com sucesso!\n");
    getchar();

    int op = 0;

    do
    {
        system("cls");
        printf("[1] -> Empilhar\n");
        printf("[2] -> Desempilhar\n");
        printf("[0] -> Encerrar Programa\n");
        scanf("%d", &op);
        getchar();
        system("cls");

        switch (op)
        {
        case 0:
            printf("Encerrando Programa!\n");
            break;
        case 1:
            insereFinal(pilha);
            exibePilha(pilha);
            getchar();
            break;
        case 2:
            removeFinal(pilha);
            exibePilha(pilha);
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