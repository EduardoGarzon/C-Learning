/*
    Funcao strcpy copia o elemento de uma string B para uma string A.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char stringA[30];
    char stringB[30];

    strcpy(stringA, "String(A)\n"); // Atribuicao da stringA
    printf("String A: ");
    printf(stringA);

    strcpy(stringB, "String(B)\n"); // Atribuicao da StringB
    printf("String B: ");
    printf("%s", stringB);

    printf("String B copiada para String A: ");
    strcpy(stringA, stringB); // Copiando stringB para stringA
    printf("%s", stringA);

    system("pause");
    return 0;
}