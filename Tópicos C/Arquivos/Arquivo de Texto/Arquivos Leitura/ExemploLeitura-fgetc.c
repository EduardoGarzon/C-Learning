/*
    Exemplo de Leitura em arquivo.txt em C com fgetc

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
    char letra;

    FILE *file;
    file = fopen("Exemplo.txt", "r"); // o arquivo deve existir!

    if (file)
    {
        // enquanto nao chegar no fim do arquivo le cada caractere e imprime
        while (!feof(file))
        {
            letra = fgetc(file); // pega um caractere do arquivo
            printf("%c", letra);
        }
        printf("\n");

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