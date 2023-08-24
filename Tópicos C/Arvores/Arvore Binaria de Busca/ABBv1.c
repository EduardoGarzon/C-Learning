/*
    Implementacao de um Arvore Binaria de Busca v1.
*/

#include <stdio.h>
#include <stdlib.h>

/*
    Estrutura do Nó da Arvore
*/
typedef struct no
{
    int dado;
    struct no *left, *rigth;
} NoArv;

/*
    Funcao recursiva para inserir um novo nó na arvore
*/
NoArv *inserirNoRec(NoArv *raiz, int dado)
{
    if (raiz == NULL) // Verifica se no vazio
    {
        NoArv *aux = malloc(sizeof(NoArv));
        aux->dado = dado;
        aux->left = NULL;
        aux->rigth = NULL;
        return aux;
    }
    else
    {
        // Se arvore nao vazia
        if (dado < raiz->dado) // Insere recursivamente à esquerda
        {
            raiz->left = inserirNoRec(raiz->left, dado);
        }
        else if (dado > raiz->dado) // Insere recursivamente à direita
        {
            raiz->rigth = inserirNoRec(raiz->rigth, dado);
        }
        return raiz;
    }
}

/*
    Procedimento recursivo para inserir um novo nó na arvore
*/
void inserirNoRec2(NoArv **raiz, int dado)
{
    if ((*raiz) == NULL) // Se nó vazio
    {
        (*raiz) = malloc(sizeof(NoArv));
        (*raiz)->dado = dado;
        (*raiz)->left = NULL;
        (*raiz)->rigth = NULL;
    }
    else if (dado < (*raiz)->dado) // Insere à esquerda
    {
        inserirNoRec2(&((*raiz)->left), dado);
    }
    else if (dado > (*raiz)->dado) // Insere à direita
    {
        inserirNoRec2(&((*raiz)->rigth), dado);
    }
}

