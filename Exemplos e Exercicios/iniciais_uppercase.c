/* Criando uma funcao que coloca as iniciais de um nome informado em Maiusculo */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void maiusculo(char nome[])
{

    for (int i = 0; i < strlen(nome); i++)
    {
        if (nome[i] == ' ') // se no indice atual for um espaco o proximo caractere fica em uppercase
        {
            nome[i + 1] = toupper(nome[i + 1]);
        }
        if (i == 0) // se for o primeiro caractere ele fica em uppercase
        {
            nome[i] = toupper(nome[i]);
        }
    }
    printf("\n%s", nome); // escreve o nome
}

int main()
{
    char nome[50]; // string para o nome

    printf("Informe seu nome completo: "); // leitura do nome
    fgets(nome, 100, stdin);
    maiusculo(nome); // chamada da funcao que joga as iniciais do nome para maiusculo

    return 0;
}