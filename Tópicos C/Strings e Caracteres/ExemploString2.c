/*
    Utilizando Malloc e Calloc para alocar ponteiro de char
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Malloc
    char *string = (char *)malloc(sizeof(char));

    printf("String Alocada com Malloc: %s | Tamanho: %lld\n", string, strlen(string));

    string = "Luiz Eduardo Garzon";
    printf("String Atribuida: %s | Tamanho: %lld\n", string, strlen(string));

    string = "Eduarda Kalschne";
    printf("Nova atribuicao: ");
    for (unsigned long long int i = 0; i < strlen(string); i++)
    {
        printf("%c", string[i]);
    }
    printf("\n\n");

    // Calloc
    char *string2 = (char *)calloc(sizeof(char), 10);

    printf("String Alocada com Calloc: %s | Tamanho: %lld\n", string2, strlen(string2));

    string2 = "Luiz Eduardo Garzon";
    printf("String Atribuida: %s | Tamanho: %lld\n", string2, strlen(string2));

    string2 = "Eduarda Kalschne";
    printf("Nova atribuicao: ");
    for (unsigned long long int i = 0; i < strlen(string2); i++)
    {
        printf("%c", string2[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}