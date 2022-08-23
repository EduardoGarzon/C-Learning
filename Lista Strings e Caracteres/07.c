/* 7. Escreva um subprograma que receba um texto e devolva o mesmo texto com todas as
suas letras duplicadas. Exemplo:
texto recebido:
INSTITUTO DE INFORMATICA
texto devolvido:
IINNSSTTIITTUUTTOO DDEE IINNFFOORRMMAATTIICCAA
*/

#include <stdio.h>
#include <string.h>

void duplicar(char texto[], char copia[])
{
    int x = 0;

    for (int i = 0; i < strlen(texto); i++)
    {
        copia[x] = texto[i]; // posicao recebe a letra
        x++;
        copia[x] = texto[i]; // a proxima posicao tambem recebe a mesma letra
        x++;
    }

    printf("\nString com suas letras duplicadas:\n");
    printf("%s", copia); // retorna a String copia contendo os resultados
}

int main()
{
    char texto[100]; // String para o texto
    char copia[200]; // String que recebe os valores duplicados

    printf("Informe uma frase ou palavra: [limite - 100 caracteres]: \n");
    fgets(texto, 100, stdin); // leitura da String texto

    duplicar(texto, copia); // chamda da funcao que vai duplicar cada elemento da String

    return 0;
}