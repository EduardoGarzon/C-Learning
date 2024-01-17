/*
    Funcao strcat 'e utilizada para concatenar strings.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char stringA[10] = {"Luiz "};
    char stringB[10] = {"Eduardo"};
    char stringC[30];

    printf("String A: %s\n", stringA);
    printf("String B: %s\n", stringB);

    // stringC deve ter tamanho suficiente para conter a duas strings de tamanho 10
    strcat(stringC, stringA); // Concatenando stringA na stringC
    strcat(stringC, stringB); // Concatenando stringB na stringC
    strcat(stringC, "\n\0");  // Concatenando \n e fim da string na stringC

    printf("Strings Concatenadas: %s", stringC);

    system("pause");
    return 0;
}