/*
    Procedimento iterativo para inserir um novo no na arvore
*/
void inserirNoIterativo(NoArv **raiz, int dado)
{
    NoArv *aux = *raiz;
    // while retorna um no vazio onde sera inserido o novo no com o dado
    while (aux) // Enquanto nao existir no vazio
    {
        if (dado < aux->dado) // Se o dado for menor
        {
            raiz = &aux->left; // Avanca para esquerda
        }
        else if (dado > aux->dado) // Se o dado for maior
        {
            raiz = &aux->rigth; // Avanca para direita
        }
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->dado = dado;
    aux->left = NULL;
    aux->rigth = NULL;
    *raiz = aux; // atribui o novo no ao no vazio;
}

/*
    Função para remover nós da Árvore binária
*/
NoArv *removerRecursivo(NoArv *raiz, int chave)
{
    if (raiz == NULL) // Verifica no vazio
    {
        printf("Valor nao encontrado!\n");
        return NULL;
    }
    else
    { // Procura o nó a remover
        if (raiz->dado == chave)
        {
            // Remove nós folhas (nós sem filhos)
            if (raiz->left == NULL && raiz->rigth == NULL)
            {
                free(raiz);
                printf("Elemento folha removido: %d !\n", chave);
                return NULL;
            }
            else
            {
                // Remover nós que possuem 2 filhos
                if (raiz->left != NULL && raiz->rigth != NULL) // Se possui dois filhos
                {
                    NoArv *aux = raiz->left; // Aux recebe a subárvore à esquerda
                    while (aux->rigth != NULL)
                        aux = aux->rigth;   // Obtêm o nó mais a direita da subarvore esquerda
                    raiz->dado = aux->dado; // Copia o predecessor para a posicao que contem o elemento a ser removido
                    aux->dado = chave;      // Copia para o predecessor o valor que estava na posicao a ser removida
                    printf("Elemento trocado: %d\n", chave);
                    raiz->left = removerRecursivo(raiz->left, chave);
                    return raiz;
                }
                else
                {
                    // remover nós que possuem 1 filho
                    NoArv *aux;
                    if (raiz->left != NULL)
                    {
                        aux = raiz->left;
                    }
                    else
                    {
                        aux = raiz->rigth;
                    }
                    free(raiz);
                    printf("Elemento com 1 filho removido: %d\n", chave);
                    return aux;
                }
            }
        }
        else
        {
            if (chave < raiz->dado)
                raiz->left = removerRecursivo(raiz->left, chave);
            else
                raiz->rigth = removerRecursivo(raiz->rigth, chave);
            return raiz; // Atualiza o ponteiro do no pai caso algum filho seja removido
        }
    }
}

/*
    Função recursiva para buscar um elemento na arvore
*/
NoArv *buscaRecursiva(NoArv *raiz, int dado)
{
    if (raiz) // Se arvore nao vazia
    {
        if (dado == raiz->dado)                       // O dado esta no no atual?
            return raiz;                              // Retorna a raiz que contem o dado
        else if (dado < raiz->dado)                   // Dado menor que o valor do no?
            return buscaRecursiva(raiz->left, dado);  // Percorre pela esquerda
        else                                          // Dado maior que o no atual
            return buscaRecursiva(raiz->rigth, dado); // Percorre pela direita
    }
    return NULL; // Retorna vazio se nao encontrou o dado
}

/*
     Função iterativa para realizar uma busca em uma árvore binária de busca
*/
NoArv *buscaIterativa(NoArv *raiz, int dado)
{
    while (raiz) // Enquanto nó nao for vazio itera
    {
        if (dado < raiz->dado)      // Dado menor que dado do nó?
            raiz = raiz->left;      // Segue à esquerda
        else if (dado > raiz->dado) // Dado maior que dado do nó?
            raiz = raiz->rigth;     // Segue pela direita
        else                        // Dado nao é menor nem maior entao é igual
            return raiz;            // Retorna o no que contem o dado procurado
    }
    return NULL; // Retorna Null se nao encontrar o dado
}

/*
    Procedimento recursivo para imprimir a arvore pre-ordem
    Raiz, Subarvore esquerda, Subarvore direita.
*/
void imprimirPre(NoArv *raiz)
{
    if (raiz)
    {
        printf("%d ", raiz->dado);
        imprimirPre(raiz->left);
        imprimirPre(raiz->rigth);
    }
}

/*
    Procedimento recursivo para imprimir a arvore In-ordem
    Subarvore esquerda, Raiz, Subarvore direita.
*/
void imprimirIn(NoArv *raiz)
{
    if (raiz)
    {
        imprimirIn(raiz->left);
        printf("%d ", raiz->dado);
        imprimirIn(raiz->rigth);
    }
}

/*
    Procedimento recursivo para imprimir a arvore Pos-Ordem
    Subarvore esquerda, Subarvore direita, Raiz.
*/
void imprimirPos(NoArv *raiz)
{
    if (raiz)
    {
        imprimirPos(raiz->left);
        imprimirPos(raiz->rigth);
        printf("%d ", raiz->dado);
    }
}

/*
    Funcao recursiva para calcular a altura da arvore
*/
int alturaRecursiva(NoArv *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }
    else
    {
        int left = alturaRecursiva(raiz->left);
        int right = alturaRecursiva(raiz->rigth);
        if (left > right)
        {
            return left + 1;
        }
        else
        {
            return right + 1;
        }
    }
}

/*
    Função que conta e retorna a quantidade de nós da arvore
*/
int qtdNosRecursiva(NoArv *raiz)
{
    // if (raiz == NULL)
    //     return 0;
    // else
    //     return 1 + quantidade_nos(raiz->esquerda) + quantidade_nos(raiz->direita);

    // operador ternário -> teste : verdadeiro : falso
    return (raiz == NULL) ? 0 : 1 + qtdNosRecursiva(raiz->left) + qtdNosRecursiva(raiz->rigth);
}

/*
    Função que conta e retorna a quantidade de nós folhas da Arvore
*/
int qtdFolhasRecursiva(NoArv *raiz)
{
    if (raiz == NULL)                                   // se no vazio
        return 0;                                       // retorna 0
    else if (raiz->left == NULL && raiz->rigth == NULL) // se no nao vazio e nao tiver filhos
        return 1;                                       // retorna +1 folha
    else
        // Avanca tanto para esquerda quanto para direita
        return qtdFolhasRecursiva(raiz->left) + qtdFolhasRecursiva(raiz->rigth);
}

