// Testando funcoes da biblioteca string.h

#include <stdio.h>
#include <string.h>

int main()
{
    char nome[20];
    char copia[20];
    char diferente[20] = "Vetor diferente";

    printf("Informe seu nome: ");
    scanf("%s", nome);

    strcat(nome, "@gmail.com"); // funcao que concatena palavras
    printf("\nSeu email de acesso: %s", nome);

    strcpy(copia, nome); // funcao que copia os caracteres do vetor
    printf("\nVetor copia: %s", copia);

    printf("\nComprimento do vetor: %d caracteres", strlen(nome)); // funcao que mostra o comprimento de caracteres presentes no vetor

    // strcpy(diferente, nome); // teste para igualar os vetores
    if (!strcmp(nome, diferente)) // o sinal ! (negacao) faz comparar a igualdade agora, e nao a diferenca
    {
        printf("\nOs vetores sao iguais!");
    }
    else
    {
        printf("\nOs vetores sao diferentes!");
    }
}