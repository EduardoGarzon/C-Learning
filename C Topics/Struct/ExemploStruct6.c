#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia, mes, ano;
} DataNas;

typedef struct
{
    DataNas dataNas;
    int idade;
    char sexo;
    char nome[100];
} Pessoa;

void imprimirPessoa(Pessoa p)
{
    printf("\n\tNome: %s", p.nome);
    printf("\tIdade: %d\n", p.idade);
    printf("\tSexo: %c\n", p.sexo);
    printf("\tData de nas.: %d/%d/%d\n\n", p.dataNas.dia, p.dataNas.mes, p.dataNas.ano);
}

// função que lê os dados de uma pessoa e retorna para quem chamou
Pessoa lerPessoa()
{
    Pessoa p;

    printf("Digite seu nome: ");
    fgets(p.nome, 100, stdin);

    printf("Digite sua idade: ");
    scanf("%d", &p.idade);
    scanf("%c");

    printf("Digite f ou m para o sexo:");
    scanf("%c", &p.sexo);

    printf("Digite sua data de nascimento no formato dd mm aaaa:");
    scanf("%d%d%d", &p.dataNas.dia, &p.dataNas.mes, &p.dataNas.ano);
    scanf("%c");

    printf("\n");

    return p;
}

int main()
{

    Pessoa pessoas[2][2];
    int l, c;

    // preenche a matriz com pessoas lidas do teclado
    for (l = 0; l < 2; l++)
    {
        for (c = 0; c < 2; c++)
            pessoas[l][c] = lerPessoa();
    }

    // imprime a matriz de pessoas
    for (l = 0; l < 2; l++)
    {
        for (c = 0; c < 2; c++)
            imprimirPessoa(pessoas[l][c]);
    }

    system("pause");
    return 0;
}