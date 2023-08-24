#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char login[20];
    char senha[20];
} Usuario;

typedef struct
{
    char nome[100];
    long long int CPF;
    int idade;
} Pessoa;

typedef struct
{
    bool validation;
    Usuario user;
    Pessoa person;
} Cadastro;

Pessoa p;
Usuario u;
Cadastro c;

void clearScreen()
{
    system("cls");
}

Pessoa cadastrarPessoa()
{
    Pessoa p;

    printf("\nCADASTRO DA PESSOA:\n");
    printf("Informe o nome: ");
    fgets(p.nome, 100, stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';
    printf("Informe o CPF: ");
    scanf("%lld", &p.CPF);
    fflush(stdin);
    printf("Informe a idade: ");
    scanf("%d", &p.idade);
    fflush(stdin);

    return p;
}

Usuario cadastrarUsuario()
{
    Usuario c;

    printf("\nCADASTRO DE USUARIO\n");
    printf("Informe o login: ");
    fgets(c.login, 100, stdin);
    c.login[strcspn(c.login, "\n")] = '\0';
    printf("Informe uma senha: ");
    fgets(c.senha, 100, stdin);
    c.senha[strcspn(c.senha, "\n")] = '\0';
    fflush(stdin);

    return c;
}

Cadastro validarCadastroPessoa(Pessoa *p)
{
    Cadastro c;

    if (p->nome != NULL && p->idade >= 18 && p->CPF != 0)
    {
        c.validation = true;
        printf("DADOS VALIDADOS\n");
    }
    else
    {
        c.validation = false;
        printf("FALHA NA VALIDACAO\n");
    }

    printf("\nTECLE ENTER PARA PROSSEGUIR...");
    getchar();
    fflush(stdin);

    return c;
}

void inserirCadastro(Pessoa *p, Usuario *u, Cadastro *c)
{
    if (!c->validation)
    {
        printf("Impossivel criar cadastro, dados nao validados!\n");

        printf("\nTECLE ENTER PARA PROSSEGUIR...");
        getchar();
        fflush(stdin);
    }
    else
    {
        c->person = *(p);
        c->user = *(u);
        printf("Cadastro realizado com sucesso!\n");

        printf("\nTECLE ENTER PARA PROSSEGUIR...");
        getchar();
        fflush(stdin);
    }
}

void exibirCadastro(Cadastro *c)
{
    printf("DADOS DO CADASTRO\n\n");
    printf("\tPESSOA:\n");
    printf("\t\tNome: %s\n", c->person.nome);
    printf("\t\tCPF: %lld\n", c->person.CPF);
    printf("\t\tIdade: %d\n", c->person.idade);
    printf("\n\tUSUARIO:\n");
    printf("\t\tLogin: %s\n", c->user.login);
    printf("\t\tSenha: %s\n", c->user.senha);
    printf("\n\n");

    printf("TECLE ENTER PARA PROSSEGUIR...");
    getchar();
    fflush(stdin);
}

void Menu()
{
    clearScreen();

    int op = 0;

    printf("----- MENU DE OPCOES -----\n");
    printf("[1] Cadastrar Pessoa\n");
    printf("[2] Validar Pessoa\n");
    printf("[3] Cadastrar Usuario\n");
    printf("[4] Inserir Cadastro\n");
    printf("[5] Exibir Cadastro\n");
    printf("[6] SAIR\n");
    printf("Informe a opcao: ");
    scanf("%d", &op);
    fflush(stdin);
    clearScreen();

    switch (op)
    {
    case 1:
        p = cadastrarPessoa();
        Menu();
        break;
    case 2:
        c = validarCadastroPessoa(&p);
        Menu();
        break;
    case 3:
        u = cadastrarUsuario();
        Menu();
        break;
    case 4:
        inserirCadastro(&p, &u, &c);
        Menu();
        break;
    case 5:
        exibirCadastro(&c);
        Menu();
        break;
    case 6:
        printf("PROGRAMA FINALIZADO!\n");
        exit(0);
        break;
    default:
        printf("Opcao Invalida!\n");
        Menu();
        break;
    }
}

int main()
{
    Menu();

    system("pause");
    return 0;
}