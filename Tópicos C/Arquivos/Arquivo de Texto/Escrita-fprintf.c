/*
    Exemplo de escrita em arquivo C utilizando fprintf

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
    file = fopen(nome, "w");

    char pessoa[100];
    int idade = 0;
    int option = 0;

    system("cls");

    if (file)
    {
        do
        {
            printf("Digite primeiro o nome de pois a idade:\n");
            scanf("%99[^\n]%d", pessoa, &idade);
            fprintf(file, "%s %d\n", pessoa, idade); // escreve string formatada
            printf("[1] Para Continuar | [2] Para Sair: ");
            scanf("%d", &option);
            fflush(stdin);
            system("cls");
        } while (option == 1);
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