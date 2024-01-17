/*
    Implemente a função ultimo_nome que recebe como parâmetro
    uma cadeia de caracteres com o nome completo de uma pessoa
    e retorna o último nome encontrado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ultimo_nome(char nome[], char sobrenome[])
{
    int i, x, y = 0; // indices

    for (i = 0; i < (int)strlen(nome); i++) // leitura da string
    {
        if (nome[i + 1] == '\n') // encontra o final da string
        {
            x = i; // x recebe o i que esta antes da ultima posicao

            while (nome[x] != ' ') // retrocede ate encontra o primeiro espaco
            {
                sobrenome[y] = nome[x]; // string sobrenome recebe caracter a caracter
                x--;
                y++;
            }
        }
    }

    for (i = strlen(sobrenome); i >= 0; i--)
    {
        printf("%c", sobrenome[i]); // escreve a string da frente para tras
    }

    printf("\n");
}

int main()
{
    char nome[30];      // String para o nome
    char sobrenome[30]; // String para o ultimo nome

    printf("Informe seu nome completo: ");
    fgets(nome, 30, stdin); // Leitura do nome

    printf("Ultimo nome detectado: ");
    ultimo_nome(nome, sobrenome); // Chamada da funcao para detectar o ultimo nome

    system("pause");
    return 0;
}