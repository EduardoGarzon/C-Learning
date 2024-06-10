/*
    Implemente um programa que receba um nome completo e
    apresente apenas o último nome e
    o 1º nome na seguinte forma: último, 1º nome
        Exemplo: Rafael Paes Oliveira
                 Saída: Oliveira, Rafael
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 100

void trocar(char nome[], char ultimo_nome[])
{
    int i = strlen(nome) - 1, x = 0; // indices

    while (x == 0)
    {
        i--;

        // varre o vetor a partir do final ate encontrar o primeiro espaco
        if (nome[i] == ' ')
        {
            // pula um indice para comecar a armazenar
            // a partir da primeira letra do ultimo nome
            i += 1;

            // a variavel vai receber o nome adiante ate encontrar o final do vetor
            while (nome[i] != '\n')
            {
                ultimo_nome[x] = nome[i];
                i++;
                x++;
            }

            // concatena uma virgula e um espaco para colocar
            // o primeiro nome posteriormente
            x++;

            strcat(ultimo_nome, ",");

            x++;

            strcat(ultimo_nome, " ");
        }
    }

    // varre o vetor nome desde o inicio ate encontrar o primeiro espaco
    for (i = 0; nome[i] != ' '; i++)
    {
        // o primeiro nome é armazenado no vetor que contem o ultimo nome
        ultimo_nome[x] = nome[i];
        x++;
    }

    printf(ultimo_nome); // escreve o ultimo nome, primeiro nome
}

int main()
{
    // string para o nome e strig final com ultimo nome e nome
    char nome[size], ultimo_nome[size];

    printf("Informe seu nome completo: ");
    fgets(nome, size, stdin); // leitura do nome completo

    trocar(nome, ultimo_nome); // chamada da funcao sem retorno que vai fazer a operacao

    system("pause");
    return 0;
}