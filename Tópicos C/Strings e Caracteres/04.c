/* 4. Solicite ao usuário o seu endereço, e identifique se ele mora em uma rua, avenida,
travessa ou BR. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void minusculo(char endereco[]) // funcao que passa toda a string para minusculo
{
    int i = 0;
    while (endereco[i] != '\n')
    {
        endereco[i] = tolower(endereco[i]);
        i++;
    }
}

int main()
{
    char endereco[20];

    printf("Informe seu endereco (ex: Rua Amarela, 150): "); // leitura do endereco
    fgets(endereco, 20, stdin);

    minusculo(endereco); // funcao com parametro e sem retorno

    for (int i = 0; i < strlen(endereco); i++) // Testando a localizacao pelas iniciais
    {
        if (endereco[i] == 'r' && endereco[i + 1] == 'u' && endereco[i + 2] == 'a')
        {
            printf("\nLocal de endereco: Rua");
            break;
        }
        else if (endereco[i] == 't' && endereco[i + 1] == 'r' && endereco[i + 2] == 'a')
        {
            printf("\nLocal de endereco: Travessa");
            break;
        }
        else if (endereco[i] == 'a' && endereco[i + 1] == 'v' && endereco[i + 2] == 'e')
        {
            printf("\nLocal de endereco: Avenida");
            break;
        }
        else if (endereco[i] == 'b' && endereco[i + 1] == 'r')
        {
            printf("\nLocal de endereco: BR");
            break;
        }
        else
        {
            printf("\nLocal de endereco nao identificado");
            break;
        }
    }

    return 0;
}