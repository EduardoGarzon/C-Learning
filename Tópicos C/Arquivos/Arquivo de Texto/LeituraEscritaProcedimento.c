/*
    Exemplo de leitura e escrita em arquivo.txt em C por meio de procedimentos
    com fgetc e fputc

    Modos de abertura de arquivos:
        w  -> Escrita
        r  -> leitura
        a  -> anexar
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)
*/

#include <stdio.h>
#include <stdlib.h>

void criarArquivo(const char nomeArquivo[], const char modoAbertura[])
{
    printf("Informe o nome do arquivo: ");
    scanf("%99s", nomeArquivo); // Usar %99s para evitar estouro de buffer
    fflush(stdin);

    printf("Informe o modo de abertura do arquivo: ");
    scanf("%2s", modoAbertura); // Usar %2s para capturar apenas 2 caracteres (modo + caractere nulo)
    fflush(stdin);

    FILE *file;
    file = fopen(nomeArquivo, modoAbertura);
    if (file)
    {
        printf("\nArquivo %s criado/aberto no modo %s!\n", nomeArquivo, modoAbertura);
        fclose(file);
    }
    else
    {
        printf("\nErro ao abrir arquivo!\n");
        exit(1);
    }
}

void escreverArquivo(const char nomeArquivo[])
{
    FILE *file;
    file = fopen(nomeArquivo, "a");

    char letra;
    if (file)
    {
        printf("\nDigite algo e tecle [ENTER] para finalizar!\n");
        scanf("%c", &letra);
        while (letra != '\n')
        {
            fputc(letra, file);
            scanf("%c", &letra);
        }
        printf("\n\nDado escrito no arquivo!\n");
        fclose(file);
    }
    else
    {
        printf("\nErro ao escrever no arquivo!\n");
    }
}

void lerArquivo(const char nomeArquivo[])
{
    FILE *file;
    file = fopen(nomeArquivo, "r");

    char letra;
    if (file)
    {
        printf("\nDados lidos do arquivo:\n");
        while (!feof(file))
        {
            letra = fgetc(file);
            printf("%c", letra);
        }
        printf("\n");
        fclose(file);
    }
    else
    {
        printf("\nErro ao ler arquivo!\n");
    }
}

int main()
{
    char nomeArquivo[100];
    char modoAbertura[3];

    criarArquivo(nomeArquivo, modoAbertura);
    escreverArquivo(nomeArquivo);
    lerArquivo(nomeArquivo);

    return 0;
}