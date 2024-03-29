// Exemplo de arquivo em C.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *pont_arq;
    char c;

    pont_arq = fopen("exemplo2.txt", "r");
    if (pont_arq == NULL)
    {
        printf("Erro ao tentar abrir o arquivo!");
        exit(1);
    }

    printf("Lendo e exibindo os dados do arquivo \n\n");

    do
    {
        // faz a leitura do caracter no arquivo apontado por pont_arq
        c = fgetc(pont_arq);

        // exibe o caracter lido na tela
        printf("%c", c);
    } while (c != EOF); // enquanto não for final de arquivo

    fclose(pont_arq); // fechando o arquivo

    system("pause"); // pausa na tela, somente para Windows
    return (0);
}