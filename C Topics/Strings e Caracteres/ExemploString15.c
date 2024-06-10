/*
    Converter uma string qualquer para maiusculo ou minusculo em C.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // toupper() and tolower()

void string_Maiusculo(char str1[], char str2[])
{
    int tamanho = 0;
    while (str1[tamanho] != '\0' && str1[tamanho] != '\n')
    {
        str2[tamanho] = toupper(str1[tamanho]);
        tamanho++;
    }
    str2[tamanho] = '\0';
}

void string_Minusculo(char str1[], char str2[])
{
    int tamanho = 0;
    while (str1[tamanho] != '\0' && str1[tamanho] != '\n')
    {
        str2[tamanho] = tolower(str1[tamanho]);
        tamanho++;
    }
    str2[tamanho] = '\0';
}

int main()
{
    char str1[100]; // string original
    char str2[100]; // string minuscula ou maiuscula

    printf("Informe a string: ");
    fgets(str1, 100, stdin); // leitura string original
    fflush(stdin);

    string_Maiusculo(str1, str2); // string to upper
    printf("String em MAIUSCULO: %s\n", str2);

    printf("\n");

    string_Minusculo(str1, str2); // string to lower
    printf("String em MINUSCULO: %s\n", str2);

    system("pause");
    return 0;
}