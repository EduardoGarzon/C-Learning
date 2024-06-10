#include <stdio.h>
#include <string.h>

struct Datas
{
    int ano, mes, dia;
} datas;

typedef struct
{
    char nome[100];
    struct Datas aniversario;
} Pessoa;

void inserirNome(Pessoa *p)
{
    printf("Informe o Nome: ");
    fgets(p->nome, 100, stdin);

    p->nome[strcspn(p->nome, "\n")] = '\0';
}

void inserirAniversario(Pessoa *p)
{
    printf("Informe sua data de aniversario (dd/mm/aa): ");
    scanf("%d/%d/%d", &p->aniversario.dia, &p->aniversario.mes, &p->aniversario.ano);
}

void exibirDados(Pessoa *p)
{
    printf("\nDADOS DA PESSOA\n");
    printf("Nome: %s\n", p->nome);
    printf("Data de Aniversario: %d/%d/%d\n", p->aniversario.dia, p->aniversario.mes, p->aniversario.ano);
}

int main()
{
    Pessoa p;

    inserirNome(&p);
    inserirAniversario(&p);
    exibirDados(&p);

    system("pause");
    return 0;
}