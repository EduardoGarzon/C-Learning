/*
    Solicite ao usuário que informe uma palavra.
    O programa deve informar a existência de uma letra dentro desta palavra.
    A letra que será procurada é informada pelo usuário também.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char palavra[20];
    char letra;

    printf("Informe uma palavra: ");
    scanf("%s", palavra);
    getchar();

    printf("Informe uma letra: ");
    scanf("%c", &letra);
    getchar();

    unsigned long int i = 0;
    for (; i < strlen(palavra); i++)
    {
        if (letra == palavra[i])
        {
            printf("Letra encontrada na string!\n");
            break;
        }
    }

    if (i >= strlen(palavra))
    {
        printf("Letra nao encontrada na string!\n");
    }

    system("pause");
    return 0;
}