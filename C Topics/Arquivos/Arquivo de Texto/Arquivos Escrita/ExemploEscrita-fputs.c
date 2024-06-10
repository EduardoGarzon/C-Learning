/*
    Exemplo de criacao, abertura e escrita com fputs em arquivo .txt em C

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
#include <string.h>

int main()
{
    FILE *file; // ponteiro para o endereco do arquivo

    // nome do arquivo a ser aberto/criado e modo de abertura
    // a extensao do arquivo pode ser opcional, no nosso caso usamos .txt
    file = fopen("exemplo.txt", "w");

    if (file == NULL)
    {
        printf("\n");
        printf("Erro ao abrir arquivo!\n");
    }
    else
    {
        system("cls"); // limpa tela

        char texto[500]; // buffer de texto
        int count = 1;   // contador de linha

        printf("\n\t[Digite 1 caractere para finalizar]\n");
        printf("\n\t[A cada frase tecle [enter] para proxima linha]\n\n");

        printf("Linha [%d]:\n", count);
        scanf("%499[^\n]", texto);
        scanf("%c"); // limpa o ENTER que ficou no buffer do teclado

        while (strlen(texto) > 1)
        {
            fputs(texto, file); // armazena string no arquivo
            fputc('\n', file);  // armazena caractere no arquivo

            count++;

            printf("Linha [%d]:\n", count);
            scanf("%499[^\n]", texto);
            scanf("%c");
        }

        fclose(file);
    }

    system("pause");
    return 0;
}