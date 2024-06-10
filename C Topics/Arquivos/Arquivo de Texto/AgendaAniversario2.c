/*
    Modos de abertura de arquivo em C:
        w  -> Escrita (cria o arquivo caso ele não exista e apaga todo seu conteudo caso exista)
        r  -> leitura
        a  -> anexar (adicionar informação ao final de um arquivo que já existe)
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Tamanho: formato dos espacos dos contatos da agenda
typedef struct tamanho
{
    int status;
    char nome[100];
    int idade;
    int dia, mes, ano;
} Tamanho;

// Agenda: quantidade de contatos e tamanho da agenda
typedef struct agenda
{
    int status;
    int tamanho;
    Tamanho contato[50];
} Agenda;

// Enter para prosseguir...
void tecleEnter()
{
    printf("Tecle [ENTER] para prosseguir...");
    getchar();
}

// Funcao que cria/reseta a agenda
void criarAgenda(char nomeArquivo[])
{
    printf("Informe o nome da Agenda: ");
    scanf("%99s", nomeArquivo); // Usar %99s para evitar estouro de buffer
    fflush(stdin);

    FILE *file;
    file = fopen(nomeArquivo, "w");
    if (file)
    {
        printf("\n");
        printf("Agenda [%s] criada/resetada no modo [w]!\n", nomeArquivo);

        fclose(file);

        tecleEnter();
    }
    else
    {
        printf("\n");
        printf("Erro ao abrir agenda [%s]!\n", nomeArquivo);

        tecleEnter();
    }
}

// Funcao que abre e carrega a agenda
void abrirAgenda(char nomeArquivo[], Agenda *agenda)
{
    char nomeAgenda[20];

    printf("Informe o nome da Agenda: ");
    scanf("%99s", nomeAgenda); // Usar %99s para evitar estouro de buffer
    fflush(stdin);

    FILE *file;
    file = fopen(nomeAgenda, "r");
    if (file)
    {
        int count = 0;
        while (fscanf(file, "ID: %d | Nome: %99[^|] | Idade: %d | Aniversario: %d/%d/%d\n", &count, agenda->contato[count].nome, &agenda->contato[count].idade, &agenda->contato[count].dia, &agenda->contato[count].mes, &agenda->contato[count].ano) != -1)
        {
            agenda->contato[count].status = 1;
            agenda->tamanho++;
            count++;
        }

        agenda->status = 1; // agenda aberta e carregada

        printf("\n");
        printf("Agenda [%s] existente e aberta!\n", nomeAgenda);

        fclose(file);

        strcpy(nomeArquivo, nomeAgenda);

        tecleEnter();
    }
    else
    {
        printf("\n");
        printf("A agenda [%s] nao existe!\n", nomeAgenda);

        tecleEnter();
    }
}

// Funcao para inserir contato no arquivo
void inserirContato(char nomeArquivo[], Agenda *agenda)
{
    int count = 0;

    if (agenda->tamanho <= 50)
    {
        if (agenda->tamanho == 0)
        {
            count = 0;
        }
        else if (agenda->contato[count].status == 0)
        {
            count = 0;
        }
        else
        {
            while (count < agenda->tamanho)
            {
                if (agenda->contato[count].status == 0)
                {
                    break;
                }
                else
                {
                    count++;
                }
            }
        }

        // leitura dos dados
        printf("Informe o nome do contato: ");
        scanf("%99[^\n]", agenda->contato[count].nome);
        printf("Informe a idade do contato: ");
        scanf("%d", &agenda->contato[count].idade);
        printf("Informe a data no formato [dia mes ano]: ");
        scanf("%d%d%d", &agenda->contato[count].dia, &agenda->contato[count].mes, &agenda->contato[count].ano);
        fflush(stdin);

        agenda->tamanho++;
        agenda->contato[count].status = 1;

        printf("\n");
        printf("Contato inserido com sucesso!\n");

        tecleEnter();
    }
    else
    {
        printf("\n");
        printf("Agenda cheia!\n");

        tecleEnter();
    }
}

// Funcao para remover contato no arquivo
void removerContato(Agenda *agenda)
{
    int id = 0;

    printf("Informe o ID do contato: ");
    scanf("%d", &id);
    fflush(stdin);

    if (id <= 50 && id >= 0)
    {
        agenda->contato[id].status = 0;
        agenda->tamanho--;

        printf("\n");
        printf("Contato desativado!\n");

        tecleEnter();
    }
    else
    {
        printf("\n");
        printf("ID invalido!\n");

        tecleEnter();
    }
}

// Funcao para imprimir contatos da agenda
void imprimirAgenda(Agenda *agenda)
{
    int count = 0;

    printf("--------------------CONTATOS--------------------\n");
    printf("Total de Contatos: [%d]\n\n", agenda->tamanho);

    while (count <= agenda->tamanho)
    {
        if (agenda->contato[count].status == 1)
        {
            printf("ID: %d | Nome: %s | Idade: %d | Aniversario: %d/%d/%d | STATUS: %d\n", count, agenda->contato[count].nome, agenda->contato[count].idade, agenda->contato[count].dia, agenda->contato[count].mes, agenda->contato[count].ano, agenda->contato[count].status);
        }
        count++;
    }

    tecleEnter();
}

// Funcao para atualizar o arquivo
void salvarAgenda(char nomeArquivo[], Agenda *agenda)
{
    FILE *file;
    file = fopen(nomeArquivo, "w");

    if (file)
    {
        int count = 0;
        int count2 = 0;

        while (count <= agenda->tamanho)
        {
            if (agenda->contato[count].status == 1)
            {
                fprintf(file, "ID: %d | Nome: %s | Idade: %d | Aniversario: %d/%d/%d\n", count2, agenda->contato[count].nome, agenda->contato[count].idade, agenda->contato[count].dia, agenda->contato[count].mes, agenda->contato[count].ano);

                count2++;
            }
            else
            {
                if (count2 == 0)
                {
                    count2 = 0;
                }
                else
                {
                    count2--;
                }
            }
            count++;
        }

        fclose(file);

        printf("\n");
        printf("Agenda salva com sucesso!\n");

        tecleEnter();
    }
    else
    {
        printf("\n");
        printf("Falha ao salvar arquivo!\n");

        tecleEnter();
    }
}

void Menu()
{
    Agenda agenda;
    agenda.tamanho = 0; // agenda vazia
    agenda.status = 0;  // agenda fechada e nao carregada

    char nomeArquivo[20];
    int op = 0;

    do
    {
        system("cls");
        printf("[------AGENDA EM ARQUIVO.TXT------]\n");
        printf("[                                 ]\n");
        printf("[      1 -> Criar/Resetar Agenda  ]\n");
        printf("[      2 -> Abrir Agenda          ]\n");
        printf("[      3 -> Inserir Contato       ]\n");
        printf("[      4 -> Remover Contato       ]\n");
        printf("[      5 -> Imprimir Agenda       ]\n");
        printf("[      7 -> Salvar                ]\n");
        printf("[      8 -> Sair                  ]\n");
        printf("[---------------------------------]\n");
        printf("Infome sua opcao: ");
        scanf("%d", &op);

        fflush(stdin);
        system("cls");

        switch (op)
        {
        case 1:
            criarAgenda(nomeArquivo);
            break;
        case 2:
            abrirAgenda(nomeArquivo, &agenda);
            break;
        case 3:
            if (agenda.status == 1)
            {
                inserirContato(nomeArquivo, &agenda);
            }
            else
            {
                printf("\n");
                printf("Agenda nao aberta!\n");

                tecleEnter();
            }
            break;
        case 4:
            if (agenda.status == 1)
            {
                removerContato(&agenda);
            }
            else
            {
                printf("\n");
                printf("Agenda nao aberta!\n");

                tecleEnter();
            }
            break;
        case 5:
            if (agenda.status == 1)
            {
                imprimirAgenda(&agenda);
            }
            else
            {
                printf("\n");
                printf("Agenda nao aberta!\n");

                tecleEnter();
            }
            break;
        case 7:
            if (agenda.status == 1)
            {
                salvarAgenda(nomeArquivo, &agenda);
            }
            else
            {
                printf("\n");
                printf("Agenda nao aberta!\n");

                tecleEnter();
            }
            break;
        default:
            printf("\n");
            printf("Erro ou Opcao invalida, tente novamente!\n");
            break;
        }
    } while (op != 8);
}

int main()
{
    Menu();

    system("pause");
    return 0;
}