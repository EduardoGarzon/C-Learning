/* 5. Solicite ao usuário a digitação de uma palavra e verifique se ela é um palíndromo (ex.:
ovo, osso). Palíndromo é uma palavra, frase ou número que permanece igual quando lida de trás para diante. */

#include <stdio.h>
#include <string.h>

void comparar(char palavra[], char copia[]) // funcao secundaria para comparacao de strings
{
    int i = 0, x = strlen(palavra) - 2;
    int flag = 0;
    strcpy(copia, palavra); // string copia recebe a string palavra

    for (i = 0; i < strlen(palavra) - 1; i++)
    {
        if (palavra[i] == copia[x])
        {
            flag++;
            x--;
        }
    }
    if (flag == strlen(palavra) - 1)
    {
        printf("A palavra e um Palindromo");
    }
    else
    {
        printf("A palavra nao e um Palindromo");
    }
}

int main()
{
    char palavra[10];
    char copia[10]; // vetor para comparacao

    printf("Informe uma palavra apenas: ");
    fgets(palavra, 10, stdin);

    comparar(palavra, copia); // funcao com paramentro e sem retorno

    return 0;
}