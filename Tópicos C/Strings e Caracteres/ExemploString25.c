/*
    Crie uma função que recebe uma string e um caractere,
    e retorne o número de vezes que esse caractere aparece na string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buscar(char nome[], char letra)
{
    int flag = 0;

    strlwr(nome);

    for (int i = 0; i < (int)strlen(nome); i++)
    {
        if (nome[i] == letra) // Passando todos os caracteres para minusculo
        {
            flag++; // o teste compara  se a letra é igual ao caractere no indice i
        }
    }

    if (flag > 0)
    {
        // retorna se flag for maior que zero
        printf("Seu nome possui %d %c\n", flag, letra);
    }
    else
    { // retorna caso a flag fique em zero
        printf("Seu nome nao possui a letra informada.\n");
    }
}

int main()
{
    char nome[100]; // String do nome
    char letra;     // Char da letra

    printf("Informe seu nome completo: ");
    gets(nome);

    printf("Informe uma letra: ");
    scanf("%c", &letra); // Lendo a letra
    getchar();

    buscar(nome, letra); // Chamada para a funcao que ira buscar a letra na String

    system("pause");
    return 0;
}