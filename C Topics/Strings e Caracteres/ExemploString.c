/*
    Exemplo de string.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[10];    // String, Vetor de Caracteres
    char nomeb = 'A'; // Variavel do tipo caractere
                      // 1 byte na memoria para um unico caractere

    printf("Informe seu nome: "); // entrada de dados para o nome
    scanf("%s", nome);            // leitura do nome para a variavel do tipo string
    // nao é necessario o & pois uma string ja possui um ponteiro
    // que contem o endereco do primeiro caractere do vetor de caracteres

    printf("\n");
    printf("Seu nome e : %s\n", nome);              // escrevendo o nome informado no vetor
    printf("Letra contida na variavel: %c", nomeb); // variavel do tipo caractere

    system("pause");
    return 0;
}