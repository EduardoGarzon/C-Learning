/*
    Utilizando string com puts e putchar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nome[50];

    printf("Informe seu nome: ");
    scanf("%[^\n]", nome); // ignora strings com o caractere especificado
    // fflush(stdin);

    puts(nome); // escreve a string inteira

    for (unsigned long long int i = 0; i < strlen(nome); i++)
    {
        putchar(nome[i]); // escreve a string caractere por caractere
    }
    printf("\n");

    system("pause");
    return 0;
}