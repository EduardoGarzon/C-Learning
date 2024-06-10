/*
    Solicite ao usuário o seu endereço,
    e identifique se ele mora em uma rua, avenida, travessa ou BR.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char endereco[20];
    int i = 0;

    printf("Informe seu endereco (ex: Rua Amarela, 150): "); // leitura do endereco
    fgets(endereco, 20, stdin);

    strlwr(endereco);

    if (endereco[i] == 'r' && endereco[i + 1] == 'u' && endereco[i + 2] == 'a')
    {
        printf("Local de endereco: Rua!\n");
    }
    else if (endereco[i] == 't' && endereco[i + 1] == 'r' && endereco[i + 2] == 'a')
    {
        printf("Local de endereco: Travessa!\n");
    }
    else if (endereco[i] == 'a' && endereco[i + 1] == 'v' && endereco[i + 2] == 'e')
    {
        printf("Local de endereco: Avenida!\n");
    }
    else if (endereco[i] == 'b' && endereco[i + 1] == 'r')
    {
        printf("Local de endereco: BR!\n");
    }
    else
    {
        printf("Local de endereco nao identificado!\n");
    }

    system("pause");
    return 0;
}