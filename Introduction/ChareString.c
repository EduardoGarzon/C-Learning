// Exemplo de string de caracteres

#include <stdio.h>

int main()
{
    char nome[10];    // String de caracteres
    char nomeb = 'A'; // variavel do tipo caractere, alocacao de 1 byte na memoria para um unico caractere

    printf("Informe seu nome: "); // entrada de dados para o nome
    scanf("%s", &nome);           // leitura do nome para a variavel do tipo string
    printf("\n");

    printf("Seu nome e : %s\n", nome);              // escrevendo o nome informado no vetor
    printf("Letra contida na variavel: %c", nomeb); // escrevendo a variavel do tipo caractere
}