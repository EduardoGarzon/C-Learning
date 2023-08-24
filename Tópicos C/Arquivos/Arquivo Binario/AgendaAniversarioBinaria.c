#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int dia, mes, ano;
} Contato;

void imprimir(Contato **c, int quant)
{
    int i;

    printf("\n\t\tLista de Contatos:\n");
    printf("\t--------------------------------\n");
    for (i = 0; i < quant; i++)
    {
        printf("\t%d = %2d/%2d/%4d\t%s\n", i + 1, c[i]->dia, c[i]->mes, c[i]->ano, c[i]->nome);
    }
    printf("\t--------------------------------\n");
    getchar();
}

int cadastrar_contato(Contato **c, int quant, int tam)
{
    if (quant < tam)
    {
        Contato *novo = malloc(sizeof(Contato));

        printf("\nDigite o nome do contato: ");
        scanf("%49[^\n]", novo->nome);
        printf("\nDigite a data de aniversario dd mm aaaa: ");
        scanf("%d%d%d", &novo->dia, &novo->mes, &novo->ano);
        c[quant] = novo;
        return 1;
    }
    else
    {
        printf("\n\tImpossivel novo cadastro. Vetor cheio!\n");
        getchar();
        return 0;
    }
}

void salvarB(char arq[], Contato **c, int quant)
{
    FILE *file = fopen(arq, "wb");
    int i;

    if (file)
    {
        for (i = 0; i < quant; i++)
            fwrite(c[i], sizeof(Contato), 1, file);
        fclose(file);
    }
    else
        printf("\nErro ao abrir arquivo!\n");
}

int lerB(char arq[], Contato **c)
{
    int quant = 0;
    FILE *file = fopen(arq, "rb");

    if (file)
    {
        Contato *novo = malloc(sizeof(Contato)); // Move a alocação para dentro do loop

        while (fread(novo, sizeof(Contato), 1, file))
        {
            c[quant] = novo;
            quant++;

            novo = malloc(sizeof(Contato)); // Aloca novo espaço para o próximo contato
        }
        free(novo); // Libera a última alocação não usada
        fclose(file);
    }
    else
        printf("\nErro ao abrir arquivo!\n");

    return quant;
}

void alterarB(char arq[])
{
    FILE *file = fopen(arq, "rb+");
    Contato c;
    int id, i = 0;

    if (file)
    {
        printf("\tLista de contatos:\n");
        printf("\t----------------------------\n");
        while (fread(&c, sizeof(Contato), 1, file))
        {
            printf("\t%d = %2d/%2d/%4d\t%s\n", i + 1, c.dia, c.mes, c.ano, c.nome);
            i++;
        }
        printf("\t----------------------------\n");

        printf("\n\tDigite o indice do contato que deseja alterar:\n\n");
        scanf("%d", &id);
        getchar();
        id--;

        if (id >= 0 && id < i)
        {
            printf("\tDigite nome e data de nascimento dd mm aaaa: ");
            scanf(" %49[^\n] %d%d%d", c.nome, &c.dia, &c.mes, &c.ano);

            fseek(file, id * sizeof(Contato), SEEK_SET);
            fwrite(&c, sizeof(Contato), 1, file);
            fflush(file); // Adicionar essa linha para garantir a escrita imediata no arquivo
        }
        else
        {
            printf("\n\tIndice de contato invalido!\n");
            getchar();
        }

        fclose(file);
    }
    else
    {
        printf("\nErro ao abrir arquivo!\n");
        getchar();
    }
}

int main()
{
    Contato *agenda[50];
    char arquivo2[] = {"agenda.dat"};
    int opcao, tam = 50, quant = 0;

    do
    {
        system("cls");
        printf("\n\t0 - Sair\n\t1 - Cadastrar\n\t2 - Imprimir\n");
        printf("\t3 - SalvarB\n\t4 - LerB\n\t5 - AlterarB\n"); // Correção na opção "AlterarB"
        scanf("%d", &opcao);
        getchar();
        system("cls");
        switch (opcao)
        {
        case 1:
            quant += cadastrar_contato(agenda, quant, tam);
            break;
        case 2:
            imprimir(agenda, quant);
            break;
        case 3:
            salvarB(arquivo2, agenda, quant);
            break;
        case 4:
            quant = lerB(arquivo2, agenda);
            break;
        case 5:
            alterarB(arquivo2);
            break;
        default:
            if (opcao != 0)
                printf("\n\tOpcao invalida!!!\n");
        }
    } while (opcao != 0);

    return 0;
}
