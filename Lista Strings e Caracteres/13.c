/* 13. Leia duas strings. Se as strings forem iguais escreva “strings iguais”. Caso contrário,
concatene as duas strings e imprima a string resultante. */

#include <stdio.h>
#include <string.h>

int main()
{
    char texto[50];      // string do texto
    char comparador[25]; // string para o outro texto que ira ser comparado com o primeiro

    printf("Digite algo [Limite de 50 caracteres]: ");
    gets(texto);

    printf("Digite algo novamente: [Limite de 50 caracteres]: ");
    gets(comparador);

    if (strlen(texto) <= 50 && strlen(comparador) <= 50) // teste para limitar a quantidade de caracteres
    {
        if (strcmp(texto, comparador)) // funcao que compara as duas strings
        {
            printf("\nAs strings sao difentes: "); // sao diferentes se o retorno for maio ou menor que zero
            strcat(texto, " ");
            strcat(texto, comparador); // funcao que concatena as duas strings
            printf("\n%s", texto);     // retornar os dois textos concatenados
        }
        else
        {
            printf("\nAs strings sao iguais."); // se o retorno for = 0 entao as strings sao iguais
        }
    }
    else
    {
        printf("\nVoce excedeu o limite de 50 caracteres, escreva novamente");
    }
}