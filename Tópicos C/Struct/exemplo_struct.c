#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nome
{
    char nome[50];
} NOME[3];

void inserirNome(struct Nome *N)
{
    for (int i = 0; i < 3; i++) {
        printf("Nome: ");
        fgets(N[i].nome, 50, stdin);
    }
}

void printarNome(struct Nome *N)
{
    for (int i = 0; i < 3; i++) {
        printf("Nome[%d]: %s", i, N[i].nome);
    }
}

int main()
{
    inserirNome(NOME);
    printarNome(NOME);
    system("pause");
    return 0;
}