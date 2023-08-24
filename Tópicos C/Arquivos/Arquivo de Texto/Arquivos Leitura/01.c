/*
1. Considere o arquivo “idade.txt”, crie um programa que realize a leitura
das informações contidas no mesmo e apresente a média das idades
informadas.
*/
#include <stdio.h>
int main()
{
    int valor = 0, media = 0, cont = 0;
    FILE *arquivo;
    arquivo = fopen("idade.txt", "r"); // abertura do arquivo
    if (arquivo == NULL)               // teste da abertura do arquivo
    {
        printf("Erro na abertura do arquivo.\n");
    }
    while (!feof(arquivo)) // enquanto nao chegar no fim do arquivo
    {
        cont++;                        // contador para total de idades
        fscanf(arquivo, "%d", &valor); // le o arquivo
        media += valor;                // soma as idades encontradas
        fflush(stdin);
        printf("Idade: %d\n", valor);
    }
    media = media / cont; // calculo da media
    printf("Media das idades do arquivo: %d\n", media);
    fclose(arquivo);
    return 0;
}