void clear()
{
    system("cls");
}

void continuar()
{
    printf("\nTecle [ENTER] para continuar...");
    getchar();
}

int main()
{
    int dado = 0, op = -1;                 // Dado para ser inserido na Arvore
    NoArv *retorno = NULL, *Arvore = NULL; // Iniciando uma Arvore vazia

    do
    {
        clear();
        printf("\t 1 -> Inserir [Recursao com retorno]\n");
        printf("\t 2 -> Inserir [Recursao sem retorno]\n");
        printf("\t 3 -> Inserir [Iterativo sem retorno]\n");
        printf("\t 4 -> Imprimir [Pre - In - Pos]\n");
        printf("\t 5 -> Buscar [Recursao]\n");
        printf("\t 6 -> Buscar [Interativo]\n");
        printf("\t 7 -> Altura da Arvore [Recursivo]\n");
        printf("\t 8 -> Calcular Quantidade de Nos [Recursivo]\n");
        printf("\t 9 -> Calcular Quantidade de Folhas [Recursivo]\n");
        printf("\t10 -> Remover Elemento [Recursivo]\n");
        printf("\tOpcao: ");
        scanf("%d", &op);
        fflush(stdin);
        clear();

        switch (op)
        {
        case 1:
            printf("Informe o valor: ");
            scanf("%d", &dado);
            fflush(stdin);
            Arvore = inserirNoRec(Arvore, dado);
            clear();
            break;
        case 2:
            printf("Informe o valor: ");
            scanf("%d", &dado);
            fflush(stdin);
            inserirNoRec2(&Arvore, dado);
            clear();
            break;
        case 3:
            printf("Informe o valor: ");
            scanf("%d", &dado);
            fflush(stdin);
            inserirNoIterativo(&Arvore, dado);
            clear();
            break;
        case 4:
            if (Arvore == NULL)
            {
                printf("Arvore Vazia!\n");
            }
            else
            {
                printf("\n\n[Pre-Ordem]: Raiz, Subarvore esquerda, Subarvore direita.\n");
                imprimirPre(Arvore);
                printf("\n\n[In-Ordem]: Subarvore esquerda, Raiz, Subarvore direita.\n");
                imprimirIn(Arvore);
                printf("\n\n[Pos-Ordem]: Subarvore esquerda, Subarvore direita, Raiz.\n");
                imprimirPos(Arvore);
            }
            printf("\n");
            continuar();
            clear();
            break;
        case 5:
            printf("Informe o elemento a ser buscado: ");
            scanf("%d", &dado);
            fflush(stdin);
            retorno = buscaRecursiva(Arvore, dado);
            if (retorno)
            {
                printf("Elemento retornado: %d\n", retorno->dado);
            }
            else
            {
                printf("Elemento nao encontrado!");
            }
            continuar();
            clear();
            break;
        case 6:
            printf("Informe o elemento a ser buscado: ");
            scanf("%d", &dado);
            fflush(stdin);
            retorno = buscaIterativa(Arvore, dado);
            if (retorno)
            {
                printf("Elemento retornado: %d\n", retorno->dado);
            }
            else
            {
                printf("Elemento nao encontrado!");
            }
            continuar();
            clear();
            break;
        case 7:
            printf("Altura da Arvore: %d\n", alturaRecursiva(Arvore));
            continuar();
            clear();
            break;
        case 8:
            printf("Quantidade de nós da Arvore: %d\n", qtdNosRecursiva(Arvore));
            continuar();
            clear();
            break;
        case 9:
            printf("Quantida de folhas da Arvore: %d\n", qtdFolhasRecursiva(Arvore));
            continuar();
            clear();
            break;
        case 10:
            printf("Informe o valor que deseja remover: ");
            scanf("%d", &dado);
            fflush(stdin);
            Arvore = removerRecursivo(Arvore, dado);
            continuar();
            clear();
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (op != 0);

    return 0;
}