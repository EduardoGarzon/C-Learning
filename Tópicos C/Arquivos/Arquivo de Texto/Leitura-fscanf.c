/*
    Exemplo de leitura em arquivo C com fscanf.

    Modos de abertura de arquivo em C:
        w  -> Escrita (cria o arquivo caso ele não exista e apaga todo seu conteudo caso exista)
        r  -> leitura
        a  -> anexar (adicionar informação ao final de um arquivo que já existe)
        r+ -> leitura e escrita
        w+ -> leitura e escrita (apaga o conteúdo caso o arquivo exista)
        a+ -> leitura e escrita (adiciona ao final do arquivo)
*/

#include <stdio.h>
#include <stdlib.h>

void escreverArquivo(char nome[])
{
    FILE *file;
    file = fopen(nome, "r");

    char pessoa[100];
    int idade = 0;

    system("cls");

    if (file)
    {
        printf("Dados lidos do arquivo:\n");
        // realiza leitura enquanto o retorno nao for feof
        // leitura de string formatada
        // nao le strings com espacos, ele quebra a linha
        while (fscanf(file, "%s%d", pessoa, &idade) != -1)
        {
            printf("Nome: %s | Idade: %d\n", pessoa, idade);
            fflush(stdin);
        }
        fclose(file);
    }
    else
    {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
}

int main()
{
    char nome[] = {"Exemplo.txt"};

    escreverArquivo(nome);

    return 0;
}