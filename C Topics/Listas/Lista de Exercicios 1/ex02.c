/*
    Crie um programa que simule um sistema de fila onde o primeiro que entra
    é o primeiro que sai.
    A inserção sempre ocorrerá no inicio da lista.
    O programa deve ter as duas opções 1 – inclui na fila e 2 – exclui da fila.
    A cada inserção ou remoção a fila deve ser apresentada na tela.



    Insere no Inicio e Remove no Final:

        Insere 1:
            Inicio -> 1 -> Final
        Insere 2:
            Inicio -> 2 -> 1 -> Final
        Remove:
            Inicio -> 2 -> Final
*/

#include <stdio.h>
#include <stdlib.h>

// Criacao da Estrutura/Header da fila
struct Node
{                         // Tipo do elemento da dila
    int dado;             // dado que a fila armazena
    struct Node *proximo; // ponteiro do tipo da fila para o proximo no
};
typedef struct Node node; // renomeando o tipo, apelido
typedef node *FILA;       // declaracao do ponteiro da Header da fila

// Funcao para criar a fila, declaracao do Header
FILA *criarFila()
{
    FILA *inicio = (FILA *)malloc(sizeof(FILA)); // aloca header da fila
    if (inicio != NULL)
    {
        *inicio = NULL; // header é NULL
    }
    else
    {
        printf("Erro ao alocar o header da fila!\n");
        exit(0);
    }
    return inicio; // retorna o header alocado
}

// Procedimento para inserir no inicio da fila
void insereInicio(FILA *fila)
{
    node *novo = (node *)malloc(sizeof(node)); // declara novo no e aloca
    if (novo == NULL)
    {
        printf("Erro ao alocar novo no!\n");
        exit(0);
    }

    printf("Informe o valor do novo elemento: ");
    scanf("%d", &novo->dado); // leitura do novo elemento
    getchar();                // retira o \n do buffer

    novo->proximo = (*fila); // proximo do novo aponta para o antigo atual
    (*fila) = novo;          // inicio da lista recebe o novo
}

// Funcao para remover um elemento do final da fila
void removeFinal(FILA *fila)
{
    node *noAnterior, *tmp;
    tmp = (*fila); // no teporario recebe o header

    if ((*fila) != NULL && tmp->proximo == NULL) // verifica se existe apenas um elemento na fila
    {
        (*fila) = NULL; // header é nulo
        free(tmp);      // desaloca tmp
        printf("Elemento removido com sucesso!\n");
    }
    else if ((*fila) != NULL) // se fila possuir mais elementos
    {
        while (tmp->proximo != NULL) // avanca ate chegar no final da fila
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
        printf("FILA VAZIA!\n");
    }
}

// Procedimento para exibir os elementos da fila
void exibeFila(FILA *fila)
{
    if ((*fila) == NULL)
    {
        printf("FILA VAZIA!\n");
    }
    else
    {
        node *tmp;
        tmp = (*fila); // no temporario recebe o header

        printf("<-------------------------->\n");
        printf("    ELEMENTOS DA FILA:     \n");
        printf("<-------------------------->\n\n");
        printf("|FIM: ");
        while (tmp != NULL) // enquanto existir elementos
        {
            printf("%d ", tmp->dado); // imprime o atual
            tmp = tmp->proximo;          // avanca para o proximo
        }
        printf(":INICIO|\n");
    }
}

int main()
{
    system("cls");

    FILA *fila;
    fila = criarFila();

    printf("Fila criada com sucesso!\n");
    getchar();

    int op = 0;

    do
    {
        system("cls");
        printf("[1] -> Inserir\n");
        printf("[2] -> Remover\n");
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
            insereInicio(fila);
            exibeFila(fila);
            getchar();
            break;
        case 2:
            removeFinal(fila);
            exibeFila(fila);
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