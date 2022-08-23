/*
'x' é o CARACTER x, enquanto que "x" é o STRING x. Quando escrevemos "x" o compilador, na verdade, cria um vetor com 2 caracteres: 'x' e '\0'.

gets(), definida também em stdio.h, lê até um "enter", ou seja, até um '\n', é perigosa porque não checa o limite do string.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char nome[10] = "Luiz Eduardo";  // declaracao com alocacao de memoria manual
    char nome2[] = "Luiz Eduardo";   // declaracao com alocacao de memoria automatica
    printf("Escrevendo string sem declarar: %s\n", "String nao declarada"); // string sem declaracao

    char string[30] = "Incrementando a String"; // incrementando a string
    printf("\n%s", string);
    int i = 0;
    while(string[i] != '\0') i++; // achando a ultima posicao, fim da string
    string[i] = '!';              // inserindo novo caractere no lugar
    string[i+1] = '\0';           // inserindo o fim da string no proximo indice
    printf("\n%s", string);

    char a = 'a', b = 'A';
    printf("\n%c = %d", a, 'a'); // valor da tabelas ASCII
    printf("\n%c = %d", b, 'A');
    printf("\nNumero de caracteres da string: %d - %s", strlen("String Teste"), "String Teste");
    // strlen retorna o número de caracteres de um string (sem contar o '\0')
    return 0;
}