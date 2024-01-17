/*
    Exemplo de Leitura em arquivo.txt em C com fgets

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

int main()
{
    char texto[500];

    FILE *file;
    file = fopen("Exemplo.txt", "r"); // o arquivo deve existir!

    if (file)
    {
        system("cls");

        printf("\n");
        printf("[Dados lidos do arquivo]\n\n");

        // enquanto nao chegar no fim do arquivo le cada caractere e imprime
        while (!feof(file))
        {
            // 499 pois o 500 é \0 fim de linha
            // onde sera carregado, quantidade maxima de caracteres que serao lidos,
            // de onde serao lidos
            if (fgets(texto, 499, file))
            {
                printf("%s", texto);
            }
        }

        fclose(file);
    }
    else
    {
        printf("\n");
        printf("Erro na abertura do arquivo!\n");
    }

    system("pause");
    return 0;
}