/*
    strchr: retorna o endereço (um ponteiro) para a primeira ocorrência
    do caractere x na string str, ou NULL se não encontrar.

    strrchr: retorna o endereço (um ponteiro) para a última ocorrência do caractere.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[100] = "Luiz Eduardo Garzon";
    char letra;

    printf("Informe a letra que deseja encontrar: ");
    scanf(" %c", &letra);
    getchar();

    printf("\n");
    printf("Utilizando for para encontrar um caractere:\n");
    for (unsigned long long int i = 0; i < strlen(string); i++)
    {
        if (string[i] == letra)
        {
            printf("Letra Encontrada!\n");
            printf("Retorno: %c\n", string[i]);
            printf("Indice: %lld\n", i);
            printf("Endereco: %p\n", &string[i]);
            break;
        }
    }
    printf("\n");

    printf("Utilizando strchr - primeira ocorrencia do caractere:\n");
    char *end = strchr(string, 'z');
    printf("Caractere Retornado: %c\n", (*end));

    // diferenca entre o endereco do elemento e o endereco inicial da string
    int indice = end - string;
    printf("Indice: %d\n", indice);
    printf("Endereco: %p\n", end);

    printf("\n");

    printf("Utilizando strrchr - ultima ocorrencia do caractere:\n");
    char *end2 = strrchr(string, 'z');

    // diferenca entre o endereco do elemento e o endereco inicial da string
    int indice = end - string;
    printf("Indice: %d\n", indice);
    printf("Caractere Retornado: %c\n", (*end2));
    printf("Endereco: %p\n", end2);

    system("pause");
    return 0;
}