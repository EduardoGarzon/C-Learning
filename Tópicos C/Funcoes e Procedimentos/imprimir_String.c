/*
criando uma funcao para imprimir caractere-caractere de uma string
*/

#include <stdio.h>

void imprimir_String(char nome[])
{
    int tamanho = 0;
    // alternativa: tamanho < strlen(nome)
    while (nome[tamanho] != '\0' && nome[tamanho] != '\n')
    {
        printf("%c", nome[tamanho]);
        tamanho++;
    }
}

int main()
{
    char nome[100];

    printf("Informe seu nome: ");
    fgets(nome, 100, stdin);
    imprimir_String(nome);

    return 0;
}