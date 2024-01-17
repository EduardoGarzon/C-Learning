/*
    Solicite ao usuário a digitação de uma palavra
    e verifique se ela é um palíndromo (ex.:ovo, osso).
    Palíndromo é uma palavra, frase ou número que
    permanece igual quando lida de trás para diante.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char palavra[20];

    printf("Informe uma palavra apenas: ");
    scanf(" %s", palavra);
    getchar();

    char copia[strlen(palavra) + 1];

    for (int i = strlen(palavra) - 1, j = 0; i >= 0; i--, j++)
    {
        copia[j] = palavra[i];
    }
    
    copia[strlen(palavra)] = '\0';

    if (strcmp(copia, palavra) == 0)
    {
        printf("A palavra e um palindromo!\n");
    }
    else
    {
        printf("A palavra nao e um palindromo!\n");
    }

    system("pause");
    return 0;
}