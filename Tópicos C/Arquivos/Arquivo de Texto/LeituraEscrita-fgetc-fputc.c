/*
    Exemplo de leitura e escrita em arquivo C com fgetc e fputc

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
    file = fopen("Exemplo.txt", "w+");

    if (file)
    {
        printf("Digite algo e tecle [ENTER] para finalizar!\n");
        scanf("%c", &letra);
        while (letra != '\n')
        {
            fputc(letra, file); // leitura
            scanf("%c", &letra);
        }

        rewind(file); // move o ponteiro para o inicio da arquivo

        printf("\n\nLeitura do arquivo:\n");
        while (!feof(file))
        {
            letra = fgetc(file); // escrita
            printf("%c", letra);
        }
        scanf("\n");
    }
    else
    {
        printf("Erro ao abrir o arquivo!\n");
    }

    fclose(file); // fecha o arquivo

    return 0;
}