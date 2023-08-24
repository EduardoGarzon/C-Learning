/*
Implementado funcao para copiar string utilizando Aritmetica de Ponteiros.
*/

#include <stdio.h>
#include <stdlib.h>

int strcpy_Fake(char *destino, char *origem)
{
    int i = 0;
    while (*(origem + i) != '\0') // enquanto nao chegar ao fim da string original
    {
        *(destino + i) = *(origem + i); // copia caractere por caractere
        i++;
    }
    *(destino + i) = '\0'; // adiciona o caractere de fim destring

    return i;
}

int main()
{
    char destino[25];
    char origem[25] = {"Luiz Eduardo"};

    // retorna o tamanho da string copiada
    // Passando a primeira possicao de cada string
    int tamanho = strcpy_Fake(destino, origem);

    printf("Tamanho da String copiada: %d\n", tamanho);
    printf("String original: %s\n", origem);
    printf("String copiada: %s\n", destino);

    system("pause");
    return 0;
}