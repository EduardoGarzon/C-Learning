/*
    Como remover / apagar um arquivo com a função remove?
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // nome do arquivo
    char nome[] = {"agenda.txt"};

    // tenta abrir o arquivo para escrita
    FILE *file = fopen(nome, "w");

    if (file)
    {
        printf("\n");
        printf("Arquivo aberto com sucesso!\n");

        fclose(file);

        // tenta remover o arquivo agenda.txt
        printf("\n");
        printf("Retorno: %d\n", remove(nome));
    }
    else
    {
        printf("\n");
        printf("Erro ao abrir o arquivo!\n");

        // Ao tentar remover um arquivo que não existe a função retorna o valor -1
        printf("\n");
        printf("Retorno: %d\n", remove(nome));
    }

    system("pause");
    return 0;
}