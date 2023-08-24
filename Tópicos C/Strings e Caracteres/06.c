/* 6. Crie uma função que recebe uma string e um caractere, e retorne o número de vezes
que esse caractere aparece na string. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buscar(char nome[], char letra)
{
    int flag = 0;

    for (int i = 0; i < strlen(nome); i++)
    {
        if (tolower(nome[i]) == letra) // Passando todos os caracteres para minusculo
        {
            flag++; // o teste compara  se a letra é igual ao caractere no indice i
        }
    }

    if (flag > 0)
    {
        printf("\nSeu nome possui %d - %c.", flag, letra); // retorna se flag for maior que zero
    }
    else
    {
        printf("\nSeu nome nao possui a letra informada."); // retorna caso a flag fique em zero
    }
}

int main()
{
    char nome[30]; // String do nome
    char letra;    // Char da letra

    printf("Informe seu nome completo: ");
    fgets(nome, 30, stdin); // Lendo a String

    printf("Informe uma letra: ");
    scanf("%c", &letra); // Lendo a letra

    buscar(nome, letra); // Chamada para a funcao que ira buscar a letra na String

    return 0;
}