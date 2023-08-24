/* Teste com string
A leitura de uma string deve ser feita para uma variável com espaço suficiente para recebê-la, para não gerar um estouro de buffer (buffer overflow).
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char nome[50];
    int i = 0;

    printf("Informe seu nome: ");
    scanf("%[^\n]", nome); // scanf("%[^caractere]", nome);, le strings com o caractere especificado
    fflush(stdin);

    puts(nome); // escreve a string

    for (i = 0; i < strlen(nome); i++)
    {
        putchar(nome[i]); // escreve a string caractere por caractere
    }

    /* char * strncpy (dest, src, n) - Copia ''n'' caracteres da string de origem (''src'') para o local indicado como destino (''dest'').*/
    char teste[12] = "XXXXX";
    strncpy(nome, teste, 5);
    printf("\n%s", nome);

    /* Compara as duas strings indicadas, idem, mas só considera os ''n'' primeiros caracteres.
    int strncmp (str1, str2 ,n) */
    int resultado = strncmp(nome, "xxxxxx", 5);
    printf("\nResultado de strncmp(nome, teste, 5) == %d\n", resultado);

    /* char * strncat (strto, strfrom, n), só concatena os ''n'' primeiros caracteres. */
    strncat(nome, "funcionou", 4);
    puts(nome);

    /* Retorna o endereço (um ponteiro) para a primeira ocorrência do caractere ''c'' na string ''str'', ou NULL se não encontrar. char * strchr (str, c) */
    /* char * strrchr (str, c) - retorna o endereço (um ponteiro) para a última ocorrência do caractere */

    return 0;
}