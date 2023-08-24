#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char string[30];
    char string2[30];
    char copia[30];

    strcpy(string, "String 1"); // Atribuicao de String
    printf(string);             // forma de saida 1
    strcpy(string2, "STRING 2");
    printf("\n\n%s", string2); // forma de saida 2

    strcat(string, string2);  // Concatenando Strings
    printf("\n\n%s", string); // O valor de string2 é anexado ao final de string1. Uma vez que o valor concatenado é realmente armazenado em string1, essa variável deve estar definida com o tamanho adequado para armazenar a string combinada.

    strcpy(copia, "String Copia");
    printf("\n\n%s", copia);
    strcpy(copia, string); // copiando uma string
    printf("\n\n%s", copia);

    int resultado;
    char letra1[2] = {'A'}, letra2[2] = {'a'};
    resultado = stricmp(&letra1, &letra2); // igual strcmp(), mas ignora maiusculas e minusculas
    printf("\n\nstricmp(&letra1, &letra2) == %d", resultado);

    strupr(string);  // string inteira para maiuscula
    strlwr(string2); // string inteira para minuscula
    printf("\n\n%s", string);
    printf("\n%s", string2);

    tolower(letra1[0]); // caractere em minusculas
    toupper(letra2[0]); // caractere em maiusculas
    printf("\n\nLetra1 em Minusculo: %c | Letra2 em Maiusculo: %c\n", letra1[0], letra2[0]);

    char string3[30];
    printf("\nInforme o nome: ");
    strupr(gets(string3)); // string para maiusculo
    printf("Nome em maiusculas: %s", string3);
    printf("\nNome em minusculas: %s", strlwr(string3)); // string para minusculo

    return 0;
}