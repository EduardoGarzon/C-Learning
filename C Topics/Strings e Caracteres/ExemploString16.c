/*
    String e Char para Maiucula e Minuscula.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    // STRING
    char stringA[] = {"LuIz EdUaRdO"};

    printf("String Original: %s\n", stringA);

    strupr(stringA); // string inteira para maiuscula
    printf("String Maiuscula: %s\n", stringA);

    strlwr(stringA); // string inteira para minuscula
    printf("String Minuscula: %s\n", stringA);

    // CHAR
    char letraA = 'a';

    printf("\n\n");
    printf("Char Original: %c\n", letraA);

    letraA = toupper(letraA); // caractere em maiuscula
    printf("Char Maiusculo: %c\n", letraA);

    letraA = tolower(letraA); // caractere em minuscula
    printf("Char Minusculo: %c\n", letraA);

    // STRING DE ENTRADA
    char string[10];

    printf("\n\n");
    printf("Informe o nome: ");
    strupr(gets(string));                   // string de entrada para maiusculo
    
    printf("Nome Maiusculo: %s\n", string); // gets faz a leitura ate encontrar um \n

    system("pause");
    return 0;
}