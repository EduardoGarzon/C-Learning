/*
    Incrementando sobre os indices de uma String.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[30] = "Incrementando a String";

    printf("STRING ORIGINAL: %s\n", string);

    int i = 0;
    while (string[i] != '\0') // Enquanto nao chegar no fim da String
        i++;                  // Incrementa o indice
    string[i] = '!';          // Insere novo caractere no lugar
    string[i + 1] = '\0';     // Insere caracter \0 de final de string

    printf("STRING INCREMENTADA: %s\n", string);

    system("pause");
    return 0;
}