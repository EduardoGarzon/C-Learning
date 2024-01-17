#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra;

    printf("Informe um caractere: ");
    letra = fgetc(stdin);

    printf("Caractere informado: %c\n", letra);

    /*
        fgetc faz parte das funcoes especificas
        para leitura de dados em arquivos,
        o f indica file recebe como parametro o nome do arquivo
        de onde sera feita a leitura.
    */

    system("pause");
    return 0;
}