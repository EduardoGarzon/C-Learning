#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void happyBirthday(char nome, int idade)
{
    printf("Feliz Aniversario %s\n", nome);
    printf("Parabens pelos seus %d anos de vida!\n", idade);
}

int main()
{
    int idade;
    char nome[25];

    printf("Informe seu nome: ");
    fgets(nome, 25, stdin);

    nome[strlen(nome) - 1] = '\0';

    happyBirthday(nome, idade);

    system("pause");
    return 0;
}