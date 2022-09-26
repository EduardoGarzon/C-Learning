#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Agenda com base em arquivo binario
*/

typedef struct contato
{
    char nome[11];
    char telefone[11];
} contato;

FILE *file;
int op = 0;

int main()
{
    openfile();
    menu();

    return 0;
}

void menu()
{
    op = 0;
    printf("========================================\n");
    printf("           AGENDA DE CONTATOS           \n");
    printf("========================================\n");
    printf("[1] - Inserir contato\n");
    printf("[2] - Buscar contato\n");
    printf("[3] - Alterar Informacoes do Contato \n");
    printf("[4] - Exibir agenda \n");
    printf("[5] - Sair do programa\n");
    printf("========================================\n");
    printf("Informe a opcao desejada: ");
    scanf("%d", &op);
    fflush(stdin);
    clear_screen();
    switch (op)
    {
    case 1:
        add();
        break;
    case 2:
        search();
        break;
    case 3:
        change();
        break;
    case 4:
        show();
        break;
    default:
        printf("Programa encerrado.\n");
        break;
    }
}

void openfile()
{
    file = fopen("agenda.txt", "ab+");
    if (file == NULL)
    {
        printf("Erro na abertura do arquivo.");
        exit(0);
    }
    fclose(file);
}

void add()
{
    file = fopen("agenda.txt", "ab");
    if (file == NULL)
    {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }
    else
    {
        contato ctt;
        printf("NOME: ");
        scanf("%s", ctt.nome);
        fflush(stdin);
        printf("TELEFONE: ");
        scanf("%s", &ctt.telefone);
        fflush(stdin);

        int ok = fwrite(&ctt, 1, sizeof(contato), file);
        printf("Contato adicionado com sucesso: %d\n", ok);
        printf("===================================================\n");
        printf("Adicionar outro contato? [1 - SIM | 0 - NAO]: ");
        scanf("%d", &op);
        fflush(stdin);
        fclose(file);
        if (op == 1)
        {
            clear_screen();
            add();
        }
        else if (op == 0)
        {
            clear_screen();
            menu();
        }
    }
}

void search()
{
    file = fopen("agenda.txt", "rb");
    if (file == NULL)
    {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }
    else
    {
        contato ctt;
        int found = 0;
        char nomectt[11];
        printf("Informe o nome do contato: ");
        scanf("%s", &nomectt);
        fflush(stdin);
        while (found == 0 && !feof(file))
        {
            fread(&ctt, sizeof(contato), 1, file);
            if (strcmp(nomectt, ctt.nome) == 0)
            {
                found = 1;
                printf("===============================================\n");
                printf("NOME: %s | TELEFONE: %s\n", ctt.nome, ctt.telefone);
                printf("===============================================\n");
            }
        }
        if (feof(file) && found == 0)
        {
            printf("CONTATO NAO ENCONTRADO!\n");
        }
    }
    fclose(file);
    printf("Buscar novamente? [1 - SIM | 0 - NAO]: ");
    scanf("%d", &op);
    fflush(stdin);
    if (op == 1)
    {
        clear_screen();
        search();
    }
    else if (op == 0)
    {
        clear_screen();
        menu();
    }
}

void change()
{
    file = fopen("agenda.txt", "rb+");
    if (file == NULL)
    {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }
    else
    {
        contato ctt;
        int found = 0;
        char nomectt[11];
        printf("Informe o nome do contato: ");
        scanf("%s", &nomectt);
        fflush(stdin);
        while (found == 0 && !feof(file))
        {
            fread(&ctt, sizeof(contato), 1, file);
            if (strcmp(nomectt, ctt.nome) == 0)
            {
                found = 1;
                printf("===============================================\n");
                printf("Informe o novo nome: ");
                scanf("%s", &ctt.nome);
                fflush(stdin);
                printf("Informe o novo telefone: ");
                scanf("%s", &ctt.telefone);
                fseek(file, -sizeof(contato), SEEK_CUR);
                int ok = fwrite(&ctt, sizeof(contato), 1, file);
                printf("Contato alterado com sucesso: %d\n", ok);
                printf("===============================================\n");
            }
        }
    }
    fclose(file);
    printf("Alterar outro contato? [1 - SIM | 0 - NAO]: ");
    scanf("%d", &op);
    fflush(stdin);
    if (op == 1)
    {
        clear_screen();
        change();
    }
    else if (op == 0)
    {
        clear_screen();
        menu();
    }
}

void show()
{
    file = fopen("agenda.txt", "rb");
    if (file == NULL)
    {
        printf("Erro na abertura do arquivo.\n");
    }
    else
    {
        contato ctt;
        while (!feof(file))
        {
            fread(&ctt, sizeof(contato), 1, file);
            if (!feof(file))
            {
                printf("===============================================\n");
                printf("NOME: %s | TELEFONE: %s\n", ctt.nome, ctt.telefone);
                printf("===============================================\n");
            }
        }
    }
    fclose(file);
    printf("Digite [1] para retornar: ");
    scanf("%d", &op);
    fflush(stdin);
    if (op == 1)
    {
        clear_screen();
        menu();
    }
}

void clear_screen()
{
    system("cls");
}