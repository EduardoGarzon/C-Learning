/*
    Tabela Hash com struct
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2 * 15 = 31
#define TAM 15

typedef struct
{
    int dia, mes, ano;
} Data;

typedef struct
{
    char rua[50];
    char bairro[50];
    char cidade[50];
    char pais[50];
    int num, cep;
} Endereco;

typedef struct
{
    int codigo;
    Data dataAss;
    char cargo[50];
    float salario;
} Contrato;

typedef struct
{
    char nome[50];
    long long unsigned cpf;
    Data dataNas;
    Endereco end;
    Contrato contr;
} Pessoa;

// -------------- Impressão das informações de uma Pessoa ------------------------

void imprimirData(Data d)
{
    printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}

void imprimirEndereco(Endereco end)
{
    printf("\tEndereco:\n");
    printf("\t\tRua: %s", end.rua);
    printf("\t\tBairro: %s", end.bairro);
    printf("\t\tCidade: %s", end.cidade);
    printf("\t\tPais: %s", end.pais);
    printf("\t\tNumero: %d\n", end.num);
    printf("\t\tCep: %d\n", end.cep);
}

void imprimirContrato(Contrato c)
{
    printf("\tContrato %d:\n", c.codigo);
    printf("\t\tCargo: %s", c.cargo);
    printf("\t\tSalario R$%.2f\n", c.salario);
    printf("\t\tData de ad.: ");
    imprimirData(c.dataAss);
}

void imprimirPessoa(Pessoa p)
{
    printf("\n\tNome: %s", p.nome);
    printf("\tCpf: %lld\n", p.cpf);
    printf("\tData de nas.: ");
    imprimirData(p.dataNas);
    imprimirEndereco(p.end);
    imprimirContrato(p.contr);
}

// ------------ Leitura dos dados de uma Pessoa -------------------------

Data lerData()
{
    Data d;
    printf("\nDigite a data no formato dd mm aaaa: ");
    scanf("%d%d%d", &d.dia, &d.mes, &d.ano);
    getchar();
    return d;
}

Endereco lerEndereco()
{
    Endereco end;
    printf("\nRua: ");
    fflush(stdin);
    fgets(end.rua, sizeof(end.rua), stdin);
    printf("\nBairro: ");
    fflush(stdin);
    fgets(end.bairro, sizeof(end.bairro), stdin);
    printf("\nCidade: ");
    fflush(stdin);
    fgets(end.cidade, sizeof(end.cidade), stdin);
    printf("\nPais: ");
    fflush(stdin);
    fgets(end.pais, sizeof(end.pais), stdin);
    printf("\nNumero: ");
    scanf("%d", &end.num);
    printf("\nCep: ");
    scanf("%d", &end.cep);
    getchar();
    return end;
}

Contrato lerContrato()
{
    Contrato c;
    printf("\nCodigo do contrato: ");
    scanf("%d", &c.codigo);
    printf("\nData de assinatura:\n");
    c.dataAss = lerData();
    printf("\nCargo: ");
    fgets(c.cargo, sizeof(c.cargo), stdin);
    fflush(stdin);
    printf("\nSalario: R$");
    scanf("%f", &c.salario);
    getchar();
    return c;
}

Pessoa lerPessoa()
{
    Pessoa p;
    printf("\nNome: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    fflush(stdin);
    printf("\nCpf: ");
    scanf("%lld", &p.cpf);
    printf("\nData de nascimento:\n");
    p.dataNas = lerData();
    p.contr = lerContrato();
    p.end = lerEndereco();
    return p;
}

// ---------- Funções e procedimentos para a tabela hash -----------

void inicializarTabela(Pessoa t[])
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        t[i].cpf = 0;
    }
}

int funcaoHash(long long unsigned chave)
{
    return chave % TAM;
}

void inserir(Pessoa t[])
{
    Pessoa p = lerPessoa();
    int id = funcaoHash(p.cpf);
    while (t[id].cpf != 0)
    {
        id = funcaoHash(id + 1);
    }
    t[id] = p;
}

Pessoa *busca(Pessoa t[], long long unsigned chave)
{
    int id = funcaoHash(chave);
    printf("\nIndice gerado: %d\n", id);
    while (t[id].cpf != 0)
    {
        if (t[id].cpf == chave)
            return &t[id];
        else
            id = funcaoHash(id + 1);
    }
    return NULL;
}

void imprimir(Pessoa t[])
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        printf("%d\n", i);
        if (t[i].cpf != 0)
            imprimirPessoa(t[i]);
        printf("\n----------------------\n");
    }
}

int main()
{
    int opcao;
    long long unsigned valor;
    Pessoa *buscar, tabela[TAM];

    inicializarTabela(tabela);

    do
    {
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            inserir(tabela);
            break;
        case 2:
            printf("\tQual CPF deseja buscar? ");
            scanf("%lld", &valor);
            buscar = busca(tabela, valor);
            if (buscar)
            {
                printf("\nCPF encontrado:\n");
                imprimirPessoa(*buscar);
            }
            else
            {
                printf("\tCPF nao encontrado!\n");
            }
            break;
        case 3:
            imprimir(tabela);
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
