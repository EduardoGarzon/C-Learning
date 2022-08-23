/*
4. Faça um programa que leia o arquivo “linhas.txt” e mostre na tela
quantas linhas esse arquivo possui.
*/

#include <stdio.h>

int main()
{
    int cont = 0;
    FILE *arquivo;
    arquivo = fopen("linhas.txt", "r"); // abertura do arquivo
    if (arquivo == NULL)                // testando abertura do arquivo
    {
        printf("Erro na abertura do arquivo.\n");
    }
    while (!feof(arquivo)) // enquanto nao chegar no fim do arquivo
    {
        if (fgetc(arquivo) == '\n') // procura a quebra de linha
        {
            cont++;
        }
    }
    printf("Quantidade de linhas do arquivo: %d\n", cont + 1);
    fclose(arquivo);
    return 0;
}