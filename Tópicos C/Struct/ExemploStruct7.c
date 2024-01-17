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

Cadastro c;

void clearScreen()
{
    system("cls");
}

void cadastrarPessoa()
{
    printf("\nCADASTRO DA PESSOA:\n");
    printf("Informe o nome: ");
    fgets(c.person.nome, 100, stdin);

    c.person.nome[strcspn(c.person.nome, "\n")] = '\0';

    printf("Informe o CPF: ");
    scanf("%lld", &c.person.CPF);
    fflush(stdin);

    printf("Informe a idade: ");
    scanf("%d", &c.person.idade);
    fflush(stdin);
}

void cadastrarUsuario()
{
    printf("\nCADASTRO DE USUARIO\n");
    printf("Informe o login: ");
    fgets(c.user.login, 100, stdin);

    c.user.login[strcspn(c.user.login, "\n")] = '\0';

    printf("Informe uma senha: ");
    fgets(c.user.senha, 100, stdin);
    fflush(stdin);

    c.user.senha[strcspn(c.user.senha, "\n")] = '\0';
}

void validarCadastroPessoa()
{
    if (c.person.nome != NULL && c.person.idade >= 18 && c.person.idade != 0)
    {
        c.validation = true;
        printf("DADOS VALIDADOS\n");
    }
    else
    {
        c.validation = false;
        printf("FALHA NA VALIDACAO\n");
    }

    printf("TECLE ENTER PARA PROSSEGUIR...\n");
    getchar();
}

void exibirCadastro()
{
    printf("DADOS DO CADASTRO\n\n");
    printf("\tPESSOA:\n");
    printf("\t\tNome: %s\n", c.person.nome);
    printf("\t\tCPF: %lld\n", c.person.CPF);
    printf("\t\tIdade: %d\n", c.person.idade);
    printf("\n\tUSUARIO:\n");
    printf("\t\tLogin: %s\n", c.user.login);
    printf("\t\tSenha: %s\n", c.user.senha);
    printf("\n\n");

    printf("TECLE ENTER PARA PROSSEGUIR...\n");
    getchar();
}

void Menu()
{
    clearScreen();

    int op = 0;

    printf("----- MENU DE OPCOES -----\n");
    printf("[1] Cadastrar Pessoa\n");
    printf("[2] Validar Pessoa\n");
    printf("[3] Cadastrar Usuario\n");
    printf("[4] Exibir Cadastro\n");
    printf("[5] SAIR\n");
    printf("Informe a opcao: ");
    scanf("%d", &op);
    fflush(stdin);

    clearScreen();

    switch (op)
    {
    case 1:
        cadastrarPessoa();
        Menu();

        break;
    case 2:
        validarCadastroPessoa(&c);
        Menu();

        break;
    case 3:
        cadastrarUsuario();
        Menu();

        break;
    case 4:
        exibirCadastro(&c);
        Menu();

        break;
    case 5:
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