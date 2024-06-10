/*
    Leia duas strings.
    Se as strings forem iguais escreva “strings iguais”.
    Caso contrário, concatene as duas strings e imprima a string resultante.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char texto[50];      // string do texto
    char comparador[50]; // string para o outro texto que ira ser comparado com o primeiro

    printf("Digite algo [Limite de 50 caracteres]: ");
    gets(texto);
    getchar();

    printf("Digite algo novamente: [Limite de 50 caracteres]: ");
    gets(comparador);
    getchar();

    // teste para limitar a quantidade de caracteres
    if (strlen(texto) <= 50 && strlen(comparador) <= 50)
    {
        if (strcmp(texto, comparador)) // funcao que compara as duas strings
        {
            // sao diferentes se o retorno for maior ou menor que zero
            printf("As strings sao difentes:\n");

            strcat(texto, " ");
            strcat(texto, comparador); // funcao que concatena as duas strings

            printf("%s\n", texto); // retornar os dois textos concatenados
        }
        else
        {
            // se o retorno for = 0 entao as strings sao iguais
            printf("As strings sao iguais.\n");
        }
    }
    else
    {
        printf("Voce excedeu o limite de 50 caracteres, escreva novamente.\n");
    }

    system("pause");
    return 0;
}