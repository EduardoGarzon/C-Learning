/*
    Implementacao de uma Tabela Hash (Tabela de Espelhamento ou Dispersao) com vetor.

    Utilizada em processos de alto volume de busca
    na insercao e remocao em um periodo curto de tempo.

    É possivel acessar diretamente a posicao da tabela
    onde o elemento deve estar caso ele exista.

    Cada numero armazenado no vetor recebe o nome de chave ou chave hash
    para calcular a posicao do vetor em que sera inserido.

    Funcao Hash ou Espelhamento: espalhar os elementos pela tabela,
    descobrir a posicao em que o elemento sera armazenado.
    Metodo mais utilizado: posicao = valor a ser inserido % tamanho da tabela.

    Ao realizar a busca pelo elemento utilizamos a funcao hash
    que retorna a posicao onde verificamos se o conteudo procurado esta presente.
    Assim temos um acesso direto ao elemento sem precisar percorrer o vetor inteiro.

    Colisao: quando a Funcao Hash gera um indice ja ocupado na tabela hash.
    Nesse caso inserimos o valor na proxima posicao vazia.

    Construcao recomendada da Tabela Hash: numero primo mais proximo do dobro
    da quantidade de elementos que serao inserido na tabela.
    EX: 6 elementos, 12 é o dobro, 11 e 13 sao os primos mais proximos.
    Isso ajuda a reduzir as colisoes na tabela.

*/

#include <stdio.h>
#include <stdlib.h>

/*
    Considerando 15 elementos a serem inseridos,
    os numeros primos proximos do dobro do conjunto
    (2 * 15 == 30) sao 29 e 31. Escolhemos 31.
*/
#define TAM 31

// Procedimento que inicializa a Tabela Hash
void inicializarTabela(int T[])
{
    // Inicilizamos o vetor com zeros,
    // como forma de estabelecer os espacos em branco.
    int i;

    for (i = 0; i < TAM; i++)
    {
        T[i] = 0;
    }
}

// Funcao Hash
int funcaoHash(int chave)
{
    // O resto da divisao do valor a ser inserido pelo tamanho da tabela,
    // representa o indice em que o elemento sera inserido
    return chave % TAM;
}

// Procedimento para Insercao
void inserirHash(int T[], int valor)
{
    // Nao precisamos nos preocupar com o fim do vetor,
    // quando o fim do vetor for atingido o resto sera zero,
    // voltando automaticamente para o inicio do vetor.

    int id = funcaoHash(valor);
    while (T[id] != 0) // Caso ocorra colisao procura ate achar a proxima posicao vazia.
    {
        id = funcaoHash(id + 1);
    }
    T[id] = valor;
}

// Funcao para Remocao
int RemoverHash(int T[], int chave)
{
    int id = funcaoHash(chave);
    int tentantivas = 0;

    while (tentantivas < TAM)
    {
        if (T[id] == 0) // Elemento nao encontrado
        {
            printf("Elemento nao encontrado!\n");
            return 0;
        }

        if (T[id] == chave) // Elemento encontrado
        {
            printf("Posicao acessada: %d\n", id);
            T[id] = 0;
            return 1;
        }

        if (T[id] != 0) // Colisao da posicao
        {
            id = funcaoHash(id + 1);
        }
    }

    // Elemento nao encontrado apos percorrer todo o vetor
    return 0;
}

// Funcao de Busca
int buscarHash(int T[], int chave)
{
    int id = funcaoHash(chave);
    int tentativas = 0; // Contador para percorrer a tabela toda

    while (tentativas < TAM)
    {
        if (T[id] == 0) // Elemento não encontrado
        {
            return 0;
        }

        if (T[id] == chave) // Elemento encontrado
        {
            printf("Posicao acessada: %d\n", id);
            return T[id];
        }

        printf("Posicao com colisao: %d\n", id); // id com colisao
        id = funcaoHash(id + 1);
        tentativas++;
    }

    // Elemento não encontrado após percorrer toda a tabela
    return 0;
}

// Procedimento para impressao da Tabela Hash
void imprimirTabela(int T[])
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        printf("%d == %d\n", i, T[i]);
    }
}

void clear()
{
    system("cls");
}

void continuar()
{
    printf("Tecle [ENTER]  para continuar...");
    getchar();
}

int main()
{
    int op, valor, retorno, HASH[TAM];

    do
    {
        printf("\t1 - Inicizalizar Tabela\n");
        printf("\t2 - Inserir Elemento\n");
        printf("\t3 - Remover Elemento\n");
        printf("\t4 - Buscar Elemento\n");
        printf("\t5 - Imprimir Tabela\n");
        printf("\t6 - Sair\n");
        printf("\tInforme a opcao: ");
        scanf("%d", &op);
        fflush(stdin);
        clear();

        switch (op)
        {
        case 1:
            inicializarTabela(HASH);
            printf("Tabela inicializada!\n");
            continuar();
            clear();
            break;
        case 2:
            printf("Informe o elemento a ser inserido: ");
            scanf("%d", &valor);
            fflush(stdin);
            inserirHash(HASH, valor);
            printf("Elemento Inserido!\n");
            continuar();
            clear();
            break;
        case 3:
            printf("Informe o valor que deseja remover: ");
            scanf("%d", &valor);
            fflush(stdin);
            retorno = RemoverHash(HASH, valor);
            if (retorno == 1)
            {
                printf("Elemento removido!\n");
            }
            else
            {
                printf("Falha ao Remover.\n");
            }
            continuar();
            clear();
            break;
        case 4:
            printf("Informe o elemento a ser buscado: ");
            scanf("%d", &valor);
            fflush(stdin);
            retorno = buscarHash(HASH, valor);
            if (retorno != 0)
            {
                printf("Elemento retornado: %d\n", retorno);
            }
            else
            {
                printf("Elemento nao encontrado.\n");
            }
            continuar();
            clear();
            break;
        case 5:
            imprimirTabela(HASH);
            continuar();
            clear();
            break;
        case 6:
            printf("Encerrando programa...\n");
            break;
        default:
            printf("Opcao invalida, tente novamente!\n");
            continuar();
            clear();
            break;
        }

    } while (op != 6);

    return 0;
}