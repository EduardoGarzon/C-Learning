#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nome[25];

    printf("Informe seu nome: ");
    fgets(nome, 25, stdin);

    nome[strlen(nome) - 1] = '\0';

    while (strlen(nome) == 0)
    {
        printf("\nVoce nao digitou nada!\n\n");

        printf("Informe seu nome: ");
        fgets(nome, 25, stdin);
    }

    printf("\nHello %s\n", nome);

    system("pause");
    return 0;
}