/*
    Faça um programa que receba do usuário
    o tamanho de uma string e chame uma função para alocar dinamicamente essa string.
    Em seguida, o usuário deverá informar o conteúdo dessa string.
    O programa deve imprimir a string sem suas vogais.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// funcao secundaria que aloca a string por referencia do ponteiro
int alocar(int tamanho, char *string)
{
    string = malloc(tamanho * sizeof(char));
}

int main()
{
    unsigned int tamanho; // variavel para o tamanho da alocacao
    char *string;         // variavel do tipo ponteiro para alocacao

    printf("Informe o tamanho da string: ");
    scanf("%d", &tamanho); // lendo o tamanho
    fflush(stdin);

    alocar(tamanho, &string); // alocando por funcao secundaria a string

    printf("Informe use nome: ");
    fgets(string, tamanho, stdin); // lendo o nome na string alocada
    fflush(stdin);

    printf("\n");
    printf("Seu nome sem vogais:\n");
    for (int i = 0; string[i] != '\n'; i++)
    {
        if (string[i] != 'a' && string[i] != 'e' && string[i] != 'i' && string[i] != 'o' && string[i] != 'u' && string[i] != 'A' && string[i] != 'E' && string[i] != 'I' && string[i] != 'O' && string[i] != 'U')
        {
            putchar(string[i]); // escrevendo a string sem vogais
        }
    }

    free(string); // desalocacao

    system("pause");
    return 0;
}