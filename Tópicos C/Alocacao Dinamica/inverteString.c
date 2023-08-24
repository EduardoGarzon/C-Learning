/*
    Codigo para inverter uma string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverterA(char s[])
{
    int i, tamanho = strlen(s);
    int fim = tamanho - 1; // indice do ultimo caractere
    char aux;
    for (int i = 0; i < (tamanho / 2); i++)
    {
        aux = s[i];
        s[i] = s[fim];
        s[fim] = aux;
        fim--;
    }
}

char *inverterB(char s[])
{

    int i, aux, fim, tam = strlen(s);
    char *novo = malloc((tam + 1) * sizeof(char));

    fim = tam - 1; // índice do último caracter
    for (i = 0; i < tam; i++)
    {
        novo[fim] = s[i];
        fim--;
    }
    novo[i] = '\0'; // finaliza a nova string
    return novo;
}

int main()
{
    char string[20];

    scanf("%s[^\n]", string);

    inverterA(string);
    printf("Inverte A: %s\n\n", string);

    scanf("%s[^\n]", string);

    char *string2;
    string2 = inverterB(string);
    printf("Inverte B: %s\n\n", string2);

    return 0;
}