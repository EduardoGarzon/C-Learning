/*
    Implementando uma fila de prioridade.
*/

#include <stdio.h>
#include <stdlib.h>

// Estrutura Pessoa
typedef struct Pessoa
{
    char nome[50];
    int idade;
} P;

P pessoa;

// Struct Nó
typedef struct no
{
    P person;
    struct no *proximo;
} No;

No *fila = NULL;
No *r = NULL;

// Criando Fila
No *criar_Fila()
{
    No *f = malloc(sizeof(No));
    f->proximo = NULL;
    return f;
}

// Função para inserir com prioridade por idade
void inserir_com_prioridade(No **fila, P pessoa)
{
    No *aux, *novo = malloc(sizeof(No));
    if (novo)
    {
        novo->person = pessoa;
        novo->proximo = NULL;
        if (*fila == NULL) // a fila está vazia?
            *fila = novo;
        else
        {
            if (pessoa.idade > 59)
            { // é prioridade?
                if ((*fila)->person.idade < 60)
                {                          // é a primeira prioridade?
                    novo->proximo = *fila; // insere no início da fila
                    *fila = novo;
                }
                else
                {
                    aux = *fila;
                    while (aux->proximo && aux->proximo->person.idade > 59)
                        aux = aux->proximo;
                    novo->proximo = aux->proximo; // insere depois da última prioridade
                    aux->proximo = novo;
                }
            }
            else
            { // não é prioridade, então insere no final
                aux = *fila;
                while (aux->proximo)
                    aux = aux->proximo;
                aux->proximo = novo;
            }
        }
    }
    else
        printf("\nErro ao alocar memoria.\n");
}

// Funcao para remover da fila
No *remover_da_fila(No **fila)
{
    No *remover = NULL;

    if (*fila)
    {
        remover = *fila;
        *fila = remover->proximo;
    }
    else
        printf("\tFila Vazia.\n");
    return remover;
}

// Imprime fila
void imprimirFila(No *fila)
{
    int i = 0;
    if (fila->proximo != NULL)
    {
        fila = fila->proximo;
        printf("\t----------FILA----------\n\n");

        while (fila)
        {
            printf("\t\tPessoa: %d\n", i++);
            printf("\t\tIdade: %d | Nome: %s\n", fila->person.idade, fila->person.nome);
            fila = fila->proximo;

            if (fila)
            {
                printf("\t\t----------\n");
            }
        }
        printf("\t----------FIM DA FILA----------\n");
    }
    else
    {
        printf("\tFila Vazia!\n");
    }
}

// Criando uma Pessoa
P LerPessoa()
{
    P p;
    printf("\tInforme o nome: ");
    fgets(p.nome, 50, stdin);
    printf("\tInforme a idade: ");
    scanf("%d", &p.idade);
    fflush(stdin);
    printf("\n");
    return p;
}

// Limpa Tela
void Clear()
{
    system("cls");
}

// Menu de opcoes
void menu()
{
    int op = 0;

    printf("\t1 - Criar Fila\n\t2 - Sair\n\t3 - Ler pessoa\n\t4 - Inserir Pessoa na Fila\n\t5 - Imprimir Fila\n\t6 - Remover da Fila\n");
    scanf("%d", &op);
    fflush(stdin);

    switch (op)
    {
    case 1:
        fila = criar_Fila();
        if (fila)
        {
            printf("\tFila criada com sucesso!\n");
        }
        else
        {
            printf("\tErro ao criar fila!\n");
        }

        printf("\tTecle [ENTER] para continuar...");
        getchar();
        Clear();
        menu();
        break;
    case 2:
        printf("\tPrograma encerrado.\n");
        free(fila);
        break;
    case 3:
        pessoa = LerPessoa();
        if (pessoa.idade != 0)
        {
            printf("\tPessoa cadastrada com sucesso.\n");
        }
        else
        {
            printf("\tErro ao cadastrar pessoa.\n");
        }

        printf("\tTecle [ENTER] para continuar...");
        getchar();
        Clear();
        menu();
        break;
    case 4:
        if (fila)
        {
            if (pessoa.idade == 0)
            {
                printf("\tCadastre uma pessoa!\n");
            }
            else
            {
                inserir_com_prioridade(&fila, pessoa);
            }
        }
        else
        {
            printf("\tInicie a Fila!\n");
        }

        printf("\tTecle [ENTER] para continuar...");
        getchar();
        Clear();
        menu();
        break;
    case 5:
        imprimirFila(fila);

        printf("\tTecle [ENTER] para continuar...");
        getchar();
        Clear();
        menu();
        break;
    case 6:
        r = remover_da_fila(&fila);
        if (r)
        {
            printf("\tElemento Removido: %s \n", r->person.nome);
        }
        else
        {
            printf("\tFalha ao remover o elemento.\n");
        }
        free(r);
        
        printf("\tTecle [ENTER] para continuar...");
        getchar();
        Clear();
        menu();
        break;
    default:
        printf("\tOpcao invalida, tente novamente.\n");
        menu();
        break;
    }
}

int main()
{
    menu();

    return 0;
}
