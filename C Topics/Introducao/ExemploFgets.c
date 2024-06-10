#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nome[25];

    printf("Qual seu nome?: ");
    fgets(nome, 25, stdin);

    nome[strlen(nome) - 1] = '\0'; // Removendo o \n

    printf("Bem vindo: %s\n", nome);

    system("pause");
    return 0;
}