// exemplo de alocacao dinamica e ordenacao de vetores

#include <stdio.h>
#include <stdlib.h>

unsigned int tamanho; // variavel para o tamanho do vetor
int *vetor;
int opcao;
int i = 0; // indice atual da insercao dos valores
int x = 0; // flag para limitar apenas uma alocacao

void menu() // menu de opcaoes
{
    printf("1 - Alocar vetor\n");
    printf("2 - Inserir valores\n");
    printf("3 - Exibir valores\n");
    printf("4 - Ordenar vetor\n");
    printf("5 - Finalizar\n");
    scanf("%d", &opcao);
    system("cls");
    switch (opcao)
    {
    case 1:
        alocar();
        break;
    case 2:
        inserir();
        break;
    case 3:
        exibir();
        break;
    case 4:
        ordenar();
        break;
    case 5:
        end();
        break;
    default:
        break;
    }
}

void alocar() // alocando vetor
{
    if (x == 0)
    {
        printf("Informe o tamanho do vetor: "); // informando tamanho desejado para o vetor
        scanf("%d", &tamanho);
        vetor = (int *)malloc(tamanho * sizeof(int));
        if (vetor == NULL) // teste na alocacao
        {
            printf("\nErro na Alocacao!\n");
            exit(1);
        }
        x = 1; // muda para 1, permitindo apenas uma alocacao
    }
    else
    {
        printf("Vetor ja alocado.");
    }
    printf("\n\n");
    menu();
}

void inserir() // insere valores no vetor
{
    if (i >= tamanho)
    {
        printf("Espaco totalmente utilzado.");
    }
    else
    {
        int res = 1;
        while (i < tamanho && res == 1) // informando valores
        {
            printf("Informe um valor inteiro: ");
            scanf("%d", &vetor[i]);
            i++;
            printf("Continuar [Sim: 1 | Nao: 2]: ");
            scanf("%d", &res);
        }
    }
    printf("\n\n");
    menu();
}

void exibir() // exibe valores do vetor
{
    if (vetor == NULL)
    {
        printf("Vetor vazio!");
    }
    else
    {
        printf("VALORES: ");
        for (int z = 0; z < i; z++)
        {
            printf("[%d] ", vetor[z]);
        }
    }
    printf("\n\n");
    menu();
}

void ordenar() // ordena vetor
{
    int aux;
    for (int a = 0; a < tamanho; a++)
    {
        for (int b = 0; b < tamanho; b++)
        {
            if (vetor[a] < vetor[b])
            {
                aux = vetor[a];
                vetor[a] = vetor[b];
                vetor[b] = aux;
            }
        }
    }
    menu();
}

void end() // libera e finaliza programa
{
    free(vetor);
    exit(1);
}

int main()
{
    menu();
    return 0;
}