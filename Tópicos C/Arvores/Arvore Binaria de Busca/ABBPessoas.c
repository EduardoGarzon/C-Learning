/*
    Árvore Binária de Busca de Pessoas
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int cpf;
} Pessoa;

typedef struct no
{
    Pessoa pessoa;
    struct no *direita, *esquerda;
} NoArv;

/*
    Metodos da estrutura Pessoa
*/
Pessoa ler_pessoa()
{
    Pessoa p;
    printf("\tDigite o nome da pessoa: ");
    fgets(p.nome, 49, stdin);
    printf("\tDigite o cpf: ");
    scanf("%d", &p.cpf);
    return p;
}

void imprimir_pessoa(Pessoa p)
{
    printf("\tNome: %s\tCpf: %d\n", p.nome, p.cpf);
}

/*
    Metodos da Arvore
*/

NoArv *inserir_versao_1(NoArv *raiz, Pessoa p)
{
    if (raiz == NULL)
    {
        NoArv *aux = malloc(sizeof(NoArv));
        aux->pessoa = p;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else
    {
        if (p.cpf < raiz->pessoa.cpf)
            raiz->esquerda = inserir_versao_1(raiz->esquerda, p);
        else
            raiz->direita = inserir_versao_1(raiz->direita, p);
        return raiz;
    }
}

void inserir_versao_2(NoArv **raiz, Pessoa p)
{
    if (*raiz == NULL)
    {
        *raiz = malloc(sizeof(NoArv));
        (*raiz)->pessoa = p;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
    }
    else
    {
        if (p.cpf < (*raiz)->pessoa.cpf)
            inserir_versao_2(&((*raiz)->esquerda), p);
        else
            inserir_versao_2(&((*raiz)->direita), p);
    }
}

void inserir_versao_3(NoArv **raiz, Pessoa p)
{
    NoArv *aux = *raiz;
    while (aux)
    {
        if (p.cpf < aux->pessoa.cpf)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->pessoa = p;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

NoArv *buscar_versao_1(NoArv *raiz, int cpf)
{
    if (raiz)
    {
        if (cpf == raiz->pessoa.cpf)
            return raiz;
        else if (cpf < raiz->pessoa.cpf)
            return buscar_versao_1(raiz->esquerda, cpf);
        else
            return buscar_versao_1(raiz->direita, cpf);
    }
    return NULL;
}

NoArv *buscar_versao_2(NoArv *raiz, int cpf)
{
    while (raiz)
    {
        if (cpf < raiz->pessoa.cpf)
            raiz = raiz->esquerda;
        else if (cpf > raiz->pessoa.cpf)
            raiz = raiz->direita;
        else
            return raiz;
    }
    return NULL;
}

int altura(NoArv *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }
    else
    {
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if (esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

int quantidade_nos(NoArv *raiz)
{
    if (raiz == NULL)
        return 0;
    else
        return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);

    // operador ternário
    // return (raiz == NULL)? 0: 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);
}

int quantidade_folhas(NoArv *raiz)
{
    if (raiz == NULL)
        return 0;
    else if (raiz->esquerda == NULL && raiz->direita == NULL)
        return 1;
    else
        return quantidade_folhas(raiz->esquerda) + quantidade_folhas(raiz->direita);
}

NoArv *remover(NoArv *raiz, int chave)
{
    if (raiz == NULL)
    {
        printf("Valor nao encontrado!\n");
        return NULL;
    }
    else
    { // procura o nó a remover
        if (raiz->pessoa.cpf == chave)
        {
            // remove nós folhas (nós sem filhos)
            if (raiz->esquerda == NULL && raiz->direita == NULL)
            {
                free(raiz);
                printf("Elemento folha removido: %d !\n", chave);
                return NULL;
            }
            else
            {
                // remover nós que possuem 2 filhos
                if (raiz->esquerda != NULL && raiz->direita != NULL)
                {
                    Pessoa p;
                    NoArv *aux = raiz->esquerda;
                    while (aux->direita != NULL)
                        aux = aux->direita;
                    p = raiz->pessoa;
                    raiz->pessoa = aux->pessoa;
                    aux->pessoa = p;
                    printf("Elemento trocado: %d !\n", chave);
                    raiz->esquerda = remover(raiz->esquerda, chave);
                    return raiz;
                }
                else
                {
                    // remover nós que possuem apenas 1 filho
                    NoArv *aux;
                    if (raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    printf("Elemento com 1 filho removido: %d !\n", chave);
                    return aux;
                }
            }
        }
        else
        {
            if (chave < raiz->pessoa.cpf)
                raiz->esquerda = remover(raiz->esquerda, chave);
            else
                raiz->direita = remover(raiz->direita, chave);
            return raiz;
        }
    }
}

void imprimir_versao_1(NoArv *raiz)
{ // 50 25 30 100
    if (raiz)
    {
        imprimir_pessoa(raiz->pessoa);
        imprimir_versao_1(raiz->esquerda);
        imprimir_versao_1(raiz->direita);
    }
}

void imprimir_versao_2(NoArv *raiz)
{ // 25 30 50 100
    if (raiz)
    {
        imprimir_versao_2(raiz->esquerda);
        imprimir_pessoa(raiz->pessoa);
        imprimir_versao_2(raiz->direita);
    }
}

int main()
{

    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Buscar\n\t4 - Altura\n\t5 - Tamanho\n\t6 - Folhas\n\t7 - Remover\n");
        scanf("%d", &opcao);
        scanf("%c");

        switch (opcao)
        {
        case 1:
            inserir_versao_3(&raiz, ler_pessoa());
            break;
        case 2:
            printf("\n\tPrimeira impressao:\n\t");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tSegunda impressao:\n\t");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        case 3:
            printf("\n\tDigite o cpf a ser procurado: ");
            scanf("%d", &valor);
            // busca = buscar_versao_1(raiz, valor);
            busca = buscar_versao_2(raiz, valor);
            if (busca)
            {
                printf("\n\tValor encontrado:\n");
                imprimir_pessoa(busca->pessoa);
            }
            else
                printf("\n\tValor nao encontrado!\n");
            break;
        case 4:
            printf("\n\tAltura da arvore: %d\n\n", altura(raiz));
            break;
        case 5:
            printf("\n\tQuantidade de nos: %d\n", quantidade_nos(raiz));
            break;
        case 6:
            printf("\n\tQuantidade folhas: %d\n", quantidade_folhas(raiz));
            break;
        case 7:
            printf("\t");
            imprimir_versao_2(raiz);
            printf("\n\tDigite o cpf a ser removido: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        default:
            if (opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    } while (opcao != 0);

    return 0;
}