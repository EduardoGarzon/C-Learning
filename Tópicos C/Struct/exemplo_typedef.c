#include <stdio.h>

typedef struct
{
    char nome[100];
    int idade;
} Pessoa;

void removerEnter(char *nome)
{
    nome[strcspn(nome, "\n")] = '\0';
}

void inserirDados(Pessoa *p)
{
    printf("NOME: ");
    fgets(p->nome, 100, stdin);
    removerEnter(p->nome);
    printf("IDADE: ");
    scanf("%d", &p->idade);
}

void exibirDados(Pessoa *p)
{
    printf("\nDADOS DA PESSOA:\n");
    printf("Nome: %s | Idade: %d\n", p->nome, p->idade);
}

int main()
{
    Pessoa p;

    inserirDados(&p);
    exibirDados(&p);

    return 0;
}