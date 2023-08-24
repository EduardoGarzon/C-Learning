/*
A funcao scanf recebe o endereco de memoria onde deve salvar o que foi lido.
Uma string é um vetor de caracteres que ficar armazenada sequencialmente na memoria
(uma posicao apos a outra) independente do tipo.
O nome do vetor ja é um ponteiro para o inicio do vetor uma vez que suas posicoes sao sequenciais na memoria.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char palavra[100];

    printf("Digite algo: ");
    scanf("%100[^\n]", palavra);

    printf("Leitura: %s\n\n", palavra);

    printf("Endereco primeira posicao de palavra[100]: %p\n", palavra);
    printf("Endereco primeira posicao de palavra[100]: %p\n", &palavra);
    printf("Endereco primeira posicao de palavra[100]: %p\n", &palavra[0]);

    system("pause");
    return 0;
}