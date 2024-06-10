/*
    Escreva um subprograma que receba um texto e
    devolva o mesmo texto com todas as suas letras duplicadas.

    Exemplo:
        Texto Recebido:
            INSTITUTO DE INFORMATICA
        Texto Devolvido:
            IINNSSTTIITTUUTTOO DDEE IINNFFOORRMMAATTIICCAA
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void duplicar(char texto[], char copia[])
{
    int x = 0;

    for (int i = 0; i < (int)strlen(texto); i++)
    {
        copia[x] = texto[i]; // posicao recebe a letra
        x++;
        copia[x] = texto[i]; // a proxima posicao tambem recebe a mesma letra
        x++;
    }
    copia[(strlen(texto) * 2)] = '\0';

    printf("String com suas letras duplicadas: %s\n", copia);
    getchar();
}

int main()
{
    char texto[100]; // String para o texto

    printf("Informe uma frase ou palavra: [limite - 100 caracteres]: ");
    gets(texto);

    char copia[(strlen(texto) * 2) + 1];

    duplicar(texto, copia); // chamda da funcao que vai duplicar cada elemento da String

    system("pause");
    return 0;
}