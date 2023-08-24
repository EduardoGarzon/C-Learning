#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef _linux_
#include <unistd.h>
#elif _WIN32
#include <windows.h>
#endif

typedef struct contato
{
    int codigo;
    char nome[50];
    int telefone;
    int idade;
} contato;

FILE *f;

int criar();
int inserir();
int alterar();
int busca();
int imprimir();
void limpa_tela();

int main()
{
    int op;
    f = fopen("agendinha.txt", "ab");

    while (op != 6)
    {
        printf("\n\n---------------Agenda-------------");
        printf("\n1. Criar arquivo");
        printf("\n2. Inserir contatos");
        printf("\n3. Alterar informacoes de um contato");
        printf("\n4. Buscar um contato na agenda");
        printf("\n5. Imprimir o arquivo");
        printf("\n6. Sair");
        printf("\n\nInforme a sua opcao:\n");
        scanf("%d", &op);
        limpa_tela();

        switch (op)
        {
        case (1):
            criar();
            break;
        case (2):
            inserir();
            break;
        case (3):
            alterar();
            break;
        case (4):
            busca();
            break;
        case (5):
            imprimir();
            break;
        case (6):
            printf("\nFim de Programa\n");
            break;
        default:
            printf("\nERRO! Digite novamente:\n");
            break;
        }
    }
    fclose(f);
    return 0;
}

int criar()
{
    f = fopen("agendinha.txt", "ab");
    if (f != NULL)
    {
        printf("\n    * O arquivo foi criado! * \n");
        fclose(f);
    }
    else
        printf("\n    * Erro na criacao do arquivo! * \n");
    return 0;
}

int inserir()
{
    int resp, encontrou, op, ok, aux;
    char nome[50];
    contato pessoa;

    f = fopen("agendinha.txt", "ab");
    if (f == NULL)
        printf("\nErro ao abrir arquivo!\n");
    else
    {
        printf("\n=================================================");
        printf("\n    Digite os dados do contato!\n");
        printf("\nCodigo: ");
        scanf("%d", &pessoa.codigo);
        printf("\nNome: ");
        fflush(stdin);
        scanf("%s", pessoa.nome);
        printf("\nTelefone: ");
        scanf("%d", &pessoa.telefone);
        printf("\nIdade: ");
        scanf("%d", &pessoa.idade);
        fwrite(&pessoa, sizeof(contato), 1, f);
        printf("\nCadastro feito com sucesso!\n");
        printf("\n=================================================");
    }
    fclose(f);
    return 0;
}

int alterar()
{
    int resp, encontrou, op, ok, aux;
    char nome[50];
    contato pessoa;

    f = fopen("agendinha.txt", "rb+");
    if (f == NULL)
        printf("\nErro ao abrir arquivo!\n");
    else
    {
        printf("\n=================================================");
        printf("\n\nDigite o nome do contato a ser alterado: ");
        fflush(stdin);
        scanf("%s", nome);

        encontrou = 0;

        while (encontrou == 0 && !feof(f))
        {
            fread(&pessoa, sizeof(contato), 1, f);
            if (!feof(f) && strcmp(nome, pessoa.nome) == 0)
            {
                encontrou = 1;

                printf("\nContato Encontrado!");
                printf("\nDigite seus dados novamente!");
                printf("\n\nCodigo atual: ");
                scanf("%d", &pessoa.codigo);
                printf("\nNome atual: ");
                fflush(stdin);
                scanf("%s", pessoa.nome);
                printf("\nTelefone atual: ");
                scanf("%d", &pessoa.telefone);
                printf("\nIdade atual: ");
                scanf("%d", &pessoa.idade);
                printf("\n\t++++++++++++++++++++");
                printf("\n\tCodigo: %d\n\tNome: %s\n\tEndereco: %d\n\tTelefone: %d\n", pessoa.codigo, pessoa.nome, pessoa.telefone, pessoa.idade);
                printf("\t++++++++++++++++++++");

                fseek(f, -sizeof(contato), SEEK_CUR);
                ok = fwrite(&pessoa, sizeof(contato), 1, f);

                printf("\n\nCadastro Alterado com sucesso: %d\n", ok);
                printf("\n=================================================\n");
            }
        }
        fclose(f);
    }
    return 0;
}

int busca()
{
    int resp, encontrou, op, ok, aux;
    char nome[50];
    contato pessoa;

    f = fopen("agendinha.txt", "rb");
    if (f == NULL)
        printf("\nErro ao abrir arquivo!\n");
    else
    {
        printf("\nDigite o nome do contato a ser Consultado: ");
        fflush(stdin);
        scanf("%s", nome);
        encontrou = 0;
        while (encontrou == 0 && !feof(f))
        {
            fread(&pessoa, sizeof(contato), 1, f);
            if (strcmp(nome, pessoa.nome) == 0)
            {
                encontrou = 1;
                printf("\n=================================================");
                printf("\n\tContato Encontrado!\n");
                printf("\nCodigo: %d\nNome: %s\nEndereco: %d\nTelefone: %d\n", pessoa.codigo, pessoa.nome, pessoa.telefone, pessoa.idade);
                printf("\n=================================================\n");
            }
        } 
        if (encontrou == 0 && feof(f))
            printf("\nPessoa nao encontrada!\n");
        fclose(f);
    }
    return 0;
}

int imprimir()
{
    int resp, encontrou, op, ok, aux;
    char nome[50];
    contato pessoa;

    f = fopen("agendinha.txt", "rb");
    if (f == NULL)
        printf("\nErro ao abrir arquivo!\n");
    else
    {
        printf("\n============================================================================");
        while (!feof(f))
        {
            fread(&pessoa, sizeof(contato), 1, f);
            if (!feof(f))
                printf("\nCodigo: %d\tNome: %s\tTelefone: %d\tIdade: %d\t", pessoa.codigo, pessoa.nome, pessoa.telefone, pessoa.idade);
        }
        printf("\n============================================================================");
    }
    fclose(f);
    return 0;
}

void limpa_tela(void)
{
// Comando para os dois sistemas operacionais limparem a tela
#ifdef _linux_
    system("clear");
#elif _WIN32
    system("cls");
#else
#endif